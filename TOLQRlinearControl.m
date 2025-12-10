function u = TOLQRlinearControl(t,x,c)

    % Initialize u
    u = 0;
    
    

    % Determine most recent knot point
    index = find(c.t_k > t, 1)-1;
    if t >= c.t_k(end)
        index = length(c.t_k);
        next = index;
        interp = 0;
    else
        next = index + 1;
        interp = (t-c.t_k(index))/(c.t_k(next)-c.t_k(index));
    end
    
    
    




    % Interpolate trajectory reference state
    x_star = c.x_star(:,index)*(1-interp) ... 
        + c.x_star(:,next)*interp;

    % Interpolate trajectory reference input
    u_star = c.u_star(index)*(1-interp)+ ...
        +c.u_star(next)*interp;
    
    % conds = c.conds;
    % if (conds(index) > 1e9) | (conds(next) > 1e9)
    %     u(1) = u_star;
    %     return
    % end
    % Pick K linearized around knot point
    K = c.K(:,:,index)*(1-interp)...
         + interp*c.K(:,:,next);

    
    % Calculate input so system converges to trajectory
    u(1) = u_star - K*(x-x_star);

end
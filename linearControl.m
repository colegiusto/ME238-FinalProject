function u = linearControl(t,x,c)
    u = 0;
    bounds = c.bounds;
    x = reshape(x, [4,1]);
    if ~isfield(c, 't_k')
        
        K = c.K;
        if (x(1) <= bounds(1,1)) || (x(1) >= bounds(2,1))
            u = 0;
            return
        end
        if (x(2) <= bounds(1,2)) || (x(2) >= bounds(2,2))
            u = 0;
            return
        end
        u = -K * (x-c.x_star);
        return
    end
    
    index = find(c.t_k > t, 1)-1;
    if t >= c.t_k(end)
        interp = 0;
        index = length(c.t_k);
        next = index;
    else
        next = index+1;
        interp = (t - c.t_k(index))/(c.t_k(next)-c.t_k(index));
        
    end
    
    x_star = (1-interp)*c.x_star(:, index) + interp * c.x_star(:, next);
    u_star = (1-interp)*c.u_star(index) + interp * c.u_star(next);
    
    K = (1-interp)*c.K(:, :, index) + interp * c.K(:, :, next);

    e = x-x_star;
    
    if (e(1) <= bounds(1,1)) || (e(1) >= bounds(1,2))
        u = 0;
        return
    end
    if (e(2) <= bounds(2,1)) || (e(2) >= bounds(2,2))
        u = 0;
        return
    end
    
    u(1) = u_star;
    
    
    
end
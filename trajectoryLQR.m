function c = trajectoryLQR(t, u,state,Q,R, lqrScale, kalmanScale, conditionLimit, p)
    
    J = @(x,h,F)(F(repmat(x,size(x'))+diag(h))-F(repmat(x,size(x'))))./h';

    c.t_k = t;
    c.u_star = u;
    c.x_star = state;
    
    c.K = zeros(1,4,length(t));
    
    c.conds = zeros(length(t),1);

    for i = 1:length(t)
        A = J(c.x_star(:,i), 1e-5*ones(4,1), @(x)dynamics(x, u(i), p));
    
        B = J(u(i), 1e-5, @(u)dynamics(c.x_star(:,i), u, p));
        sys = c2d(ss(A,B,eye(2,4), 0), 0.001);
        
        [dA, dB, dC, ~] = ssdata(sys);
    
        K_dlqr = dlqr(dA, dB, Q, R);
    
        poles = eig(dA-dB*K_dlqr)*lqrScale;
        [K_placed, ~] = place(dA, dB, poles);
    
        c.K(:,:, i) = K_placed;
    
        c.conds(i) = cond(ctrb(dA,dB));
        if c.conds(i) > conditionLimit
            c.K(:,:,i) = K_placed*0;
        end
    
    end
    c.B = zeros(4,5,length(t));


    for i = 1:length(t)
        A = J(c.x_star(:,i), 1e-5*ones(4,1), @(x)dynamics(x, u(i), p));
        B = J(u(i), 1e-5, @(u)dynamics(c.x_star(:,i), u, p));
    
        sys = c2d(ss(A,B,eye(4,4), 0), 0.001);
    
        [dA, dB, dC, ~] = ssdata(sys);
    
        BB = B;
        
        QN = 1;
        RN = eye(4)*1e1;
        
        kalsys = ss(A, [B BB], dC, 0);
    
        [~, L, ~] = kalmd(kalsys, QN, RN, 0.001);
        
        poles_old = eig(dA'-dC'*L');
        
        poles_new = poles_old * kalmanScale;
    
        
        [L_placed, ~] = place(dA', dC', poles_new);
        
        L_placed = L_placed';
        
        c.A(:,:,i) = dA - L_placed*dC;
        c.B(:,:,i) = [dB L_placed];


    end
end


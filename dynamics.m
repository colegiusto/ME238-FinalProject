function dx = dynamics(x,u,p)
% dx = dynamics(x,u,p)
%
% Computes the dynamics for the pendubot
%

g = p.g;
T1 = p.T1;
T2 = p.T2;
T3 = p.T3;
T4 = p.T4;
T5 = p.T5;


q1 = x(1,:);
q2 = x(2, :);
dq1 = x(3,:);
dq2 = x(4, :);



[d11, d22, d12, d21, h1, h2, phi1, phi2] = spongParam(T1, T2, T3, T4, T5, q1, q2, dq1, dq2, g);


ddq1 = (d12.*(h2+phi2)-d22.*(h1+phi1-u))./(d11.*d22-d12.*d21);
ddq2 = (d21.*(h1+phi1-u)-d11.*(h2+phi2))./(d11.*d22-d12.*d21);

dx = [dq1; dq2; ddq1; ddq2];

end
function [d11, d22, d12, d21, h1, h2, p1, p2] = spongParam(T1, T2, T3, T4, T5, q1, q2, dq1, dq2, g)
    d11 = T1 + T2 + 2.*T3.*cos(q2);
    d22 = T2;
    d12 = T2 + T3.*cos(q2);
    d21 = d12;
    h1 = -T3 .* sin(q2) .* dq2.^2 - 2.*T3.*sin(q2) .* dq2 .* dq1;
    h2 = T3 .* sin(q2) .* dq1.^2;
    p1 = T4 .* g .* cos(q1) + T5 .* g .* cos(q1 + q2);
    p2 = T5 .* g .* cos(q1 + q2);
end


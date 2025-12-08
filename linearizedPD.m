function u = linearizedPD(x,x_ref, p, kp, kd)
    [d11, d22, d12, d21, h1, h2, phi1, phi2] = spongParam(p.T1, p.T2, p.T3, p.T4, p.T5, x(1), x(2), x(3), x(4), p.g);

    hbar = h1 - d12 * h2 / d22;
    phibar = phi1 - d12 * phi2 / d22;
    d1bar = d11 - d12 * d21 / d22;

    pd = kp*(x(1)-x_ref(1))+kd*(x(3)-x_ref(3));
    
    u = hbar + phibar - d1bar*pd;
end


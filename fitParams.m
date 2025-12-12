clear

load step.mat

%%


output = pendPos;
output.time = output.time(1:end, :);
output.signals.values = output.signals.values(1:end, :);

ap.l1 = 1;
ap.l2 = 1.5;
figure(1)
for i = 1:50:length(output.time)
    clf; hold on;
    ap.color = [1.0 0 0];
    animate(output.time(i), output.signals.values(i,:), ap)

    drawnow; pause(0.01); 
end

%%
p.g = 9.8;

p.T1 = 0.0148;
p.T2 = 0.0051;
p.T3 = 0.0046;
p.T4 = 0.1003;
p.T5 = 0.0303;



%%

W = @(x)[0.5*x(3)^2 0.5*x(4)^2 cos(x(1)-x(2))*x(3)*x(4) -p.g*cos(x(1)) -p.g*cos(x(2))];
xs = zeros(length(output.time),4);
xs(:, 1:2) = output.signals.values;
xs(1:end-1, 3:4) = lowpass(diff(output.signals.values)/0.001, 0.1, 1000);

%%


ws = zeros(5,length(output.time)-1);


u_interp = interp1(t_control, ut, output.time);

Ps = (xs(2:end, 3)+xs(1:end-1, 3))/2.*u_interp(1:end-1);
dEs = Ps.*0.001;

for i= 1:length(output.time)-1-N_end

    ws(:,i) = W(xs(i,:));

end
% dWs = diff(ws,1,2);


iEs = cumsum(dEs, 2);


T =  w_sum'\iEs;

p.T1 = T(1);
p.T2 = T(2);
p.T3 = T(3);
p.T4 = T(4);
p.T5 = T(5);


%%


x0 = [-pi/2; 0; 0; 0];

sol = ode45(@(t,x)dynamics(x, (t>1)*0.6, p), [0, 10],x0 );

figure(1); clf
subplot(2,1,1)
plot(sol.x, sol.y(1,:));
hold on
plot(output.time, output.signals.values(:,1))
subplot(2,1,2)
plot(sol.x, sol.y(2,:));
hold on
plot(output.time, output.signals.values(:,2))
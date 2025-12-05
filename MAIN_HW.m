clear;
J = @(x,h,F)(F(repmat(x,size(x'))+diag(h))-F(repmat(x,size(x'))))./h';
load guess.mat 

%% Test Open Loop
x0 = [-pi/2+0.3; 0; 0; 0];

t_control = linspace(0,10,100);
ut = (t_control>=1)*0.2;

%%
model = 'OpenLoopHW';

set_param(model, 'SimulationMode', 'external')
set_param(model, 'SimulationCommand', 'connect')
pause(1)
set_param(model, 'SimulationCommand', 'start')
pause(11)


%% animate result

output = pendPos;
output.signals.values(1,:) = output.signals.values(1,:) - pi/2;
ap.l1 = 1;
ap.l2 = 1.5;
for i = 1:50:length(output.time)
    clf; hold on;
    animate(output.time(i), output.signals.values(i,:), ap)

    drawnow;
end

% 



%% Stabilize Downward

%lqr
clear c
c.bounds = [-pi/3 pi/3; -pi/3 pi/3];

offset = 0.6;

c.x_star = [-pi/2+offset; -offset; 0; 0];



B = J(0, 1e-7, @(u)dynamics(c.x_star, u, p));

c.u_star = -B \dynamics(c.x_star, 0, p);

A = J(c.x_star, 1e-7*ones(1,4), @(x)dynamics(x,c.u_star,p));

Q = diag([1 10 1 10]);
R = 1e-6;

sys = c2d(ss(A,B,eye(2,4), 0), 0.001);

c.K = lqr(sys, Q, R);

%lqg

[dA, dB, dC, dD] = ssdata(sys);

BB = B;
QN = 1;
RN = eye(2)*20;

kalsys = ss(A, [B BB], dC, 0);

[est, L, P] = kalman(kalsys, QN, RN);

est = c2d(est, 0.001);
est_param.A = est.A;
est_param.B = est.B;

%%
model = 'ClosedLoopHW';
set_param(model, 'Dirty', 'on')
rtwbuild(model)

set_param(model, 'SimulationMode', 'external')
set_param(model, 'SimulationCommand', 'connect')
pause(1)
set_param(model, 'SimulationCommand', 'start')
pause(11)

%% animate result

output = pendPos;
ap.l1 = 1;
ap.l2 = 1.5;
figure(1)
for i = 1:50:length(output.time)
    clf; hold on;
    animate(output.time(i), output.signals.values(i,:), ap)

    drawnow; pause(0.05); 
end

%% plot
output = pendPos;

figure(2)
subplot(2,1,1)
plot(output.time, output.signals.values(:,1), output.time, output.signals.values(:,2))
hold on
plot(pendEst.time, pendEst.signals.values(:,1),pendEst.time,pendEst.signals.values(:,2))
legend("Encoder q1", "Encoder q2", "Kalman q1", "Kalman q2")
subplot(2,1,2)
plot(output.time(1:end-1)+diff(output.time), diff(output.signals.values(:,1))/0.001, output.time(1:end-1)+diff(output.time), diff(output.signals.values(:,2))/0.001)
hold on
plot(pendEst.time, pendEst.signals.values(:,3),pendEst.time,pendEst.signals.values(:,4))
legend("Encoder dq1", "Encoder dq2", "Kalman dq1", "Kalman dq2")

%% PFL for link 1

q1_ref = pi/2;

kp = 29.8;
kd = 8;

x_ref = [pi/2; 0; 0; 0];

controller = @(x) linearizedPD(x,x_ref,p,kp,kd);

x0 = [-pi/2; 0; 0; 0];

sol = ode45(@(t,x)dynamics(x, controller(x), p), linspace(0, 10,1000), x0);

%% Trajectory Optimization

addpath ../OptimTraj/

problem.func.dynamics = @(t,x,u)( dynamics(x,u,p) );
problem.func.pathObj = @(t,x,u)( u.^2 );

% Problem bounds
problem.bounds.initialTime.low = 0;
problem.bounds.initialTime.upp = 0;
problem.bounds.finalTime.low = 5;
problem.bounds.finalTime.upp = 30;

problem.bounds.state.low = [-inf; -inf; -inf; -inf];
problem.bounds.state.upp = [inf; inf; inf; inf];
problem.bounds.initialState.low = [-pi/2;0;0;0];
problem.bounds.initialState.upp = [-pi/2;0;0;0];
problem.bounds.finalState.low = [pi/2;0;0;0];
problem.bounds.finalState.upp = [pi/2;0;0;0];

problem.bounds.control.low = -inf; %-inf;
problem.bounds.control.upp = inf;

% Guess at the initial trajectory


problem.guess = guess;

% problem.guess.time = [0,25];
% problem.guess.state = [-0.5, 0.5; 0, 0];
% problem.guess.control = [0,0];

% t = linspace(0,20,20);
% problem.guess.time = t;
% problem.guess.state = [t.*sin(t*pi/40*9)/20-0.5; 0, diff(t.*sin(t*pi/40*9)/20-0.5)];
% problem.guess.control = [1, diff(problem.guess.state(2,:))];


% Select a solver:
problem.options.method = 'trapezoid';
problem.options.defaultAccuracy = 'high';
problem.options.trapezoid.nGrid = 100;
% problem.options.nlpOpt = optimoptions('fmincon');
% problem.options.nlpOpt.MaxIterations = 1000;

% Solve the problem
soln = optimTraj(problem);
t = soln.grid.time;
q1 = soln.grid.state(1,:);
q2 = soln.grid.state(2,:);

dq1 = soln.grid.state(3,:);
dq2 = soln.grid.state(4,:);
u = soln.grid.control;

%% plot traj

figure(1); clf;

subplot(3,1,1)
plot(t,q1, t, q2)
legend()
ylabel('q')
title('Pendulum');

subplot(3,1,2)
plot(t,dq1, t, dq2)
legend()
ylabel('dq')

subplot(3,1,3)
plot(t,u)
legend()
ylabel('u')
%%
figure(3)
clf 

hold on 
set(gca, 'YTickLabel', [ ]); 
lblTime = uicontrol('style','text');
lblAction = uicontrol('style','text');
set(lblTime,'Position', [10 20 40 20]);
set(lblAction,'Position', [10 50 40 20]);


for i = 1:length(t)
    clf; hold on;
    animate(t(i), soln.grid.state(:,i), ap)


    % set(lblTime,'String', i - 1);
    % set(lblAction,'String', u(i));
    
    drawnow;
    pause(0.05);
end

%% Test Open Loop With Simulink

x0 = [-pi/2; 0; 0; 0];

t_control = t;
ut = u;

model = 'OpenLoop';

set_param(model, "StopTime", string(t(end)))
set_param(model, 'SimulationMode', 'normal')
set_param(model, 'SimulationCommand', 'connect')
pause(1)
set_param(model, 'SimulationCommand', 'start')
pause(11)


%% animate result

output = out.pendPos;
ap.l1 = 1;
ap.l2 = 1.5;
for i = 1:50:length(output.time)
    clf; hold on;
    animate(output.time(i), output.signals.values(:,:,i), ap)
    animate(output.time(i), soln.grid.state(:,find(t>=output.time(i))), ap)

    drawnow; pause(0.05); 
end


%% Use closed loop to stabilize the traject
x0 = [-pi/2;0;0;0];
c.t_k = t;
c.u_star = u;
c.x_star = soln.grid.state;
c.bounds = [-pi/3 pi/3; -pi/3 pi/3]*inf;

c.K = zeros(1,4,length(t));

Q = diag([0.01, 7, 0.1, 0.9]);
R = 6;

for i = 1:length(t)
    A = J(c.x_star(:,i), 1e-5*ones(4,1), @(x)dynamics(x, u(i), p));

    B = J(u(i), 1e-5, @(u)dynamics(c.x_star(:,i), u, p));

    c.K(:,:, i) = lqr(A, B, Q, R);
end

%%

model = 'ClosedLoop';
set_param(model, "StopTime", string(t(end)+5))

set_param(model, 'Dirty', 'on')

set_param(model, 'SimulationMode', 'normal')
set_param(model, 'SimulationCommand', 'connect')
pause(1)
set_param(model, 'SimulationCommand', 'start')
pause(11)
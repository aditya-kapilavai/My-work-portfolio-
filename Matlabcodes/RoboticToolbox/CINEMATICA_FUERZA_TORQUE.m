format compact
clear all
close all
clear mex
clc

syms d1 d2 a2 a3 a4 a5 a6 real;
syms q1 q2 q3 q4 real; %% q1=d1 %%  %%real es una funcion para no dejar en la matriz numeros conjugados (conj) y que queden numeros reales
syms pi real;
syms fx fy fz nx ny nz;
syms al ga th real;

%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Jacobiano Geometrico %%
%%%%%%%%%%%%%%%%%%%%%%%%%%
q1=0.0;
q2=0.0;
q3=0.01;
q4=0.01;

d2=1.20349;
a2=.9907;
a3=.8862;
a4=1.5;
a5=.8862;
a6=1.5;

Jg=[0, -cos(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)),  sin(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)),  sin(q3 + q4)*sin(q2)*(a5 + a6);
    0,                                                                           0,          - a5*cos(q3 + q4) - a6*cos(q3 + q4) - a3*cos(q3) - a4*cos(q3),         -cos(q3 + q4)*(a5 + a6);
    1, -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)), -cos(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)), -sin(q3 + q4)*cos(q2)*(a5 + a6);
    0,                                                                           0,                                                                cos(q2),                         cos(q2);
    0,                                                                          -1,                                                                      0,                               0;
    0,                                                                           0,                                                                sin(q2),                         sin(q2)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Obntición de Torques de cada articulacion rotatoria a partir del Jg' por las fuerzas deseadas %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fx=1;
fy=1;
fz=1;
nx=0;
ny=0;
nz=0;

Fd=[fx fy fz nx ny nz].'
Jt=Jg.';
Td=Jt*Fd




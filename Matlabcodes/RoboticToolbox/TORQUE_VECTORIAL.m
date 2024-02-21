
format compact
clear all
close all
clear mex
clc

syms d1 d2 a2 a3 a4 a5 a6 real;
syms q1 q2 q3 q4 real;  %%real es una funcion para no dejar en la matriz numeros conjugados (conj) y que queden numeros reales
syms pi real;

syms al ga th real %variables para la matriz de los angulos de EULER y de orientacion 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CALCULO DEL MODELO GEOMETRICO DIRECTO %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% q1=d1;

d2r=pi/180;

q1=2.5;    % movimiento prismatico &&Aquí estoy colocando el maximo valor de alcance 
q2=0*d2r;
q3=0*d2r;
q4=0*d2r;

d2=1.20349;
a2=.9907; 
a3=.8862;
a4=1.5;
a5=.59;
a6=.59;

%DHmatrix(th,d,a,al)
 A1=DHmatrix(0,q1,0,pi/2);
 A2=DHmatrix(q2+pi/2,d2,a2,pi/2);
 A3=DHmatrix(q3,0,a3+a4,0);
 A4=DHmatrix(q4,0,a5+a6,0);

 T1=A1;
 T12=A1*A2;
 T13=A1*A2*A3;
 T14=A1*A2*A3*A4;

H=simple(T14);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Calculo de los torques %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 %Px=H(1,4)
 y=H(2,4)
 z=H(3,4)
 
l1=a3+a4;
r1=.59+.59;
r2=sqrt(y^2+z^2);
r3=.59+.59;

 Alpa=atan2(2,4)
 B=atan(y/z)
 cos_q2=((y^2+z^2-l1^2-r3^2)/(2*l1*r3))
 sin_q2=sqrt(1-cos_q2^2)

 Alpha=abs_atan2((r3*sin_q2),(l1+r3)*cos_q2)
 
 T1=f1*r1*sin
 
 
 
 



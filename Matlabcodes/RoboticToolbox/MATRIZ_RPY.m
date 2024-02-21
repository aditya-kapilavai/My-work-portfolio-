%Simbolico de calculo de la matriz de rotacion RALL PITCH YAW

clear all
close all
clc   %esto es para que limpie memoria

syms al ga th real

ca=cos(al);
sa=sin(al);

cg=cos(ga);
sg=sin(ga);

ct=cos(th);
st=sin(th);

Rx=[1 0 0;0 ca -sa;0 sa ca]  %alpha
Ry=[cg 0 sg;0 1 0;-sg 0 cg]  %gamma
Rz1=[ct -st 0; st ct 0; 0 0 1]  %theta

%RPY= Rz*Ry*Rx
Rz=Rz1
Rzy=Rz*Ry
Rzyx=Rz*Ry*Rx %matriz de rotacion RALL PITCH YAW

X=(Rz1(1:3,3));   
Y=(Rzy(1:3,2));   
Z=(Rzyx(1:3,1));  

Tphi=[Z Y X] %Jtheta de la matriz Jx= [I     0  ]
%                                     [0   Tphi ]  Tphi=Jtheta
Tphiinv=inv(Tphi)

% Calculo de los angulos de RPY a partir de la matriz de Rotacion de la
% matriz Homogenea
%  r21=R(2,1);
%  r11=R(1,1);
%  r31=R(3,1);
%  r32=R(3,2);
%  r33=R(3,3);
%  
%  th=atan2(r21,r11);%Z
%  ga=atan2(-r31,sqrt(r32^2+r33^2)); %Y
%  al=atan2(r32,r33);%X
% 
%   Theta=[al ga th].'; % valores de theta

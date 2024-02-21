
clear all
clc 
q1=0;
q2=0.2;
q3=0.2;
q4=0.2;

qt=[q1 q2 q3 q4].'

%% unidades en centimetros
d2=1.20349;
a2=.9907;
a3=.8862;
a4=1.5;
a5=.8862;
a6=1.5;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Modelo geometrico directo %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 H=[ -cos(q3 + q4)*sin(q2),  sin(q3 + q4)*sin(q2), cos(q2),                                         -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3));...
               -sin(q3 + q4),         -cos(q3 + q4),       0,                                                  - d2 - a5*sin(q3 + q4) - a6*sin(q3 + q4) - a3*sin(q3) - a4*sin(q3);...
        cos(q3 + q4)*cos(q2), -sin(q3 + q4)*cos(q2), sin(q2), q1 + a2*cos(q2) + cos(q2)*cos(q3)*(a3 + a4) - cos(q2)*sin(q3)*sin(q4)*(a5 + a6) + cos(q2)*cos(q3)*cos(q4)*(a5 + a6);...
                           0,                     0,       0,                                                                                                                  1];
                                                                                                                                                                                                                                  
Pxyz=[H(1,4) H(2,4) H(3,4)].';

%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% MATRIZ DE ROTACIÓN %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%

R=[ -cos(q3 + q4)*sin(q2),  sin(q3 + q4)*sin(q2), cos(q2);
              -sin(q3 + q4),         -cos(q3 + q4),       0;
      cos(q3 + q4)*cos(q2), -sin(q3 + q4)*cos(q2), sin(q2)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% variables para calcular alpha, gamma y theta.                                                                                     %%%
%% De los angulos RPY.  Las posiciones de la matriz de rotacion de los angulos de EULER y RPY para el calculo de alpha, gamma, theta %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Angulos Roll, Pitch y Yaw %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 r21=R(2,1);
 r11=R(1,1);
 r31=R(3,1);
 r32=R(3,2);
 r33=R(3,3);
 
 th=atan2(r21,r11);%Z
 ga=atan2(-r31,sqrt(r32^2+r33^2)); %Y
 al=atan2(r32,r33);%X

  Theta=[al ga th].'; % valores de theta
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% JACOBIANO DEL MANIPULADOR %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Jg =[ 0, -cos(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)),  sin(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)),  sin(q3 + q4)*sin(q2)*(a5 + a6);
      0,                                                                           0,          - a5*cos(q3 + q4) - a6*cos(q3 + q4) - a3*cos(q3) - a4*cos(q3),         -cos(q3 + q4)*(a5 + a6);
      1, -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)), -cos(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)), -sin(q3 + q4)*cos(q2)*(a5 + a6);
      0,                                                                           0,                                                                cos(q2),                         cos(q2);
      0,                                                                          -1,                                                                      0,                               0;
      0,                                                                           0,                                                                sin(q2),                         sin(q2)];


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% MATRIZ DE TRANSFORMACION DE LOS ANGULOS DE RPY %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Tphi =[ cos(ga)*cos(th), -sin(th), 0;
        cos(ga)*sin(th),  cos(th), 0;
               -sin(ga),        0, 1];
iTphi=inv(Tphi);

Ta_phi=[ eye(3)    zeros(3,3); %[I     0    ]
        zeros(3,3)   iTphi];   %[0 inv(Tphi)]
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Jacobiano analítico  %%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Ja=(Ta_phi*Jg); %ES UNA MATRIZ DE TAMAÑO 6x4
Ja_b=[Ja(1:4,1) Ja(1:4,2) Ja(1:4,3) Ja(1:4,4)];

 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %%% Jacobiano analítico inverso %%%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 

% [U,S,V] = svd(Ja_b);
%  %S_a=S(4,4);
%  lambda = 0.01;
% if (S(4,4) < lambda)
%     J_ainv=inv(Ja_b.'*Ja_b+lambda*eye(4))\Ja_b.';
% else 
    J_ainv = inv(Ja_b)
% end

%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Vector de posición %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%
Xpd_b_Ke=[4 -5.203 0 5].'

 X_b=[Pxyz;
     Theta]
% L=Xpd_b_Ke;
 qp=J_ainv*Xpd_b_Ke
% %Xp=Ja*qp;


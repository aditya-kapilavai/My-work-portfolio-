%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CÁLCULO DE LA CINEMATICA DIRECTA Y DEL JACOBIANO ANALITICO %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

format compact
clear all
close all
clear mex
clc
syms d1 d2 a2 a3 a4 a5 a6 real;
syms q1 q2 q3 q4 real;  %%real es una funcion para no dejar en la matriz numeros conjugados (conj) y que queden numeros reales
syms pi real;
syms al ga th real %variables para la matriz de los angulos de EULER y de orientacion 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%CALCULO DEL MODELO GEOMETRICO DIRECTO %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% q1=d1; %% d2r=pi/180;
%DHmatrix(th,d,a,al)
 A1=DHmatrix(0,q1,0,pi/2);
 A2=DHmatrix(q2+pi/2,d2,a2,pi/2);
 A3=DHmatrix(q3,0,a3+a4,0);
 A4=DHmatrix(q4,0,a5+a6,0);
 T1=A1
 T12=A1*A2
 T13=A1*A2*A3
 T14=A1*A2*A3*A4
 H=simple(T14)

 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %% CALCULO DEL JACOBIANO DE VELOCIDAD LINEAL %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  % POR PROCEDIMIENTO DE DERIVACIÓN DE LA POSICION A PARTIR DE LA MATRIZ HOMOGENEA
  %  J= JACOBIANO 
  %  Jv= Jacobiano de velocidad lineal analitico
 Rt=[H(1:3,1) H(1:3,2) H(1:3,3)]
 Px=H(1,4)
 Py=H(2,4)
 Pz=H(3,4)
% dxq1= diff(Px,q1); % dxq2= diff(Px,q2); % dxq3= diff(Px,q3); % dxq4= diff(Px,q4);
% dyq1= diff(Py,q1); % dyq2= diff(Py,q2); % dyq3= diff(Py,q3); % dyq4= diff(Py,q4); 
% dzq1= diff(Pz,q1); % dzq2= diff(Pz,q2); % dzq3= diff(Pz,q3); % dzq4= diff(Pz,q4);
%  Jv=[dxq1 dxq2 dxq3 dxq4; dyq1 dyq2 dyq3 dyq4; dzq1 dzq2 dzq3 dzq4];
J_v=simple(jacobian([Px;Py;Pz],[q1 q2 q3 q4]));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%             CALCULO DE JACOBIANOS                %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%A PARTIR DE LA VELOCIDAD ANGULAR DEL JACOBIANO GEOMETRICO 
%DONDE J=[I     0 ]*Ja       Ja=Jacobiano Analitico J=Jacobiano geometrico 
%         [0 T(phi)]          T(phi)=Son los vectores (columna 1, 2 , 3) de cada multiplicación de transformacion de
%                             las configuraciones que uno elija de la rotacion xyz, zyz, etc.

%POR LO TANTO Ja=[I      0     ]*J
%                [0 inv(T(phi))]

%% CALCULO DE LOS ANGULOS DE EULER A PARTIR DE LA MATRIZ DE TRANSFORMACIÓN HOMOGENEA (solo tomo la matriz de rotacion 3x3), Y UTILIZANDO LA MATRIZ XYZ DE LOS ANGULOS DE EULER
%% LOS VALORES OBTENIDOS DE al, ga, th SE SUSTITUYEN EN TIEMPO REAL EN LA MATRIZ DE Tphi PARA OBTENER LOS VALORES DE T(phi)
 r21=H(2,1);
 r11=H(1,1);
 r31=H(3,1);
 r32=H(3,2);
 r33=H(3,3);
%  th=atan2(r21,r11);%Z
%  ga=atan2(-r31,sqrt(r32^2+r33^2)); %Y
%  al=atan2(r32,r33);%X
%  Theta=[al ga th].'; % valores de theta

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% MATRIZ T(phi) PARA LA CONFIGURACION RPY %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%PARA VER EL CODIGO DE COMO SE OBTIENE XYZ IR AL PROGRAMA
%MATRIZ_RPY

%% Matriz B o T(phi) obtenida a partir de los angulos de Euler (XYZ) de la rotacion RPY
Tphi =[ cos(ga)*cos(th), -sin(th), 0;
        cos(ga)*sin(th),  cos(th), 0;
               -sin(ga),        0, 1];

%% Valores obtenidos del programa JACOBIANO GEOMETRICO

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% JACOBIANO DE VELOCIDAD LINEAL %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Jv geometrico es igual al Jv analitico %%
 Jv=[0, -cos(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)),  sin(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)),  sin(q3 + q4)*sin(q2)*(a5 + a6);
     0,                                                                           0,          - a5*cos(q3 + q4) - a6*cos(q3 + q4) - a3*cos(q3) - a4*cos(q3),         -cos(q3 + q4)*(a5 + a6);
     1, -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)), -cos(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)), -sin(q3 + q4)*cos(q2)*(a5 + a6)];
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% JACOBIANO DE VELOCIDAD ANGULAR %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 Jw=[0,  0, cos(q2), cos(q2);
     0, -1,       0,       0;
     0,  0, sin(q2), sin(q2)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% OBTENCIÓN DE LA MATRIZ DEL JACOBIANO ANALITICO A PARTIR DEL JACOBIANO GEOMETRICO %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Ja=[I      0     ]*Jg
%     [0 inv(T(phi))]
Jg=[0, -cos(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)),  sin(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)),  sin(q3 + q4)*sin(q2)*(a5 + a6);
    0,                                                                           0,          - a5*cos(q3 + q4) - a6*cos(q3 + q4) - a3*cos(q3) - a4*cos(q3),         -cos(q3 + q4)*(a5 + a6);
    1, -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3)), -cos(q2)*(a5*sin(q3 + q4) + a6*sin(q3 + q4) + a3*sin(q3) + a4*sin(q3)), -sin(q3 + q4)*cos(q2)*(a5 + a6);
    0,                                                                           0,                                                                cos(q2),                         cos(q2);
    0,                                                                          -1,                                                                      0,                               0;
    0,                                                                           0,                                                                sin(q2),                         sin(q2)];

iTphi=inv(Tphi)
Ta_phi=[ eye(3)    zeros(3,3); %[I     0    ]
        zeros(3,3)   iTphi]    %[0 inv(Tphi)]
Ja=simple(Ta_phi*Jg) %ES UNA MATRIZ DE TAMAÑO 6x4

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% JACOBIANA INVERSA POR EL METODO DE LA PSEUDO-INVERSA IZQUIERDA %%
%      DONDE m>n ES DECIR TIENE MAS FILAS(6) QUE COLUMNAS(4)      %% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%JaT=simple(Ja.'); %el punto es para que me de el resultado real de la transpuesta y no me de la transpuesta conjugada
%lambda=0.01;
%JaT_Ja=simple(JaT*Ja+lambda*eye(4));%esta matriz es de cuadratica de tamaño 4x4
%JaT_Ja=simple(JaT*Ja);
% Ja_inv=(JaT_Ja)\JaT;




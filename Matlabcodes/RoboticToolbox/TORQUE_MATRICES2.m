
format compact
clear all
close all
clear mex
clc
%% Variables
 
syms d1 d2 a2 a3 a4 a5 a6 real;
syms q1 q2 q3 q4 real;  %%real es una funcion para no dejar en la matriz numeros conjugados (conj) y que queden numeros reales
syms pi real;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   CALCULO DEL MODELO GEOMETRICO DIRECTO   %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%DHmatrix(theta,d,a,pi/2)
 A1=DHmatrix(0,q1,0,pi/2);
 A2=DHmatrix(q2+pi/2,d2,a2,pi/2);
 A3=DHmatrix(q3,0,a3+a4,0);
 A4=DHmatrix(q4,0,a5+a6,0);

 T1=(A1);
 T12=simple(A1*A2);
 T13=simple(A1*A2*A3);
 T14=simple(A1*A2*A3*A4);

 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %%   CALCULO DEL JACOBIANO POR RPOCEDIMIENTO PRODUCTO CRUZ   %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 %  J= JACOBIANO
 %  Jv= Jacobiano de velocidad lineal
 %  Jw= Jacobiano de velocidad agular
 
 %  J= Jv/Jw  tenemos    J= [ J1       J2           J3          J4    ] 
 
 %DONDE EL JACOBIANO ==> J= [ Z0   Z1x(O3-O1)   Z2x(O3-O2)]=> 3
 %                          [  0       Z1           Z2    ]=> 3
 % x=PRODUCTO CRUZ
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%
 %%   CALCULO DE LAS Zi   %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 %Donde Z son los primeros 3 valores de la 3ra columna de las matrices
 %de transformación
       
 Z_0=[0 0 1].';  %ALWAYS
 Z_1=(T1(1:3,3)); %toma los primeros 3 valores de la columna 3
 Z_2=(T12(1:3,3));
 

 %%%%%%%%%%%%%%%%%%%%%%%%%%%
 %%   CALCULO DE LAS Oi   %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%

 % Donde O son los primeros 3 valores de la 4ra columna de las matrices
 % de transformación

 %O_0=[0 0 1]'  %ALWAYS
 O_1=(T1(1:3,4)); %toma los primeros 3 valores de la columna 3
 O_2=(T12(1:3,4));
 O_3=(T13(1:3,4));
 

%  O_30=O_4-O_0
 O_31=simple(O_3-O_1);
 O_32=simple(O_3-O_2);
 
 
 %%VALORES DEL PRODUCTO CRUZ
 J_v1=Z_0;
 J_v2=simple(cross(Z_1,O_31));
 J_v3=simple(cross(Z_2,O_32));
 
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %% JACOBIANO DE VELOCIDAD DE VELOCIDAD LINEAL %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 Jv1=[J_v1 J_v2 J_v3];
   %Este Jacobiano es del mismo valor que el Ja de velocidad lineal
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %% JACOBIANO DE VELOCIDAD DE VELOCIDAD ANGULAR %%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 O= [0 0 0].'; %Equivale a los ceros, o con la funcion (zeros(1,3).')
 Jw1=[O Z_1 Z_2];
 
 J1=[Jv1;
     Jw1]
 

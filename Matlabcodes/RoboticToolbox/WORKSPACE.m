%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%PROGRAMA PAR LA OBTENCIÓN DE LA CINEMATICA DIRECTA DEL BRAZO HUMANO %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% USING D-H PARAMETERS AND HOMOGENOUS TRANSFORMATIONS
 format compact
clear all
close all
clear mex
clc

disp('Computing Forward Kinematics...')
 
%% Declaración de variables
syms d2 a2 a3 a4 a5 a6 real; % q1=d1; DISTANCIAS DE LOS ESLABONES
syms q1 q2 q3 q4 real;  % valores articulares %%real es una funcion para no dejar en la matriz numeros conjugados (conj) y que queden numeros reales
syms pi real;

%% DENAVITH-HARTENBERG
n=3;
a=[0;a2;a3+a4;a5+a6];
d=[q1;d2;0;0];
alpha=[pi/2;pi/2;0;0];
q=[0;q2+pi/2;q3;q4];
A=TCo(a,d,alpha,q);


% A0=A(1:4,1:4);
 A1=A(1:4,1:4);
 A2=A(5:8,1:4);
 A3=A(9:12,1:4);  
 A4=A(13:16,1:4);  
 
%% MATRICES DE TRANSFORMACIÓN

 T01=simple(A1);
 T02=simple(T01*A2);
 T03=simple(T02*A3);
 T04=simple(T03*A4);
  
disp('Forward Kinematics has done!');

%% Graphics

disp('MAKING GRAPHICS!')
clear pi
d2r=pi/180;

%Unidades estan en centimetros
q1=2.5;    % movimiento prismatico &&Aquí estoy colocando el maximo valor de alcance 
q2=0*d2r;
q3=0*d2r;
q4=0*d2r;

d2=1.20349;
a2=.9907; 
a3=.8862;
a4=1.5; %el movimiento de extension es aprox. 1.46cm acorde a analisis de movimiento
a5=.8862;
a6=1.5; %el movimiento de extension es aprox. 1.46cm acorde a analisis de movimiento

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Graficando el eslabón con cada una de las articulaciones %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 d0=[0;0;0];
 d01=subs(T01(1:3,4))
 d02=subs(T02(1:3,4));
 d03=subs(T03(1:3,4));
 d04=subs(T04(1:3,4))

disp('Figure 1: posición inicial del brazo');

figure(1);

%%NOTA:
%Con esta configuración el dibujo queda invertido quedando los valores del
%end-effector XYZ=ZYX

% plot3([ d0(3) d01(3)],[d0(2)  d01(2)],[d0(1)  d01(1)],'green',...
%       [d01(3) d02(3)],[d01(2) d02(2)],[d01(1) d02(1)],'blue',...
%       [d02(3) d03(3)],[d02(2) d03(2)],[d02(1) d03(1)],'green',...
%       [d03(3) d04(3)],[d03(2) d04(2)],[d03(1) d04(1)],'black ','linewidth',3);
% hold on

%%NOTA:
%Con esta configuración el dibujo queda invertido quedando los valores del
%end-effector XYZ=XYZ
plot3([d0(1)  d01(1)],[d0(2)  d01(2)],[d0(3) d01(3)],'green',...
      [d01(1) d02(1)],[d01(2) d02(2)],[d01(3) d02(3)],'blue',...
      [d02(1) d03(1)],[d02(2) d03(2)],[d02(3) d03(3)],'green',...
      [d03(1) d04(1)],[d03(2) d04(2)],[d03(3) d04(3)],'black ','linewidth',3);
hold on

xlabel('X');
ylabel('Y');
zlabel('Z');

axis([-9 9 -9 9 -1 9]);

grid on

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %% Espacio de trabajo de los 3 movimientos con un intervalo   %%
% %% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
l1=1;
al1=1;
d0_2=zeros(3,10000);
d0_3=zeros(3,10000);
d0_4=zeros(3,10000);
for  q2=-15*d2r:.1:15*d2r  %q2=0*d2r:.025:0*d2r 
    for q3=0*d2r:.1:90*d2r %90
        for q4=0*d2r:.1:110*d2r %110
           q_2=q2;
           q_3=q3;
           q_4=q4;
        %d0_1(:,l1) =subs(T01(1:3,4));
        d0_2(:,l1) =subs(T02(1:3,4));
        d0_3(:,l1) =subs(T03(1:3,4));
        d0_4(:,l1) =subs(T04(1:3,4));
        
        l1=l1+1;
    
    %plot3(d0_2(3,l),d0_2(2,l),d0_2(1,l),'red o')
    %plot3(d0_3(3,l),d0_3(2,l),d0_3(1,l),'blue .')
    
    %%NOTA:
    %Con esta configuración el dibujo queda invertido quedando los valores del
    %end-effector XYZ=ZYX
    %plot3(d0_4(3,l),d0_4(2,l),d0_4(1,l),'red *');
          
    %%NOTA:
    %Con esta configuración el dibujo queda invertido quedando los valores del
    %end-effector XYZ=XYZ
        end
    end
        switch(al1)
            case 1
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'k +');
            case 2
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'b +');
            case 3
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'r +');
            case 4
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'y +');
            case 5
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'g +');
            case 6
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'m +');
            case 7
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'k +');
            case 8
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'k +');
            case 9
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'b +');
            case 10
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'r +');
            case 
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'y +');
            case 5
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'g +');
            case 6
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'m +');
            case 7
                plot3(d0_4(1,:),d0_4(2,:),d0_4(3,:),'k +');
            otherwise
        end
        al1=al1+1
        l1=1
        drawnow
end

 xlabel('X');
 ylabel('Y');
 zlabel('Z');
 grid on


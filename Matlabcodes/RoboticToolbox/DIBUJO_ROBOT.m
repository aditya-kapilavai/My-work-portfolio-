%MOVIMIENTO PRISMATICO

%%%%%%%%%%%%%%%%%%%%%%
%NOTA: LA FUNCION DHmatrix ESTA EN RADIANES y
%LA FUNCION =DHmatrixg ESTA EN GRADOS
%%%%%%%%%%%%%%%%%%%%%%

q1=2.5;
es1 = line([0 0], [0 0], [0 0] );
%TRANSLACION FIJA
d2=1.20349;
%TRANSLACION FIJA
a2=.9907;
%MOVIMIENTO ROTACIONAL Q4
a3=.8862;
a4=1.5;
es2 = line([0 0],[0 0], [0 0]);
%MOVIMIENTO ROTACIONAL Q4
a5=.8862;
a6=1.5;
es3 = line([0 0],[0 0], [0 0]);

p1=0;
p2=-3.59;
p3=-1.596;
es4 = line([0 0],[0 0], [0 0]);

%%
d2r=pi/180;
alpha=pi/2;

theta2=0*d2r;
theta3=90*d2r;
theta4=90*d2r;

hold on
 xlabel('X');
 ylabel('Y');
 zlabel('Z');

axis([-10 10 -10 10 -10 10]);
%% grid on

set(es1,'color',[1 0 0]);  %'color',[r g b])
set(es1,'LineWidth',3);
set(es2,'color',[0 1 0]);
set(es2,'LineWidth',3);
set(es3,'color',[0 0 1]);
set(es3,'LineWidth',3);
set(es4,'color',[1 0 0]);
set(es4,'LineWidth',3);

   
 A0=DHmatrix(0,q1,0,alpha);
 A1=DHmatrix(theta2+alpha,d2,a2,alpha);
 A2=DHmatrix(theta3,0,a3+a4,0);
 A3=DHmatrix(theta4,0,a5+a6,0);
 
 T01=A0*A1;
 T02=A0*A1*A2;
 T03=A0*A1*A2*A3;

set(es1,'Xdata',[0 T01(1,4)]);
set(es1,'Ydata',[0 T01(2,4)]);
set(es1,'Zdata',[0 T01(3,4)]);

set(es2,'Xdata',[T01(1,4) T02(1,4)]);
set(es2,'Ydata',[T01(2,4) T02(2,4)]);
set(es2,'Zdata',[T01(3,4) T02(3,4)]);

set(es3,'Xdata',[T02(1,4) T03(1,4)]);
set(es3,'Ydata',[T02(2,4) T03(2,4)]);
set(es3,'Zdata',[T02(3,4) T03(3,4)]);
   
% set(es4,'Xdata',[0 0.5 ]);
% set(es4,'Ydata',[-12.03 -11.7]);
% set(es4,'Zdata',[55.63 56]);


grid on
plot3 (p1, p2, p3,'o');

drawnow




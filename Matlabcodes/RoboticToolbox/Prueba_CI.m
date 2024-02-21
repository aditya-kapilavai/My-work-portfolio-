clear all;
clc ;

px=3.757;
py=-27.74;
pz=10.98;

a2=7.907;
a3=8.862
a4=15
a5=8.862
a6=15
a34=a3+a4;
a56=a5+a6;

r= sqrt(px^2+pz^2);
r_a2= r-a2

%%
theta2=atan2(px,py)
%% 
    Ctheta4=((px^2+pz^2+py^2-a34^2-a56^2)/2*a34*a56)
    Stheta4=sqrt(1-(Ctheta4)^2)
%%
theta4=atan2(Stheta4,Ctheta4)
%%
    B=atan2(py,r_a2)
    alpha=atan((a56*Stheta4)/((a34+a56)*Ctheta4)) 
    
%%   
 theta3=B-alpha
%%
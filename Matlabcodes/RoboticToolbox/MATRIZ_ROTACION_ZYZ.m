%Simbolico de calculo de la matriz de rotacion Z->Y->X

clear all
close all
format compact
clc   %esto es para que limpie memoria

syms alpha gamma theta real

ca=cos(alpha);
sa=sin(alpha);

cg=cos(gamma);
sg=sin(gamma);

ct=cos(theta);
st=sin(theta);

%Rx=[1 0 0;0 ca -sa;0 sa ca]
Rzo=[ca -sa 0; sa ca 0; 0 0 1];
Ry=[cg 0 sg;0 1 0;-sg 0 cg];
Rz=[ct -st 0; st ct 0; 0 0 1];

Rz1=Rzo;
Rzy=Rzo*Ry;
Rzyz=Rzo*Ry*Rz;  

X=(Rz1(1:3,3));
Y=(Rzy(1:3,2));
Z=(Rzyz(1:3,3));

Tphi=[X Y Z]
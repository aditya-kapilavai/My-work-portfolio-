
%% MINIWORKSHOP ON ROBOTICS, CIITEC-IPN
%% NUMERICAL RESULTS
%% LUIS I. LUGO-VILLEDA @COPYRIGHT
%% PERCRO -SCUOLA SUPERIORE SANT'ANNA
%% NUMBER:02
%% HOMOGENOUS TRANSFORMATION USING THE D-H PARAMETERS
%% JANUARY 2009

function A=TCo(a,d,alpha,q)


[m,n]=size(q);

DOF=m*n;

A=[sym(ones(4*DOF,4))];
for i=1:DOF;     
    o=1+4*(i-1);
    p=4*i;
    A(o:p,1:4)= ...
            [cos(q(i)) -sin(q(i))*cos(alpha(i)) sin(q(i))*sin(alpha(i)) a(i)*cos(q(i));...
             sin(q(i))  cos(q(i))*cos(alpha(i)) -cos(q(i))*sin(alpha(i)) a(i)*sin(q(i));...
             0          sin(alpha(i))             cos(alpha(i))              d(i);....
             0            0                       0                           1];
end
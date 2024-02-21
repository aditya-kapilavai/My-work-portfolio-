clc 
clear all

Ja=[2 3 4 5;
   3 4 1 9;
   8 0 2 1;
   1 0 3 9;
   4 2 8 7;
   3 9 7 8]

Jt=Ja.'


 Sa=Ja.'*Ja
 lambda=0.01;
 %J_ainv=(Ja.'*Ja)\Ja.';
 
 J_ainv=(Ja.'*Ja + lambda*eye(4))\Ja.';

S_a= Sa(4,4)
% if (Sa(4,4) < lambda )
     J_ainv=(Ja.'*Ja + lambda*eye(4))\Ja.'
 %else 
     J_ainv=(Ja.'*Ja)\Ja.'
 %end
      Jtinv = pinv(Ja)
 
     [U,S,V] = svd(Jt);
ldaM = 0.01;
if (S(6,6) < ldaM )
    Jtinv = Jt.'/(Jt*Jt.'+ldaM*eye(6));
else 
    Jtinv = pinv(Jt);
end 
 
 
%  J_ainv =
%    -0.0058    0.0367    0.1270   -0.0271   -0.0133   -0.0114
%     0.0063    0.0385   -0.0121   -0.0834   -0.0672    0.1068
%     0.0255   -0.1194   -0.0275    0.0003    0.1179    0.0184
%     0.0014    0.0669   -0.0204    0.0772   -0.0081   -0.0284


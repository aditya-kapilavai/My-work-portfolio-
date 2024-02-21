function [MGD] =mgdFalange(q1,d2,a2,a3,a4,a5,a6,q2,q3,q4)
          
MGD=[ -cos(q3 + q4)*sin(q2),  sin(q3 + q4)*sin(q2), cos(q2),                                         -sin(q2)*(a2 + a5*cos(q3 + q4) + a6*cos(q3 + q4) + a3*cos(q3) + a4*cos(q3));...
              -sin(q3 + q4),         -cos(q3 + q4),       0,                                                  - d2 - a5*sin(q3 + q4) - a6*sin(q3 + q4) - a3*sin(q3) - a4*sin(q3);...
       cos(q3 + q4)*cos(q2), -sin(q3 + q4)*cos(q2), sin(q2), q1 + a2*cos(q2) + cos(q2)*cos(q3)*(a3 + a4) - cos(q2)*sin(q3)*sin(q4)*(a5 + a6) + cos(q2)*cos(q3)*cos(q4)*(a5 + a6);...
                          0,                     0,       0,                                                                                                                   1];
                 
                 
                 
                                                                                                                                                                                                                                                        
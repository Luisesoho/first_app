set r / 
r27
/; 

set j / 
Q 
j161
j162
j163
j164
j165
j166
j167
j168
j169
j170
S 
/; 

set t /t0*t50/; 

VN(h,j)=no; 
VN('Q','j161')=yes;
VN('j161','S')=yes;
VN('Q','j162')=yes;
VN('j162','S')=yes;
VN('Q','j163')=yes;
VN('j163','S')=yes;
VN('Q','j164')=yes;
VN('j164','S')=yes;
VN('Q','j165')=yes;
VN('j165','S')=yes;
VN('Q','j166')=yes;
VN('j166','S')=yes;
VN('Q','j167')=yes;
VN('j167','S')=yes;
VN('Q','j168')=yes;
VN('j168','S')=yes;
VN('Q','j169')=yes;
VN('j169','S')=yes;
VN('Q','j170')=yes;
VN('j170','S')=yes;

VN('j161','j162')=yes; 
VN('j162','j163')=yes; 
VN('j162','j164')=yes; 
VN('j163','j165')=yes; 
VN('j163','j166')=yes; 
VN('j164','j168')=yes; 
VN('j165','j169')=yes; 
VN('j166','j167')=yes; 
VN('j167','j168')=yes; 
VN('j168','j169')=yes; 
VN('j169','j170')=yes; 

parameter 
d(j) / 
Q   0
S   0
j161   1
j162   2
j163   3
j164   2
j165   3
j166   4
j167   6
j168   8
j169   3
j170   15
/
Kap(r) /
r27   9
/;

k(j,r)=0;
k('j161','r27')=8;
k('j162','r27')=8;
k('j163','r27')=5;
k('j164','r27')=4;
k('j165','r27')=4;
k('j166','r27')=8;
k('j167','r27')=7;
k('j168','r27')=6;
k('j169','r27')=5;
k('j170','r27')=8;

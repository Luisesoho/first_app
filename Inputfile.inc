set r / 
r2
/; 

set j / 
Q 
j5
j6
j7
j8
j9
j10
j11
j12
j13
j14
S 
/; 

set t /t0*t50/; 

VN(h,j)=no; 
VN('Q','j5')=yes;
VN('j5','S')=yes;
VN('Q','j6')=yes;
VN('j6','S')=yes;
VN('Q','j7')=yes;
VN('j7','S')=yes;
VN('Q','j8')=yes;
VN('j8','S')=yes;
VN('Q','j9')=yes;
VN('j9','S')=yes;
VN('Q','j10')=yes;
VN('j10','S')=yes;
VN('Q','j11')=yes;
VN('j11','S')=yes;
VN('Q','j12')=yes;
VN('j12','S')=yes;
VN('Q','j13')=yes;
VN('j13','S')=yes;
VN('Q','j14')=yes;
VN('j14','S')=yes;

VN('j5','j6')=yes; 
VN('j6','j7')=yes; 
VN('j6','j8')=yes; 
VN('j7','j9')=yes; 
VN('j7','j10')=yes; 
VN('j8','j12')=yes; 
VN('j9','j13')=yes; 
VN('j10','j11')=yes; 
VN('j11','j12')=yes; 
VN('j12','j13')=yes; 
VN('j13','j14')=yes; 

parameter 
d(j) / 
Q   0
S   0
j5   1
j6   2
j7   3
j8   2
j9   3
j10   4
j11   6
j12   8
j13   3
j14   15
/
FEZ(j) /
Q   0
S   0
j5   1
j6   3
j7   6
j8   5
j9   9
j10   10
j11   16
j12   24
j13   27
j14   42
/
SEZ(j) /
Q   0
S   50
j5   1
j6   3
j7   6
j8   16
j9   24
j10   10
j11   16
j12   24
j13   27
j14   50
/
Kap(r) /
r2   9
/;

k(j,r)=0;
k('j5','r2')=8;
k('j6','r2')=8;
k('j7','r2')=5;
k('j8','r2')=4;
k('j9','r2')=4;
k('j10','r2')=8;
k('j11','r2')=7;
k('j12','r2')=6;
k('j13','r2')=5;
k('j14','r2')=8;

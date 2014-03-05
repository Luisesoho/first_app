set r / 
r10
/; 

set j / 
Q 
j10
j11
j12
S 
/; 

set t /t0*t20/; 

VN(h,j)=no; 
VN('Q','j10')=yes;
VN('j10','S')=yes;
VN('Q','j11')=yes;
VN('j11','S')=yes;
VN('Q','j12')=yes;
VN('j12','S')=yes;

VN('j10','j11')=yes; 

parameter 
d(j) / 
Q   0
S   0
j10   4
j11   4
j12   3
/
FEZ(j) /
Q   0
S   0
j10   4
j11   8
j12   3
/
SEZ(j) /
Q   0
S   20
j10   4
j11   8
j12   6
/
Kap(r) /
r10   10
/;

k(j,r)=0;
k('j10','r10')=1;

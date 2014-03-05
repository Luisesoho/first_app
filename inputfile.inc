set r /
Paolo
Carolina
Luise
Martin
/;

set j /
Q
kochen
Backen
S
/;

set t /t0*t20/;

VN(h,j)=no;
VN('Q','kochen')=yes;
VN('kochen','S')=yes;
VN('Q','Backen')=yes;
VN('Backen','S')=yes;

VN('kochen','Backen')=yes;

parameter
d(j) /
Q   0
S   0
kochen   5
Backen   5
/
FEZ(j) /
Q   0
S   0
kochen   5
Backen   10
/
SEZ(j) /
Q   0
S   20
kochen   5
Backen   10
/
Kap(r) /
Paolo   5
Carolina   5
Luise   5
Martin   5
/;

k(j,r)=0;
k('kochen','Paolo')=2;
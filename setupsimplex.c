#include "grav.h"

void setupsimplex(){
if(D==2){
DminusOneNumber=simplex_number+node_number-2;
DminusTwoNumber=node_number;
Dm1num=0;
Dm2num=0;
}

if(D==3){
DminusOneNumber=2*simplex_number;
DminusTwoNumber=node_number+simplex_number;
DminusThreeNumber=node_number;
Dm1num=0;
Dm2num=0;
Dm3num=0;
}

if(D==4){
DminusOneNumber=(int)(1.0*DPLUS/2*simplex_number);  // N3=[(d+1)/2]N
DminusTwoNumber=2*(node_number+simplex_number-2); // N2=2*N0 + 2N - 4 
DminusThreeNumber=3*node_number+(int)(0.5*simplex_number)-6;  // N1=3*NO + ((N/2) -6) 
DminusFourNumber=node_number;  // =N0     // \chi = N0 - N1 + N2 - N3 + N --> 2 
Dm1num=0;
Dm2num=0;
Dm3num=0;
Dm4num=0;
}
    
if((D==2) || (D==3) || (D==4)){
sI=vector(0,NNZDm1-1);
rowI=ivector(0,NNZDm1-1);
colI=ivector(0,NNZDm1-1);
sJ=vector(0,NNZDm2-1);
rowJ=ivector(0,NNZDm2-1);
colJ=ivector(0,NNZDm2-1);
}

if(D==3 || (D==4)){
sK=vector(0,NNZDm3-1);
rowK=ivector(0,NNZDm3-1);
colK=ivector(0,NNZDm3-1);
}

if(D==4){
sL=vector(0,NNZDm4-1);
rowL=ivector(0,NNZDm4-1);
colL=ivector(0,NNZDm4-1);
}

return;
}
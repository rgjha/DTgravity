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
DminusOneNumber=(int)(1.0*DPLUS/2*simplex_number);
DminusTwoNumber=2*(node_number+simplex_number-2);
DminusThreeNumber=3*node_number+(int)(0.5*simplex_number)-6;
DminusFourNumber=node_number;
Dm1num=0;
Dm2num=0;
Dm3num=0;
Dm4num=0;
}

if((D==2) || (D==3) || (D==4)){
/*I=matrix(0,simplex_number-1,0,DminusOneNumber-1);
ITRANS=matrix(0,DminusOneNumber-1,0,simplex_number-1);
J=matrix(0,DminusOneNumber-1,0,DminusTwoNumber-1);
JTRANS=matrix(0,DminusTwoNumber-1,0,DminusOneNumber-1);

for(int i=0;i<simplex_number;i++){
for(int j=0;j<DminusOneNumber;j++){
I[i][j]=0.0;}}
for(int i=0;i<DminusOneNumber;i++){
for(int j=0;j<simplex_number;j++){
ITRANS[i][j]=0.0;}}
for(int i=0;i<DminusOneNumber;i++){
for(int j=0;j<DminusTwoNumber;j++){
J[i][j]=0.0;}}
for(int i=0;i<DminusTwoNumber;i++){
for(int j=0;j<DminusOneNumber;j++){
JTRANS[i][j]=0.0;}}*/

sI=vector(0,NNZDm1-1);
rowI=ivector(0,NNZDm1-1);
colI=ivector(0,NNZDm1-1);
sJ=vector(0,NNZDm2-1);
rowJ=ivector(0,NNZDm2-1);
colJ=ivector(0,NNZDm2-1);
}

if(D==3 || (D==4)){
/*K=matrix(0,DminusTwoNumber-1,0,DminusThreeNumber-1);
KTRANS=matrix(0,DminusThreeNumber-1,0,DminusTwoNumber-1);
for(int i=0;i<DminusTwoNumber;i++){
for(int j=0;j<DminusThreeNumber;j++){
K[i][j]=0.0;}}
for(int i=0;i<DminusThreeNumber;i++){
for(int j=0;j<DminusTwoNumber;j++){
KTRANS[i][j]=0.0;}}*/
sK=vector(0,NNZDm3-1);
rowK=ivector(0,NNZDm3-1);
colK=ivector(0,NNZDm3-1);
}

if(D==4){
/*L=matrix(0,DminusThreeNumber-1,0,DminusFourNumber-1);
LTRANS=matrix(0,DminusFourNumber-1,0,DminusThreeNumber-1);
for(int i=0;i<DminusThreeNumber;i++){
for(int j=0;j<DminusFourNumber;j++){
L[i][j]=0.0;}}
for(int i=0;i<DminusFourNumber;i++){
for(int j=0;j<DminusThreeNumber;j++){
LTRANS[i][j]=0.0;}}*/
sL=vector(0,NNZDm4-1);
rowL=ivector(0,NNZDm4-1);
colL=ivector(0,NNZDm4-1);
}

return;
}

#include "grav.h"

void cleanup(void){

if(D==2 || (D==3) || (D==4)){
//free_matrix(I,0,simplex_number-1,0,DminusOneNumber-1);
//free_matrix(ITRANS,0,DminusOneNumber-1,0,simplex_number-1);
//free_matrix(J,0,DminusOneNumber-1,0,DminusTwoNumber-1);
//free_matrix(JTRANS,0,DminusTwoNumber-1,0,DminusOneNumber-1);
free_vector(sI,0,NNZDm1-1);
free_ivector(rowI,0,NNZDm1-1);
free_ivector(colI,0,NNZDm1-1);
free_vector(sJ,0,NNZDm2-1);
free_ivector(rowJ,0,NNZDm2-1);
free_ivector(colJ,0,NNZDm2-1);
}
if(D==3 || (D==4)){
//free_matrix(K,0,DminusTwoNumber-1,0,DminusThreeNumber-1);
//free_matrix(KTRANS,0,DminusThreeNumber-1,0,DminusTwoNumber-1);
free_vector(sK,0,NNZDm3-1);
free_ivector(rowK,0,NNZDm3-1);
free_ivector(colK,0,NNZDm3-1);
}
if(D==4){
//free_matrix(L,0,DminusThreeNumber-1,0,DminusFourNumber-1);
//free_matrix(LTRANS,0,DminusFourNumber-1,0,DminusThreeNumber-1);
free_vector(sL,0,NNZDm4-1);
free_ivector(rowL,0,NNZDm4-1);
free_ivector(colL,0,NNZDm4-1);}

return;
}

//
//  calcdet.c
//  
//
//  Created by Simon Catterall on 3/8/18.
//
//

#include "grav.h"
double calcdet(double **a, int n){
double d=0;
int *indx=ivector(0,n-1);
ludcmp(a,n,indx,&d);
for(int i=0;i<n;i++){
d=d+log(fabs(a[i][i]));}
free_ivector(indx,0,n-1);
return(d);
}

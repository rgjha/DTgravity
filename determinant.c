// ----------------------------------------------------------------------------
#include "grav.h"
// ---------------------------------------------------------------------------
// Compute determinant of the Q matrix through LAPACK.
// Matches with Simon's calculation using SuperLU.
// Call is made through sparsedet.c as --> find_det(test, #) ;

double find_det(double **Q, int j) {
int row, col, stat = 0;
double det, det2;
int n = j ;
double **OUT;
int *ipiv ; 
ipiv = malloc(sizeof *ipiv * n);
double *store = malloc(sizeof *store *  n * n);
int p;

// Convert Q to column-major double array used by LAPACK
for (row = 0; row < n; row++) {
for (col = 0; col < n; col++) {
p = (col*n + row);
store[p] = Q[row][col]; 
}
}
     
dgetrf(&n, &n, store, &n, ipiv, &stat);
// https://github.com/Reference-LAPACK/lapack/blob/master/SRC/dgetrf.f
// store has input & output 
 
det = 0;
for (p = 0; p < n; p++) {
det=det+log(fabs(store[p*(n+1)]));
}
return det;    
}

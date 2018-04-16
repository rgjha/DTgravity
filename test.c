//
//  test.c
//  
//
//  Created by smcatter on 3/25/18.
//
//

#include <stdio.h>
#include <math.h>
#include "slu_ddefs.h"


int main(int argc, char *argv[]){
    
    SuperMatrix A,B;
    SuperMatrix LO,U;
    double *rhs,*a;
    int *perm_r,*perm_c,*xa,*asub;
    int nrhs,info,nnz,n,m,permc_spec,i,j;
    double s, u, p, e, r, l;
    superlu_options_t options;
    SuperLUStat_t stat;
    nnz=12;
    m=n=5;
    
 
    /*for(i=0;i<=n;i++){
        xa[i]=i*6;
    }
    for(j=0;j<nnz;j++){
    asub[j]=j%n;}

    for(i=0;i<n;i++){
        for(j=xa[i];j<xa[i+1];j++){
            if(asub[j]==i) a[j]=5.01;
            else
                a[j]=-1.0;
        }}*/
    if ( !(a = doubleMalloc(nnz)) ) ABORT("Malloc fails for a[].");
    if ( !(asub = intMalloc(nnz)) ) ABORT("Malloc fails for asub[].");
    if ( !(xa = intMalloc(n+1)) ) ABORT("Malloc fails for xa[].");
    s = 19.0; u = 21.0; p = 16.0; e = 5.0; r = 18.0; l = 12.0;
    a[0] = s; a[1] = l; a[2] = l; a[3] = u; a[4] = l; a[5] = l;
    a[6] = u; a[7] = p; a[8] = u; a[9] = e; a[10]= u; a[11]= r;
    asub[0] = 0; asub[1] = 1; asub[2] = 4; asub[3] = 1;
    asub[4] = 2; asub[5] = 4; asub[6] = 0; asub[7] = 2;
    asub[8] = 0; asub[9] = 3; asub[10]= 3; asub[11]= 4;
    xa[0] = 0; xa[1] = 3; xa[2] = 6; xa[3] = 8; xa[4] = 10; xa[5] = 12;
    
    (void)printf("calling superLU\n");fflush(stdout);
    
    dCreate_CompCol_Matrix(&A,n,n,nnz,a,asub,xa,SLU_NC,SLU_D,SLU_GE);
    nrhs = 1;
    if ( !(rhs = doubleMalloc(m * nrhs)) ) ABORT("Malloc fails for rhs[].");
    for (int i = 0; i < m; ++i) rhs[i] = 1.0;
    dCreate_Dense_Matrix(&B, n, nrhs, rhs, m, SLU_DN, SLU_D, SLU_GE);
    if ( !(perm_r = intMalloc(m)) ) ABORT("Malloc fails for perm_r[].");
    if ( !(perm_c = intMalloc(m)) ) ABORT("Malloc fails for perm_c[].");
    
    set_default_options(&options);
    options.ColPerm = NATURAL;
    StatInit(&stat);
    dgssv(&options, &A, perm_c, perm_r, &LO, &U, &B, &stat, &info);
    dPrint_CompCol_Matrix("A", &A);
    dPrint_CompCol_Matrix("U", &U);
    dPrint_SuperNode_Matrix("L", &LO);
    print_int_vec("\nperm_r", m, perm_r);
    SUPERLU_FREE (rhs);
    SUPERLU_FREE (perm_r);
    SUPERLU_FREE (perm_c);
    
    Destroy_CompCol_Matrix(&A);
    Destroy_SuperMatrix_Store(&B);
    Destroy_SuperNode_Matrix(&LO);
    Destroy_CompCol_Matrix(&U);
    StatFree(&stat);

    return(0);     
    }

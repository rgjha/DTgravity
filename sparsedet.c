#include "grav.h"
#include "slu_ddefs.h"
void sparsedet(void){

    SuperMatrix A,B;
    SuperMatrix LO,U;
    double *rhs;
    int *perm_r,*perm_c;
    int nrhs,info,nnz,permc_spec;
    superlu_options_t options;
    SuperLUStat_t stat;

    SCformat *Lstore;
    double *Lval,**test,det,dot, **unitary;
    double *diagU, *dblock;
    int fsupc, nsupr, nsupc, luptr;
    int i2, k2, nsupers,m,n,count,NNZ;
    
    static FILE *f;
    static int first_time=1;
    int *r,*c,*ilap,*jlap,num,*jtmp,*itmp;
    double *spi,*lap,*tmp, *q;

    if(first_time){
        f=fopen("det","a");
        first_time=0;
    }

    (void)printf("Node number %d\n",node_number);
    (void)printf("Simplex_number %d\n",simplex_number);
    n=node_number;
    m=n;
    if(D==2) NNZ=NNZDm2;
    if(D==3) NNZ=NNZDm3;
    if(D==4) NNZ=NNZDm4;
    
    spi=vector(0,NNZ-1);
    c=ivector(0,NNZ-1);
    r=ivector(0,n);
    
    tmp=vector(0,Z1*NNZ-1);
    jtmp=ivector(0,Z1*NNZ-1);
    itmp=ivector(0,n);

  if(D==4){
    
    r[0]=0;num=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<Dm4num;k++){
            if(colL[k]==i) {
            c[num]=rowL[k];
            spi[num]=sL[k];
            num++;
            }
        }
        r[i+1]=num;
    }
  }

    if(D==3){
        r[0]=0;num=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<Dm3num;k++){
                if(colK[k]==i) {c[num]=rowK[k];spi[num]=sK[k];num++;}
            }
            r[i+1]=num;
            
        }}

    if(D==2){
        r[0]=0;num=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<Dm2num;k++){
                if(colJ[k]==i) {c[num]=rowJ[k];spi[num]=sJ[k];num++;}
            }
            r[i+1]=num;
            
        }}

    (void)printf("Number of nonzeroes found in node incidence matrix %d\n",num);fflush(stdout);
    
    // Multiply sparse d and d^T
    nnz=0;
    dot=0.0; count=0;
    itmp[0]=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            dot=0.0; count=0;
            for(int k=r[i];k<r[i+1];k++){
                for(int l=r[j];l<r[j+1];l++){
                    if(c[k]==c[l]){
                        dot+=spi[k]*spi[l];
                        count++;}}}

            if(count!=0){
                tmp[nnz]=dot ;
                jtmp[nnz]=j;
                nnz++;
            }
            
        }
        itmp[i+1]=nnz;
        
    }
    (void)printf("Number of nonzeroes in sparse node laplacian %d\n",nnz);fflush(stdout);
   
    // Re-malloc with exactly correct number of nonzeroes
    lap=vector(0,nnz-1);
    jlap=ivector(0,nnz-1);
    ilap=ivector(0,n);
    
    // Free sparse structures
    
    free_vector(spi,0,NNZ-1);
    free_ivector(c,0,NNZ-1);
    free_ivector(r,0,n);
    
    for(int i=0;i<=n;i++){
        ilap[i]=itmp[i];}  // How many non-zeros 
    for(int i=0;i<nnz;i++){
        lap[i]=tmp[i];  // Value 
        jlap[i]=jtmp[i];}  // Index of zeros 

    // Add mass term
    double temp = 0.0; 
    for(int i=0;i<n;i++){
      for(int j=ilap[i];j<ilap[i+1];j++){

        if(jlap[j]==i){
        lap[j]=lap[j] + MASS*MASS ; 
	//(void)printf("DIAGONAL IS  is %lg\n",lap[j] );
        temp=temp+log(fabs(lap[j]));

        }
      }
    }


    (void)printf("log of product of diags for NODE is %lg\n", temp );
    free_vector(tmp,0,Z1*NNZ-1);
    free_ivector(jtmp,0,Z1*NNZ-1);
    free_ivector(itmp,0,n);
    
    test=matrix(0,n-1,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            test[i][j]=0.0;}}  // Zero all 
    for(int i=0;i<n;i++){
        for(int k=ilap[i];k<ilap[i+1];k++){  // All non-zeros 
            test[i][jlap[k]]=lap[k];
        }
    }
    printf("Reconstructed node Laplacian\n");


    // now factorize laplacian
    q=vector(0,n-1);
    
    for(int i=0;i<n;i++){
        for(int j=ilap[i];j<ilap[i+1];j++){
            if(jlap[j]==i) {
              q[i]=lap[j];
            }
        }}
    for(int i=0;i<n;i++){
        for(int j=ilap[i];j<ilap[i+1];j++){
           lap[j]=lap[j]/sqrt(q[i]*q[jlap[j]]);
        }}



dCreate_CompCol_Matrix(&A,n,n,nnz,lap,jlap,ilap,SLU_NC,SLU_D,SLU_GE);
nrhs = 1;

if ( !(rhs = doubleMalloc(n * nrhs)) ) ABORT("Malloc fails for rhs[].");
for (int i = 0; i < n; ++i) rhs[i] = 1.0;
dCreate_Dense_Matrix(&B, n, nrhs, rhs, n, SLU_DN, SLU_D, SLU_GE);
if ( !(perm_r = intMalloc(n)) ) ABORT("Malloc fails for perm_r[].");
if ( !(perm_c = intMalloc(n)) ) ABORT("Malloc fails for perm_c[].");

set_default_options(&options);
options.SymmetricMode = YES;
StatInit(&stat);
dgssv(&options, &A, perm_c, perm_r, &LO, &U, &B, &stat, &info);

if(info!=0){(void)printf("Error in super LU\n");}

// Check solution
    if(DEBUG){double *b;
  int i;
  int j;
  int k;
 
  b = vector(0,m-1);
  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }
  for ( j = 0; j < m; j++ )
  {
    for ( k = ilap[j]; k < ilap[j+1]; k++ )
    {
        i = jlap[k];
      b[i] = b[i] + lap[k] * rhs[j];
    }
  }
    }

    det=0.0;
    Lstore = (SCformat *)LO.Store;
    Lval = (double *)Lstore->nzval;
    nsupers = Lstore->nsuper + 1;

        //Get the diagonal entries of the U matrix
        //Allocate store for the entries
        if ( !(diagU = SUPERLU_MALLOC( m * sizeof(SuperMatrix) )) )
         ABORT("Malloc fails for diagU[].");
        for(k2=0; k2< nsupers; ++k2)
         {
          fsupc = L_FST_SUPC(k2);
          nsupc = L_FST_SUPC(k2+1) - fsupc;
          nsupr = L_SUB_START(fsupc+1) - L_SUB_START(fsupc);
          luptr = L_NZ_START(fsupc);

          dblock = &diagU[fsupc];
          for(i2 = 0; i2 < nsupc; ++i2)
           {
            dblock[i2] = Lval[luptr];
            luptr += nsupr + 1;
           }
         }
                  
        //Now multiply the diagonal terms to get the determinant
        //http://oomph-lib.maths.man.ac.uk/doc/the_data_structure/html/superlu_8c_source.html //
         for(int i=0;i<n;i++){
         det=det+log(fabs(diagU[i]));
         }
    
    printf("------------------------------------ \n");
    (void)printf("Super LU node det is %lg\n",det);
    double DETERM = find_det(test,node_number);
    printf("LAPACK node det is %.6g \n", DETERM);
    printf("------------------------------------ \n");
    
	/* Free un-wanted storage */
SUPERLU_FREE(diagU);
SUPERLU_FREE (rhs);
SUPERLU_FREE (perm_r);
SUPERLU_FREE (perm_c);

Destroy_CompCol_Matrix(&A);
Destroy_SuperMatrix_Store(&B);
Destroy_SuperNode_Matrix(&LO);
Destroy_CompCol_Matrix(&U);
StatFree(&stat);
    
    
    (void)fprintf(f,"%lg ",det);
    
    // Now construct Laplacian for simplex
    
      n=simplex_number;
      m=n;
      NNZ=Dm1num;
      spi=vector(0,NNZ-1);
      c=ivector(0,NNZ-1);
      r=ivector(0,n);
    
      tmp=vector(0,Z1*NNZ-1);
      jtmp=ivector(0,Z1*NNZ-1);
      itmp=ivector(0,n);
    
     r[0]=0;num=0;
     for(int i=0;i<n;i++){
     for(int k=0;k<NNZ;k++){
     if(rowI[k]==i) {c[num]=colI[k];spi[num]=sI[k];num++;}
     }
     r[i+1]=num;
     }
    
    (void)printf("Number of nonzeroes found in simplex incidence matrix %d\n",num);fflush(stdout);
    
    // Multiply sparse d and d^T
     nnz=0;
     dot=0.0;count=0;
     itmp[0]=0;
     
     for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
     
     dot=0.0; count=0;
     for(int k=r[i];k<r[i+1];k++){
     for(int l=r[j];l<r[j+1];l++){
     if(c[k]==c[l]){
     dot+=spi[k]*spi[l];
     count++;}}}
     
     if(count!=0){
     tmp[nnz]=dot;
     jtmp[nnz]=j;
     nnz++;
     }
     
     }
     itmp[i+1]=nnz;
     
     }
    
     (void)printf("Number of nonzeroes in sparse Simplex Laplacian %d\n",nnz);fflush(stdout);
    
    // Remalloc with exactly correct number of nonzeroes
     lap=vector(0,nnz-1);
     jlap=ivector(0,nnz-1);
     ilap=ivector(0,n);
     
     // Free sparse structures
     
     free_vector(spi,0,NNZ-1);
     free_ivector(c,0,NNZ-1);
     free_ivector(r,0,n);
     
     for(int i=0;i<=n;i++){
     ilap[i]=itmp[i];}
     for(int i=0;i<nnz;i++){
     lap[i]=tmp[i];
     jlap[i]=jtmp[i];}
    
    

     for(int i=0;i<n;i++){
      
      for(int j=ilap[i];j<ilap[i+1];j++){
      
        if(jlap[j]==i){
        lap[j]=lap[j]+ MASS*MASS;
        }
      }
    }
    
     free_vector(tmp,0,Z1*NNZ-1);
     free_ivector(jtmp,0,Z1*NNZ-1);
     free_ivector(itmp,0,n);
    
    test=matrix(0,m-1,0,m-1);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            test[i][j]=0.0;}}
    for(int i=0;i<m;i++){
        for(int k=ilap[i];k<ilap[i+1];k++){
            test[i][jlap[k]]=lap[k];
        }
    }
    printf("Reconstructed simplex Laplacian\n");
    
    dCreate_CompCol_Matrix(&A,n,n,nnz,lap,jlap,ilap,SLU_NC,SLU_D,SLU_GE);
    nrhs = 1;
    
    if ( !(rhs = doubleMalloc(n * nrhs)) ) ABORT("Malloc fails for rhs[].");
    for (int i = 0; i < n; ++i) rhs[i] = 1.0;
    dCreate_Dense_Matrix(&B, n, nrhs, rhs, n, SLU_DN, SLU_D, SLU_GE);
    if ( !(perm_r = intMalloc(n)) ) ABORT("Malloc fails for perm_r[].");
    if ( !(perm_c = intMalloc(n)) ) ABORT("Malloc fails for perm_c[].");
    
    set_default_options(&options);
    options.SymmetricMode = YES;
    StatInit(&stat);
    dgssv(&options, &A, perm_c, perm_r, &LO, &U, &B, &stat, &info);
    
    if(info!=0){(void)printf("Error in super LU\n");}

    // Check solution
    if(DEBUG){double *b;
        int i;
        int j;
        int k;
        
        b = vector(0,m-1);
        for ( i = 0; i < m; i++ )
        {
            b[i] = 0.0;
        }
        for ( j = 0; j < m; j++ )
        {
            for ( k = ilap[j]; k < ilap[j+1]; k++ )
            {
                i = jlap[k];
                b[i] = b[i] + lap[k] * rhs[j];
            }
        }
    }
    
    det=0.0;
  
    Lstore = (SCformat *)LO.Store;
    Lval = (double *)Lstore->nzval;
    nsupers = Lstore->nsuper + 1;
    
    if ( !(diagU = SUPERLU_MALLOC( m * sizeof(SuperMatrix) )) )
        ABORT("Malloc fails for diagU[].");
    
    for(k2=0; k2< nsupers; ++k2)
    {
        fsupc = L_FST_SUPC(k2);
        nsupc = L_FST_SUPC(k2+1) - fsupc;
        nsupr = L_SUB_START(fsupc+1) - L_SUB_START(fsupc);
        luptr = L_NZ_START(fsupc);
        
        dblock = &diagU[fsupc];
        for(i2 = 0; i2 < nsupc; ++i2)
        {
            dblock[i2] = Lval[luptr];
            luptr += nsupr + 1;
        }
    }

    for(int i=0;i<n;i++){
        det=det+log(fabs(diagU[i]));
    }
    
    printf("------------------------------------ \n");
    (void)printf("super LU simplex det is %lg\n",det);
    DETERM = find_det(test, simplex_number);
    printf("LAPACK simplex det is %.6g \n", DETERM);
    printf("------------------------------------ \n");
    
    /* Free storage */
    SUPERLU_FREE(diagU);
    SUPERLU_FREE (rhs);
    SUPERLU_FREE (perm_r);
    SUPERLU_FREE (perm_c);
    
    Destroy_CompCol_Matrix(&A);
    Destroy_SuperMatrix_Store(&B);
    Destroy_SuperNode_Matrix(&LO);
    Destroy_CompCol_Matrix(&U);
    StatFree(&stat);
    
    (void)fprintf(f,"%lg\n",det);
    fflush(f);
}

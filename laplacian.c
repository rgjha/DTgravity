//
//  laplacian.c
//  
//
//  Created by smcatter on 3/12/18.
//
//

#include "grav.h"


void laplacian(void){
    double **Dm0,**Dm1,**Dm2,**Dm3,**Dm4;
   
    Dm1=matrix(0,DminusOneNumber-1,0,DminusOneNumber-1);
    Dm0=matrix(0,simplex_number-1,0,simplex_number-1);
    if((D==2)||(D==3)||(D==4)){
        Dm2=matrix(0,DminusTwoNumber-1,0,DminusTwoNumber-1);}
    if(D==3|| (D==4)){
        Dm3=matrix(0,DminusThreeNumber-1,0,DminusThreeNumber-1);}
    if(D==4){
        Dm4=matrix(0,DminusFourNumber-1,0,DminusFourNumber-1);}
    
    /*(void)printf("I(D,D-1) is\n");
     for(int i=0;i<simplex_number;i++){
     for(int j=0;j<DminusOneNumber;j++){
     (void)printf("%lg ",I[i][j]);
     }
     (void)printf("\n");
     }


     (void)printf("ITRANS(D-1,D) is\n");
     for(int i=0;i<DminusOneNumber;i++){
     for(int j=0;j<simplex_number;j++){
     (void)printf("%lg ",ITRANS[i][j]);
     }
     (void)printf("\n");
     }
     
     (void)printf("J(D-1,D-2) is \n");
     for(int i=0;i<DminusOneNumber;i++){
     for(int j=0;j<DminusTwoNumber;j++){
     (void)printf("%lg ",J[i][j]);
     }
     (void)printf("\n");
     }

     (void)printf("JTRANS(D-2,D-1) is \n");
     for(int i=0;i<DminusTwoNumber;i++){
     for(int j=0;j<DminusOneNumber;j++){
     (void)printf("%lg ",JTRANS[i][j]);
     }
     (void)printf("\n");
     }
     
     (void)printf("\n");
     (void)printf("K(D-2,D-3) is \n");
     for(int i=0;i<DminusTwoNumber;i++){
     for(int j=0;j<DminusThreeNumber;j++){
     (void)printf("%lg ",K[i][j]);
     }
     (void)printf("\n");
     }
     
     (void)printf("KTRANS(D-3,D-2) is \n");
     for(int i=0;i<DminusThreeNumber;i++){
     for(int j=0;j<DminusTwoNumber;j++){
     (void)printf("%lg ",KTRANS[i][j]);
     }
     (void)printf("\n");
     }
     (void)printf("\n");
     
    
    (void)printf("\n");
    (void)printf("L(D-3,D-4) is \n");
    for(int i=0;i<DminusThreeNumber;i++){
        for(int j=0;j<DminusFourNumber;j++){
            (void)printf("%lg ",L[i][j]);
        }
        (void)printf("\n");
    }
    
    (void)printf("LTRANS(D-4,D-3) is \n");
    for(int i=0;i<DminusFourNumber;i++){
        for(int j=0;j<DminusThreeNumber;j++){
            (void)printf("%lg ",LTRANS[i][j]);
        }
        (void)printf("\n");
    }
    (void)printf("\n");
    
*/

    // form Dm0 laplacian
if(DEBUG)(void)printf("D laplacian\n");
    for(int i=0;i<simplex_number;i++){
        for(int j=0;j<simplex_number;j++){
            Dm0[i][j]=0.0;
            for(int k=0;k<DminusOneNumber;k++){
                Dm0[i][j]=Dm0[i][j]+I[i][k]*ITRANS[k][j];}
if(DEBUG)(void)printf("%lg ",Dm0[i][j]);
        }
if(DEBUG)(void)printf("\n");
        Dm0[i][i]=Dm0[i][i]+MASS*MASS;
    }
    
    // form Dm1 laplacian
if(DEBUG)(void)printf("D-1 laplacian \n");
    for(int i=0;i<DminusOneNumber;i++){
        for(int j=0;j<DminusOneNumber;j++){
            Dm1[i][j]=0.0;
            
            for(int k=0;k<simplex_number;k++){
                Dm1[i][j]=Dm1[i][j]+ITRANS[i][k]*I[k][j];}
            for(int k=0;k<DminusTwoNumber;k++){
                Dm1[i][j]=Dm1[i][j]+J[i][k]*JTRANS[k][j];}
            
if(DEBUG)(void)printf("%lg ",Dm1[i][j]);
        }
if(DEBUG)(void)printf("\n");
        Dm1[i][i]=Dm1[i][i]+MASS*MASS;
    }
    
    // form Dm2 laplacian
    if((D==2)||(D==3)||(D==4)){
if(DEBUG)(void)printf("D-2 laplacian\n");
        for(int i=0;i<DminusTwoNumber;i++){
            for(int j=0;j<DminusTwoNumber;j++){
                Dm2[i][j]=0.0;
                for(int k=0;k<DminusOneNumber;k++){
                    Dm2[i][j]=Dm2[i][j]+JTRANS[i][k]*J[k][j];
                }
                if(D==3||(D==4)){
                    for(int k=0;k<DminusThreeNumber;k++){
                        Dm2[i][j]=Dm2[i][j]+K[i][k]*KTRANS[k][j];}}
  if(DEBUG)(void)printf("%lg ",Dm2[i][j]);
            }
  if(DEBUG)(void)printf("\n");
            Dm2[i][i]=Dm2[i][i]+MASS*MASS;
        }
    }
    
    // form Dm3 laplacian
    if(D==3||(D==4)){
   if(DEBUG)(void)printf("D-3 laplacian\n");
        for(int i=0;i<DminusThreeNumber;i++){
            for(int j=0;j<DminusThreeNumber;j++){
                Dm3[i][j]=0.0;
                for(int k=0;k<DminusTwoNumber;k++){
                    Dm3[i][j]=Dm3[i][j]+KTRANS[i][k]*K[k][j];}
                if(D==4){
                    for(int k=0;k<DminusFourNumber;k++){
                        Dm3[i][j]=Dm3[i][j]+L[i][k]*LTRANS[k][j];}
                }
    if(DEBUG)(void)printf("%lg ",Dm3[i][j]);
            }
      if(DEBUG)(void)printf("\n");
            Dm3[i][i]=Dm3[i][i]+MASS*MASS;
        }
    }
    // form Dm4 laplacian
    if(D==4){
       if(DEBUG)(void)printf("D-4 laplacian\n");
        for(int i=0;i<DminusFourNumber;i++){
            for(int j=0;j<DminusFourNumber;j++){
             Dm4[i][j]=0.0;
                for(int k=0;k<DminusThreeNumber;k++){
                    Dm4[i][j]=Dm4[i][j]+LTRANS[i][k]*L[k][j];}
      if(DEBUG)(void)printf("%lg ",Dm4[i][j]);
            }
      if(DEBUG)(void)printf("\n");
            Dm4[i][i]=Dm4[i][i]+MASS*MASS;
        }
    }
    
    
    // compute dets
    double d[DPLUS];
    
    d[1]=calcdet(Dm1,DminusOneNumber);
    //(void)printf("D1 det is %lg\n",d1);
    d[0]=calcdet(Dm0,simplex_number);
    //(void)printf("D0 det is %lg\n",d[0]);
    
    if((D==2)||(D==3)||(D==4)){
        d[2]=calcdet(Dm2,DminusTwoNumber);
        //(void)printf("D2 det is %lg\n",d2);
    }
    
    if((D==3)||(D==4)){
        d[3]=calcdet(Dm3,DminusThreeNumber);
    }
    
    if(D==4){
        d[4]=calcdet(Dm4,DminusFourNumber);
        (void)printf("link number is %d\n",DminusThreeNumber);
        (void)printf("Dm4 det is %lg\n",d[4]);
    }
    
    
    free_matrix(Dm0,0,simplex_number-1,0,simplex_number-1);
    free_matrix(Dm1,0,DminusOneNumber-1,0,DminusOneNumber-1);
    if((D==2)||(D==3)||(D==4)){
        free_matrix(Dm2,0,DminusTwoNumber-1,0,DminusTwoNumber-1);}
    if(D==3||(D==4)){
        free_matrix(Dm3,0,DminusThreeNumber-1,0,DminusThreeNumber-1);}
    if(D==4){
        free_matrix(Dm4,0,DminusFourNumber-1,0,DminusFourNumber-1);}}


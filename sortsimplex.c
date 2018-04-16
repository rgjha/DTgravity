//
//  sortsimplex.c
//  
//
//  Created by Simon Catterall on 2/22/18.
//
//

#include "grav.h"

void sortsimplex(PSIMPLEX s){
    int i,c,swp;
    int p[DPLUS];
    PSIMPLEX n[DPLUS],swp2;

  //  (void)printf("in sortsimplex\n");
    
    for(i=0;i<DPLUS;i++){
    p[i]=s->vertex[i];
    n[i]=s->neighbour[i];
//    printf("vertex in sortsimplex %d\n",p[i]);
}
 //   fflush(stdout);
 
    do{
        c=0;
        for(i=0;i<D;i++){
        
           if(p[i+1]<p[i]) {
           swp=p[i+1];
           swp2=n[i+1];
           p[i+1]=p[i];
           n[i+1]=n[i];
           p[i]=swp;
           n[i]=swp2;
           c++;}
           
    }
    }while(c>0);
    for(i=0;i<DPLUS;i++){
    s->vertex[i]=p[i];
    s->neighbour[i]=n[i];}

    return;
}


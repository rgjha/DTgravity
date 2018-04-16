//
//
//  Created by smcatter on 2/18/18.
//
//

#include "grav.h"


void boundary(int P, int v[DPLUS], int i, int vm[D]){
    
    int j,k=0;
    for(j=0;j<(P+1);j++){
       
            if(j==i) continue;
            vm[k]=v[j];
            k++;
        }
    return;
}


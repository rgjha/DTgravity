#include "grav.h"

/* averages quantites and writes to file every BLOCK sweeps */

void block_obs(void){
int i;

for(i=0;i<(INCVOL);i++)
len_dist[i]/=(double)(BLOCK*HITS)/(double)GAP;

for(i=0;i<INCVOL;i++)
if(len_dist[i]>0){
fprintf(fp4,"%d %lg\n",i,len_dist[i]);}
fflush(fp4);

for(i=0;i<INCVOL;i++){
len_dist[i]=0.0;
}

return;
}

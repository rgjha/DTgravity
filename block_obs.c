#include "grav.h"

/* averages quantites and writes to file every BLOCK sweeps */

void block_obs(void){
int i;

printf("Writing blocked observables\n");
fflush(stdout);

for(i=0;i<(INCVOL);i++)
len_dist[i]/=(double)(BLOCK*HITS)/(double)GAP;

for(i=0;i<VOL;i++){
len[i]/=(double)(BLOCK*HITS)/(double)GAP;
}

for(i=0;i<MAXLEN;i++){
fprintf(fp4,"%d %lg\n",i,len_dist[i]);}
fflush(fp4);

for(i=0;i<MAXLEN;i++){
fprintf(fp5,"%d %lg\n",i,len[i]);}
fflush(fp5);

for(i=1;i<STEPS;i++){
prob[i]/=(double)(BLOCK*HITS)/(double)GAP;
if(prob[i]>0){
fprintf(fp3,"%lg %lg\n",log(i+1.0),log(prob[i]));}
else{
fprintf(fp3,"%lg %lg\n",log(i+1.0),1.0*VOL);}
}
fflush(fp3);
// +1 needed to fix counter - min number of steps to return is 2
for(i=1;i<STEPS;i++){
dprob[i]/=(double)(BLOCK*HITS)/(double)GAP;
if(dprob[i]>0){
fprintf(fp6,"%lg %lg\n",log(i+1.0),log(dprob[i]));}
else{
fprintf(fp6,"%lg %lg\n",log(i+1.0),1.0*VOL);}
}
fflush(fp6);

for(i=0;i<INCVOL;i++){
len_dist[i]=0.0;}
for(i=0;i<VOL;i++){
len[i]=0.0;
}

for(i=0;i<STEPS;i++){
prob[i]=0.0;dprob[i]=0.0;}

return;
}

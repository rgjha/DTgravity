#include "grav.h"

double mean_dist(void)
{
int  i,j,k,number_returns=0;
int direct_returns=0;
PSIMPLEX temp;
double dist;
int returns[STEPS],distance[INCVOL],direct_dist[VOL],dreturns[STEPS];

/* compress data structures */

tidy();

/* Use several starting points on lattice and average */

dist=0.0;
for(i=0;i<VOL;i++){
direct_dist[i]=0;}
for(i=0;i<INCVOL;i++){
distance[i]=0;}

for(j=0;j<HITS;j++)
{

i=(int)(my_random()*simplex_number);
temp=simplex_point[i];
if(temp->label!=i){printf("Error in mean_dist ");exit(1);}
//printf("Calling geodesic/randomwalk functions\n");fflush(stdout);

geodesic(temp,distance);
//printf("first bit\n");fflush(stdout);

direct_geodesic(temp,direct_dist);
//printf("got to here ok\n");fflush(stdout);
number_returns=randomwalk(temp,returns);
direct_returns=direct_randomwalk(temp,dreturns);

//printf("number of returns %d\n",direct_returns);

for(k=0;k<number_returns;k++){
prob[returns[k]]+=1.0;}

for(k=0;k<direct_returns;k++){
dprob[dreturns[k]]+=1.0;}

for(k=0;k<simplex_number;k++){
len_dist[distance[k]]+=1.0;
dist+=distance[k];
}

for(k=0;k<VOL;k++){
if(direct_dist[k]!=(-1)){
//printf("node %d has distance %d\n",k,direct_dist[k]);
len[direct_dist[k]]+=1.0;}
}

//for(i=0;i<MAXLEN;i++){
//printf("dist %d dlen %lg\n",i,len[i]);}

}


dist/=(simplex_number*HITS);

return(dist);
}

#include "grav.h"
double mean_dist(void)
{
int  i,j,k,distance[INCVOL];
PSIMPLEX temp;
double dist;

/* compress data structures */

tidy();

/* Use several starting points on lattice and average */

dist=0.0;

for(j=0;j<HITS;j++)
{

i=(int )(my_random()*simplex_number);
temp=simplex_point[i];
if(temp->label!=i){printf("Error in mean_dist ");exit(1);}

geodesic(temp,distance);

for(k=0;k<simplex_number;k++){
len_dist[distance[k]]+=1.0;
dist+=distance[k];
}

}


dist/=(simplex_number*HITS);

return(dist);
}

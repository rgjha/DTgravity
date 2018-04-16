#include "grav.h"
/* opens all the data files and zeroes measure bins */

void init(void)
{
int  i;


for(i=0;i<INCVOL;i++){
len_dist[i]=0.0;
}

for(i=0;i<STEPS;i++){
prob[i]=0.0;
dprob[i]=0.0;
}

for(i=0;i<VOL;i++){
len[i]=0.0;
}

for(i=0;i<DPLUS;i++)
{
try_subsimplex[i]=0;
go_subsimplex[i]=0;
manifold_subsimplex[i]=0;
legal_subsimplex[i]=0;
}

real_simplex=0.0;
real_node=0.0;
average_distance=0.0;
manifold_check=0.0;
max_point=0;


return;
}

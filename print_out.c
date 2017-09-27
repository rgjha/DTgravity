#include "grav.h"
/* writes some results to output stream */

void print_out(void)
{
int  i,dummy;

printf("\nResults :");

real_simplex=real_simplex/number_measure;
real_node=real_node/number_measure;
average_distance=average_distance/number_measure;
max_point=max_point/(SWEEPS);

dummy=0.0;
for(i=0;i<DPLUS;i++)
dummy+=(double)legal_subsimplex[i];
manifold_check/=dummy;
manifold_check*=VOL;

printf("\nAverage number of simplices %lg ",real_simplex);
printf("\nAverage number of nodes %lg ",real_node);
printf("\nAverage mean distance %lg ",average_distance);
printf("\nAverage maximum pointer number %d ",max_point);
printf("\nAverage number of simplices in manifold check %lg ",manifold_check);
printf("\n ");

printf("\nSubsimplex Moves ");
for(i=0;i<DPLUS;i++)
{
printf("\n %d subsimplices : ",i);
printf("\nNumber tried %d ",try_subsimplex[i]);
printf("\nNumber that are legal %d ",legal_subsimplex[i]);
printf("\nNumber that pass manifold test %d ",manifold_subsimplex[i]);
printf("\nNumber that pass Metropolis test %d ",go_subsimplex[i]);
printf("\n ");
}


fflush(stdout);

return;
}

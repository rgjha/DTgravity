#include "grav.h"
/* opens files, initialises variables */
/* prints out the run parameters */

void header(void)
{
long int seedval;

fp2=fopen("action","a");
fp3=fopen("spec","a");
fp4=fopen("len","a");
fp5=fopen("dlen","a");
fp6=fopen("dspec","a");

seedval=SEED;
srand48(seedval);

max_point=0;

printf("\nDimension %d ",D);
printf("\nVolume %d ",VOL);
printf("\nNode coupling %g ",kappa_0);
printf("\nSimplex coupling %g ",kappa_d);  // not an input !! 
printf("\nMeasure coupling %g ",BETA);
printf("\nFermion mass %g ", MASS);
printf("\nNumber of sweeps %d ",SWEEPS);
printf("\nThermalisation time %d ",THERMALISE);
printf("\nNumber of sweeps between KD tuning %d ",TUNE_COUPLING);
printf("\nGap between measurements %d ",GAP);
printf("\nTime between configuration dumps %d ",CHECKPOINT);
printf("\nVolume fluctuation parameter %d ", DV);
printf("\nRandom number seed %d",SEED);
printf("\nNumber of random walk steps %d",STEPS);
printf("\nSize of blocks %d",BLOCK);
printf("\nMax length for geodesics %d",MAXLEN);
printf("\nNumber of sources for geodesic/random walks %d",HITS);

fflush(stdout);


return;
}

#include "grav.h"
/* opens files, initialises variables */
/* prints out the run parameters */

void header(void)
{
long int seedval;

fp2=fopen("action","a");
fp4=fopen("len","a");

seedval=SEED;
srand48(seedval);

printf("\nDimension %d ",D);
printf("\nVolume %d ",VOL);
printf("\nNode coupling %g ",kappa_0);
printf("\nSimplex coupling %g ",kappa_d);
printf("\nCurvature squared coupling %g ",BETA);
printf("\nNumber of sweeps %d ",SWEEPS);
printf("\nThermalisation time %d ",THERMALISE);
printf("\nNumber of sweeps between KD tuning %d ",TUNE_COUPLING);
printf("\nGap between measurements %d ",GAP);
printf("\nTime between configuration dumps %d ",CHECKPOINT);
printf("\nVolume fluctuation parameter %d ", DV);
printf("\nRandom number seed %d\n",SEED);

fflush(stdout);


return;
}

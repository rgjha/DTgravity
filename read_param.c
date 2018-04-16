#include "grav.h"

void read_param(void){
FILE *f;

f=fopen("param","r");

printf("Reading parameters\n");
fflush(stdout);

fscanf(f,"%lg%lg%lg",&kappa_0,&BETA,&MASS);

fscanf(f,"%d%d%d%d%d%d%d%d",&THERMALISE,&SWEEPS,&GAP,
&TUNE_COUPLING,&READIN,&BLOCK,&SEED,&START_DUMP);

return;
}


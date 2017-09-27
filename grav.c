#include "grav.h"

int vertex_io[INCVOL][DPLUS],neighbour_io[INCVOL][DPLUS],stack_io[VOL];

/* simple global pointers and counters */

PNODE stack_head=NULL;
int simplex_number=0,pointer_number=0,node_number=0;

/* data structures */

PSIMPLEX simplex_point[BIGVOL];

/* measurements etc */

int  number_measure=0,legal_subsimplex[DPLUS],max_point;
int
try_subsimplex[DPLUS],manifold_subsimplex[DPLUS],go_subsimplex[DPLUS];
int  stack_count=0,vol_monitor=0,num_monitor=0,growing_vol;
double manifold_check;
double len_dist[INCVOL];

enum LOGIC grow;

/* simple observables -- number of nodes, simplices and size */
/* and variable versions of couplings */

double real_simplex=0.0,real_node=0.0,kappa_d=KD,average_distance;

/* file pointers ... */

FILE *fp2,*fp3,*fp4,*fp5,*fp6;

/* some global constanst for run */

int THERMALISE,SWEEPS,GAP,TUNE_COUPLING,READIN,BLOCK,SEED;
int START_DUMP;

double kappa_0,BETA;

/* driver for simplex Monte Carlo */

int main(int argc, char *argv[])
{
int  i,therm,iter,sweep;

read_param();
number_measure=START_DUMP;

(void)printf("measurement number %d\n",number_measure);

/* test to read in configuration or grow from scratch */

if(READIN)
read_in();
else
initial_config();

/* build lattice */

grow=YES;
while(growing_vol<VOL){
trial_change();

growing_vol+=D;}
grow=NO;

/* thermalise and output info on run */

header();

printf("\nThermalizing lattice\n");
fflush(stdout);

for(therm=1;therm<=THERMALISE;therm++)
{
for(iter=0;iter<VOL;iter++){
trial_change();

}

tidy();

num_monitor++;
vol_monitor+=simplex_number;

if(therm%TUNE_COUPLING==0)
shift_coupling();

if(therm%CHECKPOINT==0){

write_out();}

}


init();

/* sweep lattice outputting measurements every so often */

printf("Starting measurements\n");
for(sweep=1;sweep<=SWEEPS;sweep++)
{
tidy();

for(iter=0;iter<VOL;iter++)
trial_change();

if(sweep%GAP==0){
//printf("Sweep %d\n",sweep);

measure();
}

if(sweep%BLOCK==0)
block_obs();

/* checkpoint config regularly */

if(sweep%CHECKPOINT==0)
write_out();

}

/* finally dump final configuration and print some results */

write_out();
print_out();

return(0);

}

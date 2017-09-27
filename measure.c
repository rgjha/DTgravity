#include "grav.h"
/* routine coordinates all measurements */

void measure(void)
{
double dum,total_action;
static int calls=0;

real_simplex+=(double)simplex_number;
real_node+=(double)node_number;

total_action=-kappa_0*node_number;

dum=0.0;
dum=mean_dist();
average_distance+=dum;

fprintf(fp2,"%d %d %lg %lg\n",simplex_number,node_number,total_action,dum);
	     
fflush(fp2);
number_measure++;

calls++;

if(calls==BLOCK){
io_config(number_measure);
singular_vertex();
calls=0;
}

return;
}

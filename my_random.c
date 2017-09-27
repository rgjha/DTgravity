#include "grav.h"
int idum;
double my_random(void)
{
static int first_time=1;
if(first_time){
idum=-SEED;
first_time=0;
}
return(ran3(&idum));
}

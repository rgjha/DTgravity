#include "grav.h"
/* routine tunes simplex coupling to achieve preset average volume */

void shift_coupling(void)
{
double dum;

dum=((double)vol_monitor)/((double)num_monitor);

kappa_d=kappa_d+(2.0/(DV*DV))*(dum-VOL);

printf("\nNew coupling is %f ",kappa_d);
fflush(stdout);

vol_monitor=0;
num_monitor=0;

return;
}

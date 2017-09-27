#include "grav.h"
enum LOGIC metropolis(int  sub, int  a[DPLUSPLUS],
PSIMPLEX addresses[DPLUSPLUS])
{
double ds0,dsd,dummy,change;
enum LOGIC accept;
int j,k;

if(sub==0)

ds0=-kappa_0;

else if(sub==D)

ds0=kappa_0;

else

ds0=0.0;

dsd=kappa_d*(2*sub-D);

/* add restoring force to VOL */
if(!DEBUG)
dsd=dsd+(2*sub-D)*((2*sub-D)+2*(simplex_number-growing_vol))/(1.0*DV*DV);

dsd=dsd-ds0;

dsd=exp(dsd);

dsd=(1.0+(double)(2*sub-D)/(double)simplex_number)*dsd;

dsd=1.0/(1.0+dsd);

dummy=my_random()-dsd;

if(dummy<0.0)
accept=YES;

else
accept=NO;

if(grow==YES) 
accept=YES;

if(((simplex_number+2*sub-D)<MINVOL) || ((simplex_number+2*sub-D)>MAXVOL)) accept=NO;
return(accept);

}

#include "grav.h"
enum LOGIC metropolis(int  sub, int  a[DPLUSPLUS],
PSIMPLEX addresses[DPLUSPLUS])
{
double ds0,dsd,dsn,dummy,change;
enum LOGIC accept;
int i,j,k;
double tmp;

if(sub==0)

ds0=-kappa_0;

else if(sub==D)

ds0=kappa_0;

else

ds0=0.0;

dsd=kappa_d*(2*sub-D);

/* add restoring force to VOL */
dsd=dsd+(2*sub-D)*((2*sub-D)+2*(simplex_number-growing_vol))/(1.0*DV*DV);

dsd=dsd-ds0;

/* node order term */


dsn=0.0;
if(sub==D){
/* node insertion */
for(i=0;i<DPLUS;i++){
tmp=(double)find_order(a[i],addresses[DPLUS]);
dsn=dsn+log((tmp+D-1)/tmp);}
dsn=dsn+log((double)(DPLUS));
}

else if(sub==0){
/* node deletion */
for(i=1;i<DPLUS;i++){
tmp=(double)find_order(a[i],addresses[DPLUS]);
dsn=dsn+log((tmp-D+1)/tmp);}
tmp=(double)find_order(a[DPLUS],addresses[sub+1]);
dsn=dsn+log((tmp-D+1)/tmp);
dsn=dsn-log((double)(DPLUS));
}
else{
for(i=0;i<=sub;i++){
tmp=(double)find_order(a[i],addresses[DPLUS]);
dsn=dsn+log((tmp+2*sub-D-1)/tmp);}
for(i=sub+1;i<DPLUS;i++){
tmp=(double)find_order(a[i],addresses[DPLUS]);
dsn=dsn+log((tmp+2*sub-D+1)/tmp);}
tmp=(double)find_order(a[DPLUS],addresses[sub+1]);
dsn=dsn+log((tmp+2*sub-D+1)/tmp);
}

dsd=dsd-BETA*dsn;

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

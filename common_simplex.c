#include "grav.h"

/* routine takes a named subsimplex a[0]...a[n-1] and searches for it */
/* in a simplex pointed at by p. */
/* returns a vector containing the local indices of pointers to */
/* neighbouring simplices */
/* which share a face also encompassing this subsimplex */

void common_simplex(PSIMPLEX p, int  a[DPLUS], int  n, PSIMPLEX face[DPLUS]) 
{
int  i,j;
int  b[DPLUS],mask[DPLUS];
enum LOGIC found[DPLUS];


for(i=0;i<n;i++)
found[i]=NO;

/* find positions/local indices of subsimplex in this simplex */

for(i=0;i<n;i++)
for(j=0;j<DPLUS;j++)
if(p->vertex[j]==a[i]){b[i]=j;found[i]=YES;break;}

for(i=0;i<n;i++)
if(found[i]==NO){printf("\nError in common_simplex");exit(1);}

for(j=0;j<DPLUS;j++)
mask[j]=0;

for(j=0;j<n;j++)
mask[b[j]]=1;

j=0;
for(i=0;i<DPLUS;i++)
if(!mask[i]){face[j]=p->neighbour[i];j++;}

return;
}

#include "grav.h"

PSIMPLEX add_simplex(int  a[DPLUS])
{
PSIMPLEX temp;
int  i,count;

temp=(PSIMPLEX)malloc(sizeof(SIMPLEX));
count=0;

for(i=0;i<DPLUS;i++)
{
temp->vertex[i]=a[i];
temp->neighbour[i]=NULL;
count+=a[i];
}
temp->sum=count;

/* label simplex by its index in simplex_point */

temp->label=pointer_number;
temp->flag=NO;

/* assign new simplex to simplex_point array */

simplex_point[pointer_number]=temp;

simplex_number++;
pointer_number++;

return(temp);
}

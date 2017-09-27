#include "grav.h"
/* routine returns sum of vertices around the face conjugate to node i */

int  sum_face(PSIMPLEX p, int  i)
{
int  j,add;

add=0;
for(j=0;j<DPLUS;j++)
if(p->vertex[j]!=i) add+=(p->vertex[j]);

return(add);
}

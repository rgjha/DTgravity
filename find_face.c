#include "grav.h"
/* routine takes pointer to simplex and a vertex and returns local */
/* index to conjugate face */

int  find_face(PSIMPLEX p, int  a)
{
int  i;

for(i=0;i<DPLUS;i++)
if(p->vertex[i]==a) return(i);

printf("\nError in find_face ");
exit(1);

/* return dummy if get to here error */

return(VOL);
}

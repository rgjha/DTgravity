#include "grav.h"
/* frees storage and decrements simplex number */

void delete_simplex(PSIMPLEX p)
{

/* set pointer NULL indicating a 'dead' simplex */

simplex_point[p->label]=NULL;
free(p);
simplex_number--;
return;
}

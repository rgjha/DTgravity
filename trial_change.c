#include "grav.h"
/* driver for triangulation updates */

void trial_change(void)
{
PSIMPLEX simp,addresses[DPLUSPLUS];
int subsimplex,labels[DPLUSPLUS],i;
enum LOGIC legal_move,good_manifold,metro_accept;
/*printf("in trial_change \n");
fflush(stdout);*/

simp=select_simplex(&subsimplex);

legal_move=good_subsimplex(simp,subsimplex,labels,addresses);

if(legal_move==NO) return;

/*printf("Trying a %d-move with vertices:\n",subsimplex);
for(i=0;i<(subsimplex+1);i++)
printf("%d ",labels[i]);
printf("\n");
printf("extra vertices are:\n");
for(i=subsimplex+1;i<DPLUSPLUS;i++)
printf("%d ",labels[i]);
printf("\n");*/

legal_subsimplex[subsimplex]++;

good_manifold=allowed_move(simp,subsimplex,labels);

if(good_manifold==NO) return;

manifold_subsimplex[subsimplex]++;

metro_accept=metropolis(subsimplex,labels,addresses);

if(metro_accept==NO) return;

go_subsimplex[subsimplex]++;

update(labels,addresses,subsimplex);

return;

}

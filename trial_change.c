#include "grav.h"
/* driver for triangulation updates */

void trial_change(void)
{
PSIMPLEX simp,addresses[DPLUSPLUS];
int subsimplex,labels[DPLUSPLUS],i;
int q[INCVOL];
enum LOGIC legal_move,good_manifold,metro_accept;

simp=select_simplex(&subsimplex);

legal_move=good_subsimplex(simp,subsimplex,labels,addresses);

if(legal_move==NO) return;

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

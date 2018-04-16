#include "grav.h"
/* driver for triangulation updates */

void trial_change(void)
{
PSIMPLEX simp,addresses[DPLUSPLUS];
int subsimplex,labels[DPLUSPLUS],i;
int q[INCVOL];
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
printf("\n");
fflush(stdout);
*/

legal_subsimplex[subsimplex]++;

good_manifold=allowed_move(simp,subsimplex,labels);

if(good_manifold==NO) return;

manifold_subsimplex[subsimplex]++;

metro_accept=metropolis(subsimplex,labels,addresses);

if(metro_accept==NO) return;
/*
for(i=0;i<DPLUS;i++){
q[i]=find_order(labels[i],addresses[DPLUS]);}
if(subsimplex!=D){
q[DPLUS]=find_order(labels[DPLUS],addresses[subsimplex+1]);}
else{
q[DPLUS]=0;}

for(i=0;i<DPLUSPLUS;i++){
printf("before:vertex %d has coord %d\n",labels[i],q[i]);}
*/

go_subsimplex[subsimplex]++;

update(labels,addresses,subsimplex);

//printf("simplex pointer %d\n",pointer_number);

/*
for(i=1;i<DPLUSPLUS;i++){
q[i]=find_order(labels[i],addresses[0]);}
if(subsimplex!=0){
q[0]=find_order(labels[0],addresses[subsimplex]);}
else{
q[0]=0;}

for(i=0;i<DPLUSPLUS;i++){
printf("after:vertex %d has coord %d\n",labels[i],q[i]);}
*/

return;

}

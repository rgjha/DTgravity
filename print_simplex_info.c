#include "grav.h"
void print_simplex_info(PSIMPLEX p){
int i;
printf("simplex label is %d\n",p->label);
printf("vertices are\n");
for(i=0;i<DPLUS;i++)
printf("%d ",p->vertex[i]);
printf("\n");
printf("neighbor labels are\n");
for(i=0;i<DPLUS;i++)
printf("%d ",(p->neighbour[i])->label);
printf("\n");
fflush(stdout);
return;
}

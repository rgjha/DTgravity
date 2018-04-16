#include "grav.h"

void testorient(void){
PSIMPLEX p;
int c,i,j;
int v[DPLUS],vb[D];

for(c=0;c<simplex_number;c++){

p=simplex_point[c];

(void)printf("simplex %d with parity %d and vertices: ",p->label,p->parity);
for(i=0;i<DPLUS;i++){
(void)printf("%d ",p->vertex[i]);
v[i]=p->vertex[i];}
(void)printf("\n");

for(i=0;i<DPLUS;i++){
(void)printf("Boundary points: ");
boundary(D,v,i,vb);
for(j=0;j<D;j++){
(void)printf("%d ",vb[j]);}
(void)printf("\n");
(void)printf("orientation %d \n",PERM(i));
}


}

return;
}

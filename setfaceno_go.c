#include "grav.h"

void setfaceno_go(PSIMPLEX p,int hinge[D-1],int a){
int i, not_seen,k;
int b[D],opposing;
PSIMPLEX q;

for(i=0;i<(D-1);i++)
b[i]=hinge[i];
b[D-1]=a;

for(i=0;i<DPLUS;i++){
not_seen=1;
for(k=0;k<D;k++)
not_seen=(not_seen && (p->vertex[i]!=b[k]));
if(not_seen){
p->face_flag[i]=NO;
q=p->neighbour[i];
opposing=q->sum-sum_face(p,p->vertex[i]);
q->face_flag[find_face(q,opposing)]=NO;
}
}

return;
}


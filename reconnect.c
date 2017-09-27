#include "grav.h"
/* routine handles reconnection of new simplex pointers */

void reconnect(int  a[DPLUSPLUS], PSIMPLEX q[DPLUSPLUS], int  sub)
{
int  i,j,index_face1,index_face2,index_face3,opp;

/* loop over final state simplices */


for(i=0;i<sub+1;i++)
{

/* 'internal' faces first */


for(j=0;j<sub+1;j++)
if(j!=i)
{
index_face1=find_face(q[i],a[j]);
q[i]->neighbour[index_face1]=q[j];
}

/* now 'external' faces */


for(j=sub+1;j<DPLUSPLUS;j++)
{
index_face1=find_face(q[i],a[j]);
index_face2=find_face(q[j],a[i]);

/* have found external simplices involved reconnect outward pointers */

q[i]->neighbour[index_face1]=q[j]->neighbour[index_face2];

/* just adjust pointers on external simplices so they point at new ones */

opp=(q[i]->neighbour[index_face1])->sum-
sum_face(q[i],q[i]->vertex[index_face1]);

index_face3=find_face((q[i]->neighbour[index_face1]),opp);
(q[i]->neighbour[index_face1])->neighbour[index_face3]=q[i];

}

}
return;
}

#include "grav.h"
void initial_config(void)
{

int  i,j,index,tmp,dum[DPLUSPLUS],dum2[DPLUSPLUS];


for(i=0;i<DPLUSPLUS;i++)
dum[i]=i;

for(i=0;i<DPLUSPLUS;i++)
{
combo(dum,dum2,DPLUSPLUS,i);
simplex_point[i]=add_simplex(dum2);
}

/* now set up pointers loop over faces to simplices */

for(i=0;i<DPLUSPLUS;i++)
for(j=0;j<DPLUSPLUS;j++)
if(j!=i)
{
index=find_face(simplex_point[i],dum[j]);
simplex_point[i]->neighbour[index]=simplex_point[j];
}


for(i=0;i<DPLUSPLUS;i++)
for(j=i+1;j<DPLUSPLUS;j++){

do{
tmp=(int)(my_random()*DPLUSPLUS);}
while((tmp==i) || (tmp==j));

}


node_number=DPLUSPLUS;
growing_vol=DPLUSPLUS;

return;
}

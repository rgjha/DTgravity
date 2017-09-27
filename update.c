#include "grav.h"
/* coordinates addition of new simplices and removal of old ones */

void update(int  a[DPLUSPLUS], PSIMPLEX q[DPLUSPLUS], int  sub 
)
{
int  c[DPLUSPLUS],i,j,k,m,n,temp[DPLUS],o;

/* if subsimplex is node then save its label on the stack */


if(sub==0)
{
push(a[0]);
node_number--;
}

if(sub==D)
{
pop();
node_number++;
}

/* loop over new simplices */

for(i=0;i<sub+1;i++)
{
combo(a,c,sub+1,i);

for(j=sub+1;j<DPLUSPLUS;j++)
c[j-1]=a[j];

q[i]=add_simplex(c);
}

/* now reconnect pointers appropriately */

reconnect(a,q,sub);

/* delete old guys */

for(i=sub+1;i<DPLUSPLUS;i++)
delete_simplex(q[i]);


/* reassign simplex fields of 'external' links so as to point to
new simplices */

/* loop over new simplices */

for(i=0;i<(sub+1);i++){

/* get external faces */

for(j=sub;j<DPLUS;j++){

m=0;
for(k=0;k<DPLUS;k++)
if(k!=j){
temp[m]=q[i]->vertex[k];
m++;
}

}

}

return;
}

#include "grav.h"
/* takes simplex and order of subsimplex returns logical flag if legal move */
/* legal move is equivalent to being exactly d+1-i associated simplices. */
/* these subsimplex vertices occupy first i+1 entries in a[] */
/* other d-i 'external' vertices of original simplex occupy end of a[] */
/* also returns pointers to these d+1-i simplices */
/* and opposing vertex is placed at end of a[] */

enum LOGIC good_subsimplex(PSIMPLEX p, int  sub, int  a[DPLUSPLUS], 
			     PSIMPLEX isimplex[DPLUSPLUS])
{
int  i,add,temp,seen_already,opposing;
int  aind[DPLUS];

/* test whether subsimplex is simplex itself i.e node insertion move */


if(sub==D)
{

for(i=0;i<DPLUS;i++)
a[i]=p->vertex[i];

/* opposing vertex in this case is 'new' one obtained off stack */

if(stack_head==NULL)
a[DPLUS]=node_number;
else
a[DPLUS]=stack_head->name;

isimplex[DPLUS]=p;
return(YES);
}

/* otherwise generate subsimplex at random placing its indices in aind */

add=0;
while (add<sub+1)
{
temp=(int )(my_random()*DPLUS);
/* generate random index */

/* scan existing ones to see if already produced */

seen_already=NO;
for(i=0;i<add;i++)
if(temp==aind[i]) {seen_already=YES;break;}

if (!seen_already)
{
aind[add]=temp;
add++;
}
}


/* now create array of indices to d-i remaining vertices */

temp=add;
for(i=0;i<DPLUS;i++)
{
seen_already=NO;
for(add=0;add<sub+1;add++)
if(i==aind[add]) {seen_already=YES;break;}

if(!seen_already)
{
aind[temp]=i;
temp++;
}

}

if(temp!=(DPLUS)){printf("\nError in good_subsimplex");exit(1);}

/* now loop over all possible faces constucted to include this subsimplex */
/* by selecting d-i-1 out of the d-i b indices */

for(i=0;i<DPLUS;i++)
a[i]=p->vertex[aind[i]];

isimplex[sub+1]=(p->neighbour[aind[sub+1]]);
opposing=(isimplex[sub+1]->sum)-sum_face(p,a[sub+1]);

/* protect following loop if sub=D-1 */

if(sub<(D-1))
for(i=sub+2;i<DPLUS;i++)
{
isimplex[i]=(p->neighbour[aind[i]]);
if(((isimplex[i]->sum)-sum_face(p,a[i]))!=opposing)
return(NO);
}

a[DPLUS]=opposing;
isimplex[DPLUS]=p;
return(YES);

}

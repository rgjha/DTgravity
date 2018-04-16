#include "grav.h"
/* routine takes input pointer to simplex and generates a random walk*/
/* from a random node in that simplex along links marking any times */
/* at which the walk returns to the origin node */

int direct_randomwalk(PSIMPLEX p, int returns[STEPS])
{
int i,j,k,l,dupe,number,back,currentnode,nextnode,startnode;
PSIMPLEX current;
int new,dum[DPLUS],nn[VOL],num;
PSIMPLEX simp[VOL],list[INCVOL];

number=0;back=0;
current=p;
currentnode=p->vertex[(int)(my_random()*DPLUS)];
startnode=currentnode;

//printf("starting vertex is %d\n",startnode);
while(number<STEPS){

dum[0]=currentnode;
find_simplices(current,dum,1,list,&num);

/* make up a list of neighbor nodes along links */
l=0;
for(j=0;j<num;j++){
for(k=0;k<DPLUS;k++){
new=list[j]->vertex[k];

if(new!=currentnode){
dupe=0;

for(i=0;i<l;i++){
if(new==nn[i]){dupe=1;
break;}
}

if(!dupe){
nn[l]=new;simp[l]=list[j];l++;}
}

}}

/* select neighbor node at random */

//printf("number of neighbor nodes %d\n",l);
new=(int)(my_random()*l);
nextnode=nn[new];

//printf("nextnode is %d\n",nextnode);
if(nextnode==startnode){ 
//printf("back to origin after %d steps\n",number);
returns[back]=number;back++;}

current=simp[new];
currentnode=nextnode;
number++;}

return(back);
}

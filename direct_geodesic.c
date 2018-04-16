#include "grav.h"
/* routine takes input pointer to simplex and outputs array of */
/* distances from randomly chosen node in that simplex to all other nodes */
/* labeled by their distance along links from the starting node */

void direct_geodesic(PSIMPLEX p, int direct_dist[VOL])
{
int dum[DPLUS],number1,number2,i,j,k,dist;
int examine,new,num;
int array1[INCVOL],array2[INCVOL];
PSIMPLEX simp[INCVOL],newsimp[INCVOL],list[INCVOL];
int not_seen[VOL];

/* find all simplices that contain a given random node within initial simplex */
j=(int)(my_random()*DPLUS);
dum[0]=p->vertex[j];

for(i=0;i<VOL;i++){
not_seen[i]=1;
direct_dist[i]=-1;}

array1[0]=dum[0];
simp[0]=p;
number1=1;
not_seen[dum[0]]=0;
direct_dist[dum[0]]=0;
examine=1;

//(void)printf("initial node:%d\n",dum[0]);
dist=0;

while(number1>0)
{
number2=0;
dist++;
//printf("dist is %d\n",dist);fflush(stdout);

for(i=0;i<number1;i++){
/* take node off array1 list and find all simplices that contain it */
dum[0]=array1[i];
find_simplices(simp[i],dum,1,list,&num);

//printf("number of simps around node %d is %d\n",dum[0],num);

/* loop over all distinct nodes which form links with array1[i] */
for(j=0;j<num;j++){ 
for(k=0;k<DPLUS;k++){

new=list[j]->vertex[k];
if((new!=array1[i]) && (not_seen[new])){
//printf("found new vertex %d\n",new);
examine++;
array2[number2]=new;
direct_dist[new]=dist;
not_seen[new]=0;
newsimp[number2]=list[j];
number2++;
if(number2>INCVOL){printf("number2 out of range %d\n",number2);}

}

}
}
}

for(i=0;i<number2;i++){
array1[i]=array2[i];
simp[i]=newsimp[i];}

number1=number2;

}

//printf("Examined %d nodes out of %d total\n",examine,node_number);
//printf("largest dist is %d\n",dist);

return;
}

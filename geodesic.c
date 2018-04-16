#include "grav.h"
/* routine takes input pointer to simplex and outputs array of */
/* distances from given simplex to other simplices labelled by their */
/* position in simplex_point[] i.e the value of their member label */


void geodesic(PSIMPLEX p, int  distance[INCVOL])
{
int  number1,number2,search,i,j,dist;
PSIMPLEX array1[INCVOL],array2[INCVOL], examine[INCVOL];

array1[0]=p;
number1=1;
examine[0]=p;
search=1;
p->flag=YES;
distance[p->label]=0;

dist=0;

while(number1>0)
{
number2=0;
dist++;

for(i=0;i<number1;i++)
for(j=0;j<DPLUS;j++)
if((array1[i]->neighbour[j])->flag==NO)
{
array2[number2]=array1[i]->neighbour[j];
distance[array2[number2]->label]=dist;
array2[number2]->flag=YES;
examine[search]=array2[number2];
number2++;
search++;
}

for(i=0;i<number2;i++)
array1[i]=array2[i];

//printf("number2 is %d\n",number2);
fflush(stdout);

number1=number2;

}

//printf("search is %d simplex_number is %d\n",search, simplex_number);

/* finally set all flags back to NO */

for(i=0;i<search;i++){
examine[i]->flag=NO;}

return;
}

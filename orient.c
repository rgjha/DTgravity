#include "grav.h"
// function creates an oriented triangulation from an unoriented one


void orient(void)
{
int  number1,number2,search,i,j;
PSIMPLEX array1[MAXVOL],array2[MAXVOL];
int v[DPLUS],n[DPLUS],oppv,oppfaceindx;

//(void)printf("In orient()\n");

array1[0]=simplex_point[0];
array1[0]->flag=YES;
array1[0]->parity=1;
number1=1;
search=1;


//sort simplex vertices into ascending order

sortsimplex(array1[0]);

while(number1>0)
{
number2=0;

for(i=0;i<number1;i++)
for(j=0;j<DPLUS;j++)
if((array1[i]->neighbour[j])->flag==NO)
{
// grab neighbor across particular face
array2[number2]=array1[i]->neighbour[j];

// sort vertices of neighbor simplex
sortsimplex(array2[number2]);

//(void)printf("ordered vertices: ");
//for(int l=0;l<DPLUS;l++){
//(void)printf("%d ",array2[number2]->vertex[l]);}
//(void)printf("\n");
// find identity of vertex in 2nd simplex which shares that face
oppv=(array2[number2]->sum)-sum_face(array1[i],array1[i]->vertex[j]);
// find where it is stored in that 2nd simplex
oppfaceindx=find_face(array2[number2],oppv);

// make sure parity of neighbor simplex is such that face is stored with opposite orientation

array2[number2]->parity=-PERM(oppfaceindx)*(array1[i]->parity)*PERM(j);

// flag simplex as seen and move on ..
array2[number2]->flag=YES;
number2++;
search++;


}

for(i=0;i<number2;i++)
array1[i]=array2[i];

number1=number2;
}

//printf("search in orient is %d simplex_number is %d\n",search, simplex_number);

/* finally set all flags back to NO */

for(i=0;i<simplex_number;i++){
simplex_point[i]->flag=NO;}

return;
}

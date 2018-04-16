#include "grav.h"
// driver for computation of incidence matrices

void DminusOne_search(int, int[], int);

void kdoperator(void)
{
int  number1,number2,search,i,j,k;
PSIMPLEX array1[INCVOL],array2[INCVOL];
int v[DPLUS];
    
// compute numbers of p simplices
setupsimplex();

(void)printf("In KD op.\n");fflush(stdout);
array1[0]=simplex_point[0];
for(i=0;i<DPLUS;i++){
v[i]=array1[0]->vertex[i];}

DminusOne_search(array1[0]->label,v,array1[0]->parity);
    
array1[0]->flag=YES;
number1=1;
search=1;

while(number1>0)
{
number2=0;

for(i=0;i<number1;i++)
for(j=0;j<DPLUS;j++)
if((array1[i]->neighbour[j])->flag==NO)
{
// grab neighbor across particular face
array2[number2]=array1[i]->neighbour[j];
search++;

for(k=0;k<DPLUS;k++){
v[k]=array2[number2]->vertex[k];}
    
DminusOne_search(array2[number2]->label,v,array2[number2]->parity);
// flag simplex as seen and move on ..
array2[number2]->flag=YES;
number2++;
}


for(i=0;i<number2;i++)
array1[i]=array2[i];

number1=number2;
}

//(void)printf("search in KD op is %d simplex_number is %d\n",search, simplex_number);
    
    fflush(stdout);

/* finally set all flags back to NO and delete KD structures */

for(i=0;i<simplex_number;i++){
simplex_point[i]->flag=NO;}
DminusOne_search(-1,v,1);

//laplacian();
sparsedet();
    
cleanup();
return;
}

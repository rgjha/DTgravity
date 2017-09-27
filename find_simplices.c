#include "grav.h"
/* finds addresses of all simplices which share a given subsimplex */

void find_simplices(PSIMPLEX p, int  a[DPLUS], int  sub, 
                    PSIMPLEX s_near[VOL], int  *number){

PSIMPLEX array1[VOL],array2[VOL],near[DPLUS];
int i,j,k,num1,num2;


array1[0]=p;
num1=1;
s_near[0]=p;
*number=1;
s_near[0]->flag=YES;

while(num1>0){
num2=0;

for(i=0;i<num1;i++){
common_simplex(array1[i],a,sub,near);

for(j=0;j<DPLUS-sub;j++)
if(near[j]->flag==NO){
s_near[*number]=near[j];
array2[num2]=near[j];
/*printf("simplex %d found with vertices:\n",near[j]->label);
for(k=0;k<DPLUS;k++)
printf("%d ",near[j]->vertex[k]);
printf("\n");
fflush(stdout);*/

near[j]->flag=YES;
(*number)++;
num2++;
}
}

for(i=0;i<num2;i++)
array1[i]=array2[i];

num1=num2;

}

for(i=0;i<(*number);i++)
s_near[i]->flag=NO;

return;
}

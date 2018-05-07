#include "grav.h"
/* routine packs simplices into regular arrays and outputs config */

void io_config(int number_meas)
{
FILE *fp3;
PSIMPLEX temp;
PNODE temp2;
int  i,j,k,m;
char s[100];

(void)sprintf(s,"config%d",number_meas);

fp3=fopen(s,"w");

tidy();

for(i=0;i<simplex_number;i++)
{
temp=simplex_point[i];
for(j=0;j<DPLUS;j++)
{
vertex_io[i][j]=temp->vertex[j];
neighbour_io[i][j]=(temp->neighbour[j])->label;
}
}

temp2=stack_head;
i=0;
while(temp2!=NULL)
{
stack_io[i]=temp2->name;
i++;
temp2=temp2->next;
}

if(stack_count!=i){printf("\nWrong number on stack ");exit(1);}

fprintf(fp3,"%d %d %d\n",simplex_number,node_number,stack_count);

fprintf(fp3,"%lg %lg %lg\n",kappa_0,kappa_d,BETA);

for(j=0;j<stack_count;j++)
fprintf(fp3,"%d\n",stack_io[j]);

for(i=0;i<simplex_number;i++)
for(j=0;j<DPLUS;j++)
fprintf(fp3,"%d %d\n",vertex_io[i][j],neighbour_io[i][j]);

fclose(fp3);

return;
}

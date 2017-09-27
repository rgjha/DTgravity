#include "grav.h"
/* routine reads simplex data from arrays and builds structures */

void read_in(void)
{
FILE *fp1;
int  count,s_number,i,j,k,dum[DPLUS],dummy,l_number,c,e1,e2,simp;
double k0,b;

simplex_number=0;
stack_count=0;
pointer_number=0;
printf("Reading in existing configuration\n");
fflush(stdout);

fp1=fopen("config","r");

fscanf(fp1,"%d%d%d",&s_number,&node_number,&count);
fscanf(fp1,"%lg%lg%lg",&k0,&kappa_d,&b);

printf("\nConfiguration has volume %d ",s_number);
printf("\nVertex and curvaturesq coupling %lg %lg ",k0,b);
fflush(stdout);

for(i=0;i<count;i++)
{
fscanf(fp1,"%d",&dummy);
push(dummy);
}


for(i=0;i<s_number;i++)
{
for(j=0;j<DPLUS;j++)
fscanf(fp1,"%d%d",&vertex_io[i][j],&neighbour_io[i][j]);

for(j=0;j<DPLUS;j++)
dum[j]=vertex_io[i][j];

simplex_point[i]=add_simplex(dum);
}


for(i=0;i<simplex_number;i++)
for(j=0;j<DPLUS;j++)
simplex_point[i]->neighbour[j]=simplex_point[neighbour_io[i][j]];


growing_vol=simplex_number;

printf("\nHave read data successfully ");
fflush(stdout);
return;
}

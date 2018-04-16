#include "grav.h"
/* every sweep clean up pointer array */

void tidy(void)
{
PSIMPLEX temp[BIGVOL];
int  i,add;

/* run down array compressing non NULL extries into new array */
/* and reassigning simplex labels according to their new index in this */
/* array. Finally copy back */

add=0;


if(pointer_number>BIGVOL){printf("\nError -- need to increase BIGVOL");exit(1);}

if(pointer_number>max_point) max_point=pointer_number;
//max_point+=pointer_number;

for(i=0;i<pointer_number;i++)
if(simplex_point[i]!=NULL)
{
temp[add]=simplex_point[i];
temp[add]->label=add;
add++;
}

for(i=0;i<add;i++)
simplex_point[i]=temp[i];


pointer_number=add;
if(pointer_number!=simplex_number){
printf("oops - pointer number is not equal to simplex_number in tidy()\n");}

return;
}

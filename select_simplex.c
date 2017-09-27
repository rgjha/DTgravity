#include "grav.h"
/* selects a simplex at random by accessing an array of pointers */
/* once has a simplex select subsimplex/move at random */

PSIMPLEX select_simplex(int  *sub)
{
PSIMPLEX temp;
int  i;


do{
i=(int)(my_random()*pointer_number);
temp=simplex_point[i];
  }
while(temp==NULL) ;

/* initially just grow with node insertion moves */

if(grow==YES)
*sub=D;
else
/* in general choose move type at random */
*sub=(int)(my_random()*DPLUS); 

/* debugging */
/*if(drand48()<0.5) *sub=0;
else
*sub=D;*/

try_subsimplex[*sub]++;

return(temp);

}

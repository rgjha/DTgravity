#include "grav.h"
int find_order(int a, PSIMPLEX pp){ 
int dum[DPLUS],num;
PSIMPLEX list[INCVOL];

/* finds num of d-simps sharing vertex a */

dum[0]=a;
find_simplices(pp,dum,1,list,&num);
//(void)printf("order of vertex %d is %d\n",a,num);
return(num);
}

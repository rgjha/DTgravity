#include "grav.h"
/* routine takes n element vector a[] and returns n-1 element in b[] */
/* thus n combinations possible selected according to count */
/* count is the index 'left out' in getting n-1 from n */
/* vertex left out of final vector b[] is returned in b[n-1] */

void combo(int  a[DPLUSPLUS], int  b[DPLUSPLUS], int  n, int  count)
{
int  i,add;

add=0;
for(i=0;i<n;i++)
{
if(count!=i)
{
b[add]=a[i];
add++;
}
else b[n-1]=a[i];
}
return;
}

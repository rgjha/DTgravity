#include "grav.h"
/* routine takes input pointer to simplex and outputs array of */
/* distances from given simplex to other simplices labelled by their */
/* position in simplex_point[] i.e the value of their member label */

int randomwalk(PSIMPLEX p, int returns[STEPS])
{
int i,j,number,back;
PSIMPLEX current,next;

number=0;back=0;
current=p;

while(number<STEPS){
j=(int)(my_random()*DPLUS);
next=current->neighbour[j];
//printf("reached simplex %d\n",next->label);
if(next==p) {
//printf("back to origin after %d steps\n",number);
returns[back]=number;back++;}
current=next;
number++;}

return(back);
}

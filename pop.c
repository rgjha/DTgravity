#include "grav.h"
/* routine pops off a vertex label after an accepted node insertion move  */

void pop(void)
{

PNODE temp;

/* if stack is empty do nothing */

if(stack_head==NULL)
return;

temp=stack_head;
stack_head=stack_head->next;
free(temp);
stack_count--;

return;

}

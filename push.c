#include "grav.h"
/* routine pushes deleted vertex label onto stack */

void push(int  i)
{
PNODE temp;

temp=(PNODE)malloc(sizeof(NODE));
temp->name=i;
temp->next=stack_head;

stack_head=temp;

stack_count++;
return;
}

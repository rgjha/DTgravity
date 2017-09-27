#include "grav.h"

void singular_vertex(void){
int i,j;
PSIMPLEX temp;
PSIMPLEX near[VOL];
int a[DPLUS],not_seen[VOL],number;
double vertex_coord[VOL];
static int first_time=1;
static FILE *f;

tidy();
for(i=0;i<VOL;i++)
vertex_coord[i]=0.0;

for(i=0;i<simplex_number;i++)
not_seen[i]=1;

for(i=0;i<simplex_number;i++){
temp=simplex_point[i];

for(j=0;j<D;j++){
if(not_seen[temp->vertex[j]]){
a[0]=temp->vertex[j];
find_simplices(temp,a,1,near,&number);
vertex_coord[number]=vertex_coord[number]+1.0;
not_seen[temp->vertex[j]]=0;
}
}

}

if(first_time){
f=fopen("singular","a");
first_time=0;
}

for(i=0;i<VOL;i++){
if(vertex_coord[i]>0.0)
(void)fprintf(f,"%d %lg\n",i,vertex_coord[i]);
}

fflush(f);

return;
}

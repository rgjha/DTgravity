#include "grav.h"

#define P D

typedef struct
{
    int num;
    int vertices[P];
} DminusOne;


void *DminusOne_root=NULL;


void printDminusOne(const void *node, VISIT order, int level){
    if (order == preorder || order == leaf) {
        (void)printf("DminusOne simp %d\n",(*(DminusOne**)node)->num);
        (void)printf("vertices:\n");
        for(int i=0;i<P;i++){
            (void)printf("%d ",(*(DminusOne**)node)->vertices[i]);}
        (void)printf("\n");
        
    }
}

int DminusOnecomp(const void *l, const void *r)
{
    int i;
    const DminusOne *lm = l;
    const DminusOne *lr = r;
    int d[P],diff=0;
    
    for(i=0;i<P;i++){
        d[i]=(lm->vertices[i])-(lr->vertices[i]);
        if(d[i]!=0){return d[i];}
    }
    
    return(0);
} 

// applies boundary operator to D simplex and builds incidence matrix

void DminusOne_search(int label, int v[DPLUS], int parity)
{
int vm[P],i,j;
static int num=0,level=D-1;
void *tmp;
DminusOne *a,*data;
    
    if(label==(-1)){
         while(DminusOne_root!=NULL){
         data = *(DminusOne **)DminusOne_root;
         tdelete(data,&DminusOne_root,DminusOnecomp);
         free(data);}
         num=0;
         DminusOne_root=NULL;
         (void)printf("Z in DminusOne is %lg\n",(double)(Dm1num/((double)simplex_number*DPLUS)));
  //       (void)printf("finished with D-1\n");fflush(stdout);

// free up data in boundary simps too
    DminusTwo_search(-1,vm,1);
        return;
    }
 
for(i=0;i<(P+1);i++){
    // find one of the boundary simps
            boundary(P,v,i,vm);
    a=(DminusOne*)malloc(sizeof(DminusOne));
    
    // assign to search structure
            for(j=0;j<P;j++){
            a->vertices[j]=vm[j];
            }
    
    tmp=tfind(a,&DminusOne_root,DminusOnecomp);
    if(tmp!=NULL){free(a);}
  
    if(tmp==NULL){
    // add to search tree
    tmp=tsearch(a,&DminusOne_root,DminusOnecomp);
    (*(DminusOne**)tmp)->num=num;
    // now call DminusTwo search
    DminusTwo_search(num,vm,level-1);
    num++;
    }

    
// assign elements of incidence matrix
//I[label][(*(DminusOne**)tmp)->num]=parity*PERM(i);
//ITRANS[(*(DminusOne**)tmp)->num][label]=I[label][(*(DminusOne**)tmp)->num];

//(void)printf("building sparse in DminusOne with Simp number=%d and count=%d\n",simplex_number,count);fflush(stdout);
if(Dm1num>NNZDm1){(void)printf("redimension sparse arrays in DminusOne\n");fflush(stdout);}
sI[Dm1num]=parity*PERM(i);
rowI[Dm1num]=label;
colI[Dm1num]=(*(DminusOne**)tmp)->num;

Dm1num++;
              
}
return;
}

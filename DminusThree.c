#include "grav.h"

#define P (D-2)

typedef struct
{
    int num;
    int vertices[P];
} DminusThree;

void *DminusThree_root=NULL;


void printDminusThree(const void *node, VISIT order, int level){
    if (order == preorder || order == leaf) {
        (void)printf("DminusThree simp %d\n",(*(DminusThree**)node)->num);
        (void)printf("vertices:\n");
        for(int i=0;i<P;i++){
            (void)printf("%d ",(*(DminusThree**)node)->vertices[i]);}
        (void)printf("\n");
        
    }
}

int DminusThreecomp(const void *l, const void *r)
{
    int i;
    const DminusThree *lm = l;
    const DminusThree *lr = r;
    int d[P],diff=0;
    
    for(i=0;i<P;i++){
        d[i]=(lm->vertices[i])-(lr->vertices[i]);
        if(d[i]!=0){return d[i];}
    }
    
    return(0);
} 

// applies boundary operator to D simplex and builds incidence matrix

void DminusThree_search(int label, int v[DPLUS], int level)
{
int vm[P],i,j;
static int num=0;
void *tmp;
DminusThree *data,*a;

    if(label==(-1)){
        while(DminusThree_root!=NULL){
        data = *(DminusThree **)DminusThree_root;
        tdelete(data,&DminusThree_root,DminusThreecomp);
        free(data);}

        num=0;
        DminusThree_root=NULL;
        (void)printf("Z in DminusThree is %lg\n",(double)(Dm3num/((double)simplex_number*DPLUS)));
   //     (void)printf("Finished with D-3\n");fflush(stdout);

        if(D==4){
        DminusFour_search(-1,vm,1);}
        return;
    }
    

for(i=0;i<(P+1);i++){
    // find one of the boundary simps
    boundary(P,v,i,vm);
    a=(DminusThree *) malloc(sizeof(DminusThree));
    

    // assign to search structure
            for(j=0;j<P;j++){
            a->vertices[j]=vm[j];
            }
    
    tmp=tfind(a,&DminusThree_root,DminusThreecomp);
  
    if(tmp!=NULL){free(a);}
    if(tmp==NULL){
    // add to search tree
    tmp=tsearch(a,&DminusThree_root,DminusThreecomp);
    (*(DminusThree**)tmp)->num=num;
    if(D==4){
    DminusFour_search(num,vm,level-1);}
    num++;
    }
    
// assign elements of incidence matrix

//K[label][(*(DminusThree**)tmp)->num]=PERM(i);
//KTRANS[(*(DminusThree**)tmp)->num][label]=K[label][(*(DminusThree**)tmp)->num];
if(Dm3num>NNZDm3){(void)printf("redimension sparse arrays in DminusThree\n");fflush(stdout);}
    sK[Dm3num]=PERM(i);
    rowK[Dm3num]=label;
    colK[Dm3num]=(*(DminusThree**)tmp)->num;
    Dm3num++;

}
    
return;
}

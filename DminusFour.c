#include "grav.h"

#if (D>2)
#define P (D-3)
#else
#define P 0
#endif

typedef struct
{
    int num;
    int vertices[P];
} DminusFour;

void *DminusFour_root=NULL;


void printDminusFour(const void *node, VISIT order, int level){
    if (order == preorder || order == leaf) {
        (void)printf("DminusFour simp %d\n",(*(DminusFour**)node)->num);
        (void)printf("vertices:\n");
        for(int i=0;i<P;i++){
            (void)printf("%d ",(*(DminusFour**)node)->vertices[i]);}
        (void)printf("\n");
        
    }
}

int DminusFourcomp(const void *l, const void *r)
{
    int i;
    const DminusFour *lm = l;
    const DminusFour *lr = r;
    int d[P],diff=0;
    
    for(i=0;i<P;i++){
        d[i]=(lm->vertices[i])-(lr->vertices[i]);
        if(d[i]!=0){return d[i];}
    }
    
    return(0);
} 

// applies boundary operator to D simplex and builds incidence matrix

void DminusFour_search(int label, int v[DPLUS], int level )
{
int vm[P],i,j;
static int num=0;
void *tmp;
DminusFour *a,*data;

    if(label==(-1)){
       while(DminusFour_root!=NULL){
        data = *(DminusFour **)DminusFour_root;
        tdelete(data,&DminusFour_root,DminusFourcomp);
        free(data);}

        num=0;
        DminusFour_root=NULL;
        (void)printf("Z in DminusFour is %lg\n",(double)Dm4num/((double)simplex_number*DPLUS));
       // (void)printf("Finished with D-4\n");fflush(stdout);
        return;
    }
    
for(i=0;i<(P+1);i++){
    // find one of the boundary simps
    boundary(P,v,i,vm);
    a= malloc(sizeof(DminusFour));
    

    // assign to search structure
            for(j=0;j<P;j++){
            a->vertices[j]=vm[j];
            }
    
    tmp=tfind(a,&DminusFour_root,DminusFourcomp);
    if(tmp!=NULL){free(a);}
  
    if(tmp==NULL){
        // add to search tree
    tmp=tsearch(a,&DminusFour_root,DminusFourcomp);
    (*(DminusFour**)tmp)->num=num;
    num++;
    }
    
// assign elements of incidence matrix

//L[label][(*(DminusFour**)tmp)->num]=PERM(i);
//LTRANS[(*(DminusFour**)tmp)->num][label]=L[label][(*(DminusFour**)tmp)->num];
if(Dm4num>NNZDm4){(void)printf("redimension sparse arrays in DminusFour\n");fflush(stdout);}
    sL[Dm4num]=PERM(i);
    rowL[Dm4num]=label;
    colL[Dm4num]=(*(DminusFour**)tmp)->num;
    Dm4num++;

}
    
return;
}

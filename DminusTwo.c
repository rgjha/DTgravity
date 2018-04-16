#include "grav.h"

#define P (D-1)

typedef struct
{
    int num;
    int vertices[P];
} DminusTwo;

void *DminusTwo_root=NULL;

void printDminusTwo(const void *node, VISIT order, int level){
    if (order == preorder || order == leaf) {
        (void)printf("DminusTwo simp %d\n",(*(DminusTwo**)node)->num);
        (void)printf("vertices:\n");
        for(int i=0;i<P;i++){
            (void)printf("%d ",(*(DminusTwo**)node)->vertices[i]);}
        (void)printf("\n");
        
    }
}

int DminusTwocomp(const void *l, const void *r)
{
    int i;
    const DminusTwo *lm = l;
    const DminusTwo *lr = r;
    int d[P],diff=0;
    
    for(i=0;i<P;i++){
        d[i]=(lm->vertices[i])-(lr->vertices[i]);
        if(d[i]!=0){return d[i];}
    }
    
    return(0);
} 

// applies boundary operator to D simplex and builds incidence matrix

void DminusTwo_search(int label, int v[DPLUS], int level)
{
int vm[P],i,j;
static int num=0;
void *tmp;
DminusTwo *a,*data;

    if(label==(-1)){
        while(DminusTwo_root!=NULL){
        data = *(DminusTwo **)DminusTwo_root;
        tdelete(data,&DminusTwo_root,DminusTwocomp);
        free(data);}
        num=0;
        DminusTwo_root=NULL;
        (void)printf("Z in DminusTwo is %lg\n",(double)Dm2num/((double)simplex_number*DPLUS));
        //(void)printf("Finished with D-2\n");fflush(stdout);
        
        if((D==3)||(D==4)){
        DminusThree_search(-1,vm,1);}
        return;
    }
    
for(i=0;i<(P+1);i++){
    // find one of the boundary simps
    boundary(P,v,i,vm);
    a= malloc(sizeof(DminusTwo));
    

    // assign to search structure
            for(j=0;j<P;j++){
            a->vertices[j]=vm[j];
            }
    
    tmp=tfind(a,&DminusTwo_root,DminusTwocomp);
    if(tmp!=NULL){free(a);}
  
        // add to search tree
    if(tmp==NULL){
    tmp=tsearch(a,&DminusTwo_root,DminusTwocomp);
    (*(DminusTwo**)tmp)->num=num;
    // now call DminusTwo search
    if(D==3 || (D==4)){
    DminusThree_search(num,vm,level-1);}
    num++;
    }
    
// assign elements of incidence matrix

//J[label][(*(DminusTwo**)tmp)->num]=PERM(i);
//JTRANS[(*(DminusTwo**)tmp)->num][label]=J[label][(*(DminusTwo**)tmp)->num];

    if(Dm2num>NNZDm2){(void)printf("redimension sparse arrays in DminusTwo\n");fflush(stdout);}
    sJ[Dm2num]=PERM(i);
    rowJ[Dm2num]=label;
    colJ[Dm2num]=(*(DminusTwo**)tmp)->num;
    Dm2num++;

}
    
return;
}

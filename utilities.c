#include "grav.h"


double *vector(long nl, long nh)
/* allocate a double vector with subscript range v[nl..nh] */
{
double *v;

v=(double *)malloc((size_t)((nh-nl+1+NR_END)*sizeof(double)));
if (!v) printf("allocation failure in vector()");
return v-nl+NR_END;
}

int *ivector(long nl, long nh)
/* allocate an int vector with subscript range v[nl..nh] */
{
int *v;

v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
if(!v) printf("allocation failure in ivector()");
return v-nl+NR_END;
}

double **matrix(long nrl, long nrh, long ncl, long nch)
/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
long i,nrow=nrh-nrl+1,ncol=nch-ncl+1;
double **m;

/* allocate pointers to rows */

m=(double **) malloc((size_t)((nrow+NR_END)*sizeof(double *)));
if(!m) printf("allocation failure 1 in matrix()");
m+= NR_END;
m-= nrl;

/* allocate rows and set pointers to them */
m[nrl]=(double *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(double)));
if(!m[nrl]) printf("allocation failure 2 in matrix()");
m[nrl]+= NR_END;
m[nrl]-= ncl;

for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

/* return pointer to array of pointers to rows */
return m;
}

void free_vector(double *v, long nl, long nh)
/* free a double vector allocated with vector() */
{
free((FREE_ARG) (v+nl-NR_END));
}

void free_ivector(int *v, long nl, long nh)
/* free an int vector allocated with ivector() */
{
free((FREE_ARG) (v+nl-NR_END));
}

void free_matrix(double **m, long nrl, long nrh, long ncl, long nch)
/* free a double matrix allocated by matrix () */
{
free((FREE_ARG) (m[nrl]+ncl-NR_END));
free((FREE_ARG) (m+nrl-NR_END));
}

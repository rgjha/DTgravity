#include "grav.h"

/* routines checks manifold constraint */
/* this entails examining neighbour simplices for an occurrence */
/* of the 'opposing' vertex in a simplex which also contains the other*/
/* new common subsimplex vertices */
/* this is equivalent to requiring that the new common subsimplex */
/* is not present anywhere else in the triangulation */
/* examine all neighbours gotten by moving out on faces */
/* which contain the other new common subsimplex vertices */

enum LOGIC allowed_move(PSIMPLEX p, int  sub, int  a[DPLUSPLUS])
{
PSIMPLEX array1[VOL],array2[VOL],dum[DPLUS],examine[VOL];
int  i,j,number1,number2,search,b[DPLUS];
enum LOGIC good;

/* need to terminate when either 1. see opposing vertex a[DPLUS] in some */
/* simplex or 2. have examined all simplices containing the new common */
/* vertices derived from original simplex */
/* so need to flag simplices that have been examined */

   good=YES;

   if(sub==D)
   return(good);

   if (sub==0)
   return(good); 

   j=0;
   for(i=0;i<DPLUS;i++)
   if(i>sub)
   {b[j]=a[i];j++;}

   array1[0]=p;
   number1=1;
   examine[0]=p;
   search=1;
   p->flag=YES; 

/* loop while new neighbour simplices to examine */

   while(number1>0)
   {

   number2=0;

   for(i=0;i<number1;i++)
   {

/* examine to see if contains 'opposing vertex */

   for(j=0;j<DPLUS;j++)
   if(array1[i]->vertex[j]==a[DPLUS]){good=NO; break; }

   if(good==NO) break;

/* find simplices which also in common with this subsimplex */
/* and neighbour to simplex array1[i] */

   common_simplex(array1[i],b,D-sub,dum);

/* check to see whther any of these have been seen before */
/* if not then add to array2 and flag seen. Also make note in examine */

   for(j=0;j<sub+1;j++)
   if((dum[j]->flag)==NO)
   {array2[number2]=dum[j];
   number2++;
   dum[j]->flag=YES;

   examine[search]=dum[j];
   search++;
   }
    
   }

   if(good==NO) break;

   for(i=0;i<number2;i++)
   array1[i]=array2[i];

   number1=number2;

   }

/* depending on value of good we have either found the opposing vertex or */
/* examined all the associated simplices */

/* first set all local flags back to zero */

   for(i=0;i<search;i++)
   examine[i]->flag=NO;

   manifold_check+=(double)search/VOL;


   return(good);
   }

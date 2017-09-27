/* standard libraries */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <malloc.h>

/******** global constants etc ***********/

/* S^D topology */
/* node K0 and volume couplings KD */
/* target volume VOL and allowed volume fluctuation DV */
/* dimension D */
/* MAXVOL and MINVOL are hard limits on volume fluctuations */
/* DEBUG flagged when comparing to strong coupling */

#define K0 0.0
#define KD 0.0
#define DV 4
#define VOL 8000
#define MINVOL 6
#define MAXVOL (VOL+100)
#define D 4
#define DEBUG 0
#define MAXCORRDIST 30
#define HITS 10

/* writes out a config (called dump) every CHECKPOINT sweeps */ 
/* HITS specifies number of sites to use in geodesic calcs */

#define CHECKPOINT 1000
#define PI 3.14159265

/* some useful derived constants */
/* and max's for numbers of simplices and links */

#define DPLUS (D+1)
#define DPLUSPLUS (D+2)
#define BIGVOL (VOL*2)
#define INCVOL MAXVOL

/********* Now some structure declarations *********/

enum LOGIC {NO, YES};

struct element{
int vertex[DPLUS];
int  sum;
int  label;
enum LOGIC flag;
enum LOGIC face_flag[DPLUS];
struct element *neighbour[DPLUS];};

typedef struct element SIMPLEX;
typedef SIMPLEX *PSIMPLEX;

struct stack{
int  name;
struct stack *next;};

typedef struct stack NODE;
typedef NODE *PNODE;

/******* first - global variables **********/

/* arrays for I/O */

extern int vertex_io[INCVOL][DPLUS],neighbour_io[INCVOL][DPLUS],stack_io[VOL];

/* run parameters */

extern int THERMALISE;
extern int SWEEPS;
extern int BLOCK;
extern int GAP,TUNE_COUPLING,READIN,SEED,START_DUMP;
extern double BETA;
extern double kappa_0;

/* simple global pointers and counters */

extern PNODE stack_head;
extern int simplex_number,pointer_number,node_number,lp_number;
extern int link_number;

/* data structures */

extern PSIMPLEX simplex_point[BIGVOL];

/* measurements etc */

extern int  number_measure,legal_subsimplex[DPLUS],max_point;
extern int  
try_subsimplex[DPLUS],manifold_subsimplex[DPLUS],go_subsimplex[DPLUS];
extern int  stack_count,vol_monitor,num_monitor,growing_vol;
extern double manifold_check;

extern enum LOGIC grow;

/* simple observables -- number of nodes, simplices and size */
/* and variable versions of couplings */

extern double real_simplex,real_node,kappa_d,kappa_0,average_distance;

/* file pointers ... */

extern FILE *fp2,*fp3,*fp4,*fp5,*fp6;

extern double len_dist[INCVOL];


/******** function prototypes *********/

double drand48(void);

void srand48(long int seedval);

double my_random(void);

void curvsq(double *r, double *r2);

double ran3(int*);

int main(int argc, char *argv[]);

PSIMPLEX select_simplex(int  *sub);

enum LOGIC good_subsimplex(PSIMPLEX p, int  sub, int  a[DPLUSPLUS],
PSIMPLEX isimplex[DPLUSPLUS]);

void delete_simplex(PSIMPLEX p);

PSIMPLEX add_simplex(int  a[DPLUS]);

void combo(int  a[DPLUS], int  b[DPLUS], int  n, int  count);

void find_order(int a, PSIMPLEX pp, int p[DPLUS]);

int  sum_face(PSIMPLEX p, int  i);

void pop(void);

void push(int i);

void tidy(void);

enum LOGIC allowed_move(PSIMPLEX p, int  sub, int  a[DPLUSPLUS]);

void common_simplex(PSIMPLEX p, int  a[DPLUS], int  n, PSIMPLEX face[DPLUS]);

void find_simplices(PSIMPLEX p, int  a[DPLUS], int  sub, 
PSIMPLEX s_near[VOL], int  *i);

enum LOGIC metropolis(int  sub, int  labels[DPLUSPLUS],
PSIMPLEX addresses[DPLUSPLUS]);

void trial_change(void);

void update(int  labels[DPLUSPLUS], PSIMPLEX address[DPLUSPLUS], int sub
);

int  find_face(PSIMPLEX p, int  a);

void reconnect(int  a[DPLUSPLUS], PSIMPLEX q[DPLUSPLUS], int  sub);

void read_in(void);

void write_out(void);

void print_out(void);

void measure(void);

void initial_config(void);

void header(void);

void shift_coupling(void);

void geodesic(PSIMPLEX p, int  distance[INCVOL]);

double mean_dist(void);

void init(void);

double gasdev(void);

void print_simplex_info(PSIMPLEX p);

void read_param(void);

void find_links(int a, PSIMPLEX list[], int n, int linklist[], PSIMPLEX linkp[],
int *nolinks);

void setfaceno_go(PSIMPLEX p, int h[], int a);

void block_obs(void);

void io_config(int);

void singular_vertex(void);

double *vector(long nl, long nh);
int *ivector(long nl, long nh);
double **matrix(long nrl, long nrh, long ncl, long nch);
void free_vector(double *v, long nl, long nh);
void free_ivector(int *v, long nl, long nh);
void free_matrix(double **m, long nrl, long nrh, long ncl, long nch);
double pythag(double,double);

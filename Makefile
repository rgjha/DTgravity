# DT gravity makefile
#
CFLAGS = -O -I/Users/RG/Desktop/SuperLU_5.2.0/SRC
CC = gcc

OBJ = find_simplices.o print_out.o\
gasdev.o print_simplex_info.o\
randomwalk.o grav.o push.o\
direct_geodesic.o add_simplex.o ran3.o\
direct_randomwalk.o allowed_move.o read_in.o\
reconnect.o find_order.o\
combo.o select_simplex.o\
boundary.o kdoperator.o\
utilities.o setupsimplex.o\
common_simplex.o shift_coupling.o\
geodesic.o cleanup.o\
testorient.o ludcmp.o\
DminusOne.o DminusTwo.o DminusThree.o DminusFour.o\
good_subsimplex.o sparsedet.o determinant.o\
header.o sum_face.o\
orient.o sortsimplex.o\
init.o tidy.o calcdet.o\
initial_config.o trial_change.o\
update.o laplacian.o\
mean_dist.o\
delete_simplex.o measure.o\
metropolis.o\
find_face.o my_random.o\
write_out.o\
pop.o read_param.o\
block_obs.o io_config.o singular_vertex.o\

grav: $(OBJ) 
	$(CC) $(CFLAGS) -o grav $(OBJ) -L/Users/RG/Desktop/SuperLU_5.2.0/lib -lm -lblas -llapack -lsuperlu_5.1
 
find_simplices.o: grav.h
print_out.o: grav.h
gasdev.o: grav.h
setupsimplex.o: grav.h
DminusOne.o: grav.h 
DminusTwo.o: grav.h
DminusThree.o: grav.h
DminusFour.o: grav.h
boundary.o: grav.h
sparsedet.o: grav.h
calcdet.o: grav.h
determinant.o: grav.h
kdoperator.o: grav.h
orient.o: grav.h
laplacian.o: grav.h
cleanup.o: grav.h
testorient.o: grav.h
sortsimplex.o: grav.h
print_simplex_info.o: grav.h
grav.o: grav.h
push.o: grav.h
ludcmp.o: grav.h
randomwalk.o: grav.h
direct_randomwalk.o: grav.h
add_simplex.o: grav.h
ran3.o: grav.h
find_order.o: grav.h
allowed_move.o: grav.h
read_in.o: grav.h
reconnect.o: grav.h
combo.o: grav.h 
direct_geodesic.o: grav.h
select_simplex.o: grav.h
common_simplex.o: grav.h
shift_coupling.o: grav.h
geodesic.o: grav.h
good_subsimplex.o: grav.h
header.o: grav.h
sum_face.o: grav.h
init.o: grav.h
tidy.o: grav.h
initial_config.o: grav.h
trial_change.o: grav.h
update.o: grav.h
mean_dist.o: grav.h
delete_simplex.o: grav.h
measure.o: grav.h
metropolis.o: grav.h
find_face.o: grav.h
my_random.o: grav.h
write_out.o: grav.h
pop.o: grav.h
read_param.o: grav.h
block_obs.o: grav.h
io_config.o: grav.h
singular_vertex.o: grav.h

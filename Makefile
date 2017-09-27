# DT gravity makefile
#
CFLAGS = -O
CC = gcc

OBJ = find_simplices.o print_out.o\
gasdev.o print_simplex_info.o\
grav.o push.o\
add_simplex.o ran3.o\
allowed_move.o read_in.o\
reconnect.o\
combo.o select_simplex.o\
common_simplex.o shift_coupling.o\
geodesic.o\
good_subsimplex.o\
header.o sum_face.o\
init.o tidy.o\
initial_config.o trial_change.o\
update.o\
mean_dist.o\
delete_simplex.o measure.o\
metropolis.o\
find_face.o my_random.o\
write_out.o\
pop.o read_param.o\
setfaceno_go.o block_obs.o io_config.o singular_vertex.o\

grav: $(OBJ) 
	$(CC) $(CFLAGS) -o grav $(OBJ) -lm

find_simplices.o: grav.h
print_out.o: grav.h
gasdev.o: grav.h
print_simplex_info.o: grav.h
grav.o: grav.h
push.o: grav.h
add_simplex.o: grav.h
ran3.o: grav.h
allowed_move.o: grav.h
read_in.o: grav.h
reconnect.o: grav.h
combo.c: grav.h 
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
setfaceno_go.o: grav.h
block_obs.o: grav.h
io_config.o: grav.h
singular_vertex.o: grav.h

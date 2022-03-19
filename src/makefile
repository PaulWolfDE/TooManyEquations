CC=gcc
CFLAGS= #

OBJECTS = GaussianElimination.o Libtest.o Movement.o PeriodicFractionSolver.o StringEvaluation.o TextAssignments.o Utils.o Geometry.o

all: TooManyEquations
	
TooManyEquations: $(OBJECTS)
		$(CC) -o $@ $(OBJECTS)

$(OBJECTS): %.o: %.c
	        $(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.exe

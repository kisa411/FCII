all: puzzleSolver

puzzleSolver: main.o 
	g++ main.o -o puzzleSolver

main.o: main.cpp puzzleSolver.h
	g++ -c main.cpp

clean:
	rm -f *o puzzleSolver
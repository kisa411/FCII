all: mortgage

mortgage: main.o mortgage.o
	g++ main.o mortgage.o -o mortgage

main.o: main.cpp
	g++ -c main.cpp

mortgage.o: mortgage.cpp
	g++ -c mortgage.cpp

clean:
	rm *o mortgage
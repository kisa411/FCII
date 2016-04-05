all: language

binaryTree: language.o prelab.o
	g++ language.o -o language

language.o: language.cpp
	g++ -c language.cpp

prelab.o: prelab.cpp
	g++ -c prelab.cpp

clean:
	rm *o language prelab

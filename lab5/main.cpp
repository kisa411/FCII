#include <iostream>
#include <fstream> //for file input and output
#include <vector>
#include <string>
#include "puzzle.h"

using namespace std;

int main ( int argc, char *argv[] ) { //read in the name of the file from command line (argc = number of words in command line, argv[] = stores the actual words used in command line)

	//instantiate puzzle object
	Puzzle myPuzzle;

	//start a game of sudoku
	myPuzzle.playPuzzle();


	return 0;
}
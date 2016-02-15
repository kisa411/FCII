#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T> //using templates to make the program generic - make it work for numbers and characters
class Puzzle {

public:
	Puzzle(); //constructor - read in values from file and put them in a 2D vector
	void printPuzzle(); //print out the sudoku puzzle
	void playPuzzle(); //starts the game, interactive portion
	bool checkRow( T &value, int row, int col ); //check user input validity in row
	bool checkCol( T &value, int row, int col ); //check user input validity in column
	bool checkGrid( T &value, int row, int col ); //check user input validity in mini-grid
	void insertValue( T &value, int row, int col ); //put int or char where user wants
	void eraseValue( int row, int col ); //if user made a mistake, then they should be allowed to erase a value
	bool isComplete(); //check to see if the puzzle was completed correctly

private:
	vector< vector<T> > puzzleVector; //2D vector to store values of type T

};


#endif
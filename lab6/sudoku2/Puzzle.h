
#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>
using namespace std;

//typedefs for easier notation
typedef vector<int> intvec;
typedef vector< vector<int> > int2vec;
typedef vector< vector< vector<int> > > int3vec;

class Puzzle {

  public:
	Puzzle(string="easy.txt"); //constructor with default value
	void printGrid(); //displays current state of board
	void printPossValues(); //displays possibility of each move (81 lines)
	void Solve();

  private:
	int2vec grid; // 2D int vector that stores current sudoku board values/positions
	int3vec possValues; // 3D int vector that stores "possibility" (1 or 0) of moves
			    // 1st dim: row number
			    // 2nd dim: column number
			    // 3rd dim: possibe input digits 1-9

	//solving functions
	void eliminatePoss(int, int, int); //sets possValues[i][j][k] to 0
	void possFill(); //fills in values for the spaces for which all 
			 //other possibilities have been eliminated
	int validMove(int,int,int); //checks using basic sudoku rules
	void basicSolve(); //modifies possValues using validMove
	void singletonSolve(); //uses grid and possValues to fill in the rest
	void makeMove(int,int,int);
	int isComplete();

};

#endif

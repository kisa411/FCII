

#include "Puzzle.h"
#include <iostream>

using namespace std;

int main() {
	
	//easy puzzle
	Puzzle easySudoku("easy.txt");
	cout << "Unsolved easy sudoku puzzle:" << endl;
	easySudoku.printGrid();

	easySudoku.Solve();

	cout << "Solved easy sudoku puzzle:" << endl;
	easySudoku.printGrid();




	//medium puzzle
	Puzzle mediumSudoku("medium.txt");
	cout << "Unsolved medium sudoku puzzle:" << endl;
	mediumSudoku.printGrid();

	mediumSudoku.Solve();

	cout << "Solved medium sudoku puzzle:" << endl;
	mediumSudoku.printGrid();



	//hard puzzle
	Puzzle hardSudoku("cc1.txt");
	cout << "Unsolved hard sudoku puzzle:" << endl;
	hardSudoku.printGrid();

	hardSudoku.Solve();

	cout << "Partially solved hard sudoku puzzle:" << endl;
	hardSudoku.printGrid();

		
	


	return 0;

}

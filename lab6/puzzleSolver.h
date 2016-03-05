#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

template <typename T> //using templates to make the program generic - make it work for numbers and characters
class PuzzleSolver {

public:
	PuzzleSolver( string filename ); //constructor - read in values from file and put them in a 2D vector
	void printPuzzleSolver(); //print out the sudoku PuzzleSolverSolver
	//void playPuzzleSolver(); //starts the game, interactive portion
	int checkRow( T &value, int row ); //check user input validity in row
	int checkCol( T &value, int col ); //check user input validity in column
	int checkGrid( T &value, int row, int col ); //check user input validity in mini-grid
	void insertValue( T &value, int row, int col ); //put int or char where user wants
	int isComplete(); //check to see if the PuzzleSolverSolver was completed correctly
	int isEmpty(); //check to see if all spots are filled
	int checkValidity( T &value, int row, int col ); //combine all the checking functions in one function
	void updatePossibilities(); //update the possibilities vector
	void singleton(); //singleton algorithm
	// void clearSpot( int row, int col ); //erase the value that was just placed 
	void solvePuzzle(); //return true and print the finished PuzzleSolver if PuzzleSolver was solved, return false if PuzzleSolver is not solvable
	

private:
	//vector< vector<T> > PuzzleSolverVector(9, vector<T>(9)); //2D vector to store values of type T
	vector< vector<T> > PuzzleSolverVector;
	vector<int> defaultRow; //store the row position of default values
	vector<int> defaultCol; // store the col position of default values
	vector <vector <vector <int> > > Possibilities; //will only contain 0s for non-possible values and 1 for possible values - 3D vector
	
};


//FOR TEMPLATED CLASSES INCLUDE IMPLEMENTATION IN HEADER (INTERFACE) FILE

template <typename T>
PuzzleSolver<T>::PuzzleSolver( string filename ) { 
	int i, j;
	int size = 9; //size = number of rows
	T c; //c is the thing to get from the file

	ifstream datafile(filename.c_str()); //open datafile


	for ( i=0; i<size; i++ ) { //put empty vectors in the rows of the overall vector
		PuzzleSolverVector.push_back( vector<T>() ); //puts 9 empty vectors in the overarching vector - () after vector<T> calls on the constructor
	}
	
	if ( datafile.is_open() ) {	
		while ( datafile.good() ) { //while the file is good
			for ( i=0; i<size; i++ ) { //for each empty vector row
				for ( j=0; j<size; j++ ) { //read in 9 characters from file and put them in the vector
					
					datafile >> c; //read in character from file
					PuzzleSolverVector[i].push_back(c);
					

					int b = c; //for wordoku, need to convert '0' char to int 0
					if ( c != 0 && c != '0' ) { //if the program reads in a number that was originally in the PuzzleSolver, then it should store the position so that later the user can't erase that default value
						defaultRow.push_back(i); //store row position
						defaultCol.push_back(j); //store col position
					}
				}
			} break;
		}
	}
	
	datafile.close(); //close file after done reading from it 	
}


template <typename T>
void PuzzleSolver<T>::printPuzzleSolver() { //prints out the PuzzleSolver that was read in from the file - need to use iterator
	int j, row = 9;
	typename vector<T>::const_iterator i; //make an iterator so that program can go through each element of the vector and print it out

	for ( j=0; j<row; j++ ) {
		for( i = PuzzleSolverVector[j].begin(); i != PuzzleSolverVector[j].end(); ++i ) { //print out vector values
			cout << *i << " "; //* is necessary so that it prints out the value that the iterator is pointing to
		} cout << endl;
	}
	cout << endl;

}


template <typename T>
int PuzzleSolver<T>::checkRow( T &value, int row ) { //checks to see if user input is valid in a row
	int i;
	for ( i=0; i<9; i++ ) { 
		if ( PuzzleSolverVector[row-1][i] == value ) { //did not pass check, return false
			return 0;
		} 
	}

	
	return 1; //passed check, return true
}

template <typename T>
int PuzzleSolver<T>::checkCol( T &value, int col ) { //checks to see if user input is valid in a column 
	int i;
	for ( i=0; i<9; i++ ) {
		if ( PuzzleSolverVector[i][col-1] == value ) { //did not pass check, return false
			return 0;
		} 
	}

	
	return 1; //passed check, return true
}

template <typename T>
int PuzzleSolver<T>::checkGrid( T &value, int row, int col ) { //checks to see if user input is valid in the mini-grid
	int i, j, k, l;


	//set all the row and column values to start from top row, left square so that you can just go through the mini-grid from the same spot each time
	// cout << "Given row: " << row << " given col: " << col << endl;
	if ( row%3==1 ) {
		if ( col%3==1 ) { //top row, left square
			i = row; 
			j = col;
			// cout << i << " 1. " << j << endl;
		} else if ( col%3==2 ) { //top row, middle square
			i = row;
			j = col-1;
			// cout << i << " 1. " << j << endl;
		} else if ( col%3==0 ) { //top row, right square
			i = row;
			j = col-2;
			// cout << i << " 1. " << j << endl;
		}
	} else if ( row%3==2 ) {
		if ( col%3==1 ) { //middle row, left square
			i = row-1; 
			j = col;
			// cout << i << " 2. " << j << endl;
		} else if ( col%3==2 ) { //middle row, middle square
			i = row-1;
			j = col-1;
			// cout << i << " 2. " << j << endl;
		} else if ( col%3==0 ) { //middle row, right square
			i = row-1;
			j = col-2;
			// cout << i << " 2. " << j << endl;
		}
	} else if ( row%3==0 ) {
		if ( col%3==1 ) { //bottom row, left square
			i = row-2; 
			j = col;
			// cout << i << " 3. " << j << endl;
		} else if ( col%3==2 ) { //bottom row, middle square
			i = row-2;
			j = col-1;
			// cout << i << " 3. " << j << endl;
		} else if ( col%3==0 ) { //bottom row, right square
			i = row-2;
			j = col-2;
			// cout << i << " 3. " << j << endl;
		}
	}

	if ( row <=7 && col <= 7 ) {
		for ( row=i; row<i+3; row++ ) {
			for ( col=j; col<j+3; col++ ) {
				if ( PuzzleSolverVector[row-1][col-1]==value ) {
					return 0; //value is in the mini-grid, cannot be placed
				}
			}
		}
	}
	
	
	
	return 1; //value is not in the mini-grid, can be placed
}


template <typename T>
void PuzzleSolver<T>::insertValue( T &value, int row, int col ) { //puts an integer or character at the place user wants to place 
	int i;

	for ( i=0; i<defaultRow.size(); i++ ) { //loop through stored positions of default values and if position corresponds with one of the values then say 'no'
		if ( (row) == defaultRow[i] && (col) == defaultCol[i] ) {
			cout << "That's a default value - you can't erase that." << endl;
			break;
		} else { 
			PuzzleSolverVector[row][col] = value; //value isn't being placed in a default value position, go ahead
		}
	}
	

}

template <typename T>
int PuzzleSolver<T>::isComplete() { //checks if Puzzle was completed correctly
	if ( isEmpty()==0 ) {//if all spots are filled
		return 1; //the Puzzle was completed correctly
	}

	return 0; //the Puzzle is incorrect

}

template <typename T>
int PuzzleSolver<T>::isEmpty() { //check if there are no empty values (check for 0s)
	int i, j;

	for ( i=0; i<9; i++ ) {
		for ( j=0; j<9; j++ ) {
			if ( PuzzleSolverVector[i][j]==0 ) {
				return 1; //found an empty spot
			}
		}
	}

	return 0; //all spots are filled
}


template <typename T>
void PuzzleSolver<T>::updatePossibilities() {
	int row, col, i, j, value, count = 0;


	for ( row=0; row<9; row++ ) { //for each row of the sudoku puzzle
		for ( col=0; col<9; col++ ) { //for each column of the sudoku puzzle
			if ( PuzzleSolverVector[row][col] == 0 ) { //if the spot is empty
				for ( value=1; value<10; value++ ) { //try all possible values
					if ( checkValidity( value, (row+1), (col+1) )== 0 ) { //if the value is in the same row, then reduce possibilities
						Possibilities[row][col][value-1] = 0;
					}
				}
			}
		}
	}
	int test = 0;
	for ( row=0; row<9; row++ ) { //for each row of the sudoku puzzle
		for ( col=0; col<9; col++ ) {
			//cout << "new spot" << endl;
			count = 0;
			for ( int i=0; i<9; i++ ) {
					//cout << Possibilities[row][col][i] << endl;
				if ( Possibilities[row][col][i]==1 ) {
					count++;
				}
			}
			cout << "Count: " << count << endl;
			
			if ( count==1 ) { //if there's only one possible value in the possibilities vector, then place that number on the board
				test = 1;
				cout << "Here" << endl;
				for ( int i=0; i<9; i++ ) {
					if ( Possibilities[row][col][i] == 1 ) {
						value = (i+1);
						insertValue( value, row, col );
						cout << "placed: " << value << " at row: "  << row+1 << " at col: " << col+1 << endl;
						Possibilities[row][col][i] = 0;
					}
				}
			}
		}
	}
	if ( test==0) {
		for ( row=0; row<9; row++ ) { //for each row of the sudoku puzzle
			for ( col=0; col<9; col++ ) {
				for ( int i=0; i<9; i++ ) {
					cout << "Row: " << row+1 << " col: " << col+1 << " value: " << i+1 << endl;
					cout << Possibilities[row][col][i] << endl;

				}
			}
		}


		exit(1);
	}
					
				
	count = 0;
	

}

template <typename T>
int PuzzleSolver<T>::checkValidity( T &value, int row, int col ) {
	if ( PuzzleSolverVector[row-1][col-1] == 0 ) { //if spot is empty
 		if ( checkCol(value, col) == 1 ) {
			// cout << "checked col" << endl;
			if ( checkRow(value, row) == 1 ) {
				// cout << "checked row" << endl;
				if ( checkGrid(value, row, col) == 1 ) {
					// cout << "checked grid" << endl;
					return 1;
				}
			}
		}
	}

	return 0;
}


template <typename T>
void PuzzleSolver<T>::singleton() { //singleton algorithm implementation
	int i, j, row, col, value, rowNum;
	int x = 1;
	vector<int> isPossible; //contains how many cells can be that value


	//set up vector
	for ( i=0; i<9; i++ ) { //isPossible vector now contains 9 0s
		isPossible.push_back(0);
	}
	value = 1;
	for ( col=0; col<9; col++ ) {
		for (x= 1; x < 10; x++) {
			isPossible[x-1] = 0; //re-set vector for each value
		}
		
		for ( row=0; row<9; row++ ) { //go through rows
			for ( value=1; value<10; value++ ) { //go through possible values
				cout << "Row: " << row+1 << " Col: " << col+1 << endl;
				//cout << "Trying to see if " << value << " is a singleton." << endl;
				if ( checkValidity( value, (row+1), (col+1) ) == 1) { //if value is valid in the cell
					cout << "The value " << value << " is possible here." << endl;
					//rowNum = row;
					isPossible[value-1]++; //increment the position of vector for each cell that can have that value
					cout << (value) << " is: " << isPossible[value-1] << endl;


				}
			}
		}
	}
}


template <typename T>
void PuzzleSolver<T>::solvePuzzle() { //solve the sudoku Puzzle
	int row, col, i =0, size = 9, value;
	
	vector <int> temp1; //temporary vector to store values 0-10 
	vector <vector <int> > temp2; //temporary vector to store 9 temp1 vectors

	//set up 3D vector
	for ( int i=0; i<9; i++ ) { //set up first level of 3D vector - v[0] ~ v[8] will correspond to the column values
		temp1.push_back(1);
	}

	for ( int i=0; i<9; i++ ) { //set up second level of 3D vector - col
		temp2.push_back(temp1);
	}

	for ( int i=0; i<9; i++ ) { //set up third level of 3D vector - row
		Possibilities.push_back(temp2);
	}

	// //update the boolean values of first level of 3D vector to match the possibilities based on the positions of the default values
	// updatePossibilities();
	
	do { //while the Puzzle still has empty cells
		cout << "Updating possibilities" << endl;
		updatePossibilities(); //update Possibilities vector
		//cout << "Looking for singleton." << endl;
		//singleton(); //check for singletons and if they exist, place singleton value on board
		cout << endl;
		printPuzzleSolver();
		//exit(1);
		cout << endl;
	} while( isComplete()==0 );

	printPuzzleSolver(); //display the solved sudoku puzzle

}


#endif
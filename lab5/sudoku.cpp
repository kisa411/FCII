#include <iostream>
#include <fstream> //for file input and output
#include <vector>
#include <string>
#include "puzzle.h"

using namespace std;

template <typename T>
Puzzle<T>::Puzzle( int type ) { //constructor - 1 is sudoku, 2 is wordoku
	//string word;
	int i, j;
	int loop = 0, size = 9; //size = number of rows
	T c; //c is the thing to get from the file

	//set up for reading from the textfile
	while ( loop == 0 ) {
		if ( argc!=2 ) {
			cout << "You forgot to put in the name of the file in the command line." << endl;
		} else {
			//argv[1] is the name of the file to open
			ifstream filename; //create a file handle
			filename.open( argv[1] ); //open the file that was input in command line
			if ( !filename.is_open() ) { //if the file is not opened correctly
				cout << "The file couldn't be opened." << endl;
			} else {
				cout << "Proceeding to read values from file..." << endl;
				loop = 1; //file was successfully opened, continue
			}
		}
	}

	for ( i=0; i<size; i++ ) { //put empty vectors in the rows of the overall vector
		puzzleVector.push_back( vector<T>() ); //puts 9 empty vectors in the overarching vector - () after vector<T> calls on the constructor
		filename.get(c); //read in the first character from the file
		while ( filename.get(c) ) {
			for ( i=0; i<size; i++ ) { //for each empty vector row
				for ( j=0; j<9; j++ ) { //read in 9 characters from file and put them in the vector
					puzzleVector[i].push_back(c);
					filename.get(c); //read in next character from the file
				}
			}
		}
	}
	//filename >> c;

	filename.close(); //close the file once the program is done putting the values in the vector
	}
}


template <typename T>
void Puzzle<T>::printPuzzle() { //prints out the puzzle that was read in from the file - need to use iterator
	int j, row = 9;
	vector<T>::const_iterator i; //make an iterator so that program can go through each element of the vector and print it out

	for ( j=0; j<row; j++ ) {
		for( i = puzzleVector[j].begin(); i != puzzleVector[j].end()-1; ++i ) { //print out vector values
			cout << *i << " "; //* is necessary so that it prints out the value that the iterator is pointing to
		}
	}


}

template <typename T>
void Puzzle<T>::playPuzzle() { //start the sudoku puzzle 
	int choice, row, col, loop = 1;
	T value;

	while ( loop == 1 ) {
		cout << "What would you like to do? 1. Place a value.\n 2. Erase a value.\n 3. Print the current board.\n 4. Quit the game.\n" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "What is the value that you would like to put in?" << endl;
				cin >> value;
				cout << "What is the row number that you would like to put the value in?" << endl;
				cin >> row;
				cout << "What is the column number that you would like to put the value in?" << endl;
				cin >> col;
				puzzleVector.insertValue( value, row, col );
				if ( puzzleVector.isComplete() == 1 ) {
					cout << "You've successfully completed the puzzle! Congrats :)" << endl;
					puzzleVector.printPuzzle();
					cout << "Now quitting the game." << endl;
					loop = 0;
				}
				break;
			case 2:
				cout << "What is the row number you want to erase a value from?" << endl;
				cin >> row;
				cout << "What is the column number you want to erase a value from?" << endl;
				cin >> col;
				puzzleVector.eraseValue( row, col );
				break;
			case 3:
				puzzleVector.printPuzzle();
				break;
			case 4:
				loop = 0;
				break;
		}
	}
	
}

template <typename T>
bool Puzzle<T>::checkRow( T &value, int row, int col ) { //checks to see if user input is valid in a row


}

template <typename T>
bool Puzzle<T>::checkCol( T &value, int row, int col ) { //checks to see if user input is valid in a column 


}

template <typename T>
bool Puzzle<T>::checkGrid( T &value, int row, int col ) { //checks to see if user input is valid in the mini-grid


}

template <typename T>
void Puzzle<T>::insertValue( T &value, int row, int col ) { //puts an integer or character at the place user wants to place 
	
	if ( checkRow( value, row, col ) ) { //if row is clear
		if (checkCol( value, row, col ) ) { //if column is clear
			if ( checkGrid( value, row, col ) ) { //if grid is clear
				insertValue( value, row, col ); //place value
				cout << "Value was successfully placed at row: " << row << " and column: " << col << endl;
			}
		}
	} else {
		cout << "Sorry, that's not a valid position. Try again!" << endl;
	}

}

template <typename T>
void Puzzle<T>::eraseValue( int row, int col ) { //erases the value at the position 

	vector<T>::const_iterator i = col; //make an iterator so that program can go through each element of the vector and print it out

	puzzleVector[row].erase(i); //erase the value at the given position

}

template <typename T>
bool Puzzle<T>::isComplete() { //checks if puzzle was completed correctly
	if (...) {//if there are no empty values (check for 0s)
		if ( checkRow( value, row, col ) ) { //if row is clear
			if (checkCol( value, row, col ) ) { //if column is clear
				if ( checkGrid( value, row, col ) ) { //if grid is clear
					return 1; //the puzzle was completed correctly
				}
			}
		}
	}

	return 0; //the puzzle is incorrect

}






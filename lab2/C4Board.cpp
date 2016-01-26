#include <iostream>
#include <stdbool.h> //for bool
#include <stdlib.h> //for rand()
#include "C4Board.h"
using namespace std;

//Emily Koh
ostream &operator<<( ostream& output, C4Board& board) {	//overloading '<<' operator, displays the current board in simple text
/*what do the '&'s do --> passes it by reference, so you don't need a copy constructor * (constructor that makes a copy of the class that it receives - necessary when you have new and delete)*/

	int i, j;

	for( i=board.Board[1].getMaxDiscs()-1; i>=0; i-- ) {	//go down the board by row (Board[i] = column)
		for ( j=0; j<=(board.numCol-1); j++ ) {	//go rightways from the first column
			output << board.Board[j].getDisc(i) << " | ";
		} 
		output << endl; //makes it go to another row
	}

	return (output);
}

C4Board::C4Board() {	//default constructor
	numCol = 7;	//the number of columns that are in the Connect 4 Board
}

C4Board::~C4Board() {	//default deconstructor
	//delete[] Board; //delete the pointer to the array of C4Col
	//cout << "Something was deleted." << endl;
}

void C4Board::play() {	//allows two players to play a game
	int position, turn=1;
	int choice;

	cout << "Are you playing with another person (press 1) or do you want to play against a computer (press 2)?" << endl;
	cin >> choice;
	if ( choice == 1 ) {
		while (1) { 	//there are 42 holes, so there are up to 42 turns
			if ( turn%2 == 1) {	//player 1's turn
				cout << (*this); //display the current board (<< has been overloaded to be able to display the board object)
				cout << "Player 1, which column would you like to place a piece? To end the game, put -1." << endl;
				cout << "Column:";
				cin >> position;
				if ( position == -1 ) {
					cout << "The game will now end." << endl;
					break;
				}
				while ( position < 1 || position > 7 ) {	//invalid position since it's not within the allowed columns
					cout << "That position is invalid. Please enter a position from 1~7." << endl;
					cin >> position;
				} if (Board[position-1].isFull() == false) { //if the column has an empty space
					Board[position-1]+=('X'); //'X' for player 1
					turn++;
				}
				if (winner() == true) {
					cout << "Player 1 has won the game. Congratulations!" << endl;
					cout << (*this); //show final board
					break;
				}
			} else if( turn%2 == 0) {	//player 2's turn
				cout << (*this);	//display the current board
				cout << "Player 2, which column would you like to place a piece? To end the game, put -1." << endl;
				cout << "Column:";
				cin >> position;
				if ( position == -1 ) {
					cout << "The game will now end." << endl;
					break;
				}
				while ( position < 1 || position > 7 ) {	//invalid position since it's not within the allowed columns
					cout << "That position is invalid. Please enter a position from 1~7." << endl;
					cin >> position;
				} if (Board[position-1].isFull() == false) { //if column has an empty space
					Board[position-1]+=('O'); //'O' for player 2
					turn++;
				} if (winner() == true) {
					cout << "Player 2 has won the game. Congratulations!" << endl;
					cout << (*this); //show final board
					break;
				}
			} if (turn == 43) { //all the spaces are filled
				cout << "There was no winner, it's a tie." << endl;
				break;
			}
		}
	} else if ( choice == 2 ) {
		while (1) { 	//there are 42 holes, so there are up to 42 turns
			if ( turn%2 == 1) {	//player 1's turn
				cout << (*this); //display the current board
				cout << "Player 1, which column would you like to place a piece? To end the game, put -1." << endl;
				cout << "Column:";
				cin >> position;
				if ( position == -1 ) {
					cout << "The game will now end." << endl;
					break;
				}
				while ( position < 1 || position > 7 ) {	//invalid position since it's not within the allowed columns
					cout << "That position is invalid. Please enter a position from 1~7." << endl;
					cin >> position;
				} if (Board[position-1].isFull() == false) { //if the column has an empty space
					Board[position-1]+=('X'); //'X' for player 1
					turn++;
				}
				if (winner() == true) {
					cout << "Player 1 has won the game. Congratulations!" << endl;
					cout << (*this); //show final board
					break;
				}
			} else if( turn%2 == 0) {	//computer's turn
				cout << (*this);	//display the current board
				cout << "The computer will now make a move." << endl;
				position = (rand()%7)+1; //generates a random position from 1-7
				if (Board[position-1].isFull() == false) { //if column has an empty space
					Board[position-1]+=('O'); //'O' for player 2
					turn++;
				} if (winner() == true) {
					cout << "The computer has won the game. Try again next time!" << endl;
					cout << (*this); //show final board
					break;
				}
			} if (turn == 43) { //all the spaces are filled
				cout << "There was no winner, it's a tie." << endl;
				break;
			}
		}
	}

}

bool C4Board::winner() {	//function to check if there's a winner, if there is a winner return true
	int col, row;

	for ( col=0; col<=6; col++ ) { //check vertically
		for( row=0; row<=2; row++ ) {
			if (Board[col].getDisc(row) != ' ' && Board[col].getDisc(row) == Board[col].getDisc(row+1)) { //two in a row
				if (Board[col].getDisc(row+1) == Board[col].getDisc(row+2)) { //three in a row
					if (Board[col].getDisc(row+2) == Board[col].getDisc(row+3)) { //four in a row
						cout << "Four in a vertical row!" << endl;
						return true;
					}
				}
			} 
		}
	}

	for ( col=0; col<=3; col++ ) { //check horizontally
		for( row=0; row<=5; row++ ) {
			if (Board[col].getDisc(row) != ' ' && Board[col].getDisc(row) == Board[col+1].getDisc(row)) { //two in a row
				if (Board[col+1].getDisc(row) == Board[col+2].getDisc(row)) { //three in a row
					if (Board[col+2].getDisc(row) == Board[col+3].getDisc(row)) { //four in a row
						cout << "Four in a horizontal row!" << endl;
						return true;
					}
				}
			}
		}
	}
	
	for ( col=0; col<=3; col++ ) { //check diagonally '/'
		for( row=0; row<=2; row++ ) {
			if (Board[col].getDisc(row) != ' ' && Board[col].getDisc(row) == Board[col+1].getDisc(row+1)) { //two in a row
				if (Board[col+1].getDisc(row+1) == Board[col+2].getDisc(row+2)) { //three in a row
					if (Board[col+2].getDisc(row+2) == Board[col+3].getDisc(row+3)) { //four in a row
						cout << "Four in a diagonal row right!" << endl;
						return true;
					}
				}
			}
		}
	}	

	for ( col=0; col<=3; col++ ) { //check diagonally '\'
		for( row=5; row>=3; row-- ) {
			if (Board[col].getDisc(row) != ' ' && Board[col].getDisc(row) == Board[col+1].getDisc(row-1)) { //two in a row 
				if (Board[col+1].getDisc(row-1) == Board[col+2].getDisc(row-2)) { //three in a row
					if (Board[col+2].getDisc(row-2) == Board[col+3].getDisc(row-3)) { //four in a row
						cout << "Four in a diagonal row left!" << endl;
						return true;
					}
				}
			}
		}
	}

	return false; //if none of the checks return true, then return false (there is no four in a row)
}

void C4Board::setnumCol( int number ) {
	numCol = number;
}




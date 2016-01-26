#ifndef C4BOARD_H
#define C4BOARD_H

//Emily Koh
#include <iostream>
#include <stdbool.h> //for bool
#include "C4Col.h"
using namespace std;

class C4Board {

	friend ostream &operator<<( ostream &, C4Board& board ); //overload << operator so that cout << board can actually display the board - parameters: what array to use to store the output, what class to act on (goes before public or private categories)

	public:
		C4Board();	//default constructor
		~C4Board();	//default deconstructor
		void setnumCol( int number );
		
		//void display();	//displays the current board in simple text
		void play();	//allows two players to play a game, input is the number turn it is
		

	private:
		int numCol;	//number of columns
		C4Col Board[7];	//pointer; array of C4Col objects to represent the Connect 4 Board, creates 7 objects of Class C4Col with currentdiscs as 0 and maxdiscs as 6 (connect the four board is empty and there's six rows) - this creates 7 columns 
		bool winner();
};

#endif
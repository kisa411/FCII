/* Emily Koh
FCII Final Project
Spring 2016
Alphabet Puzzle Class
*/
#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
using namespace std;

class AlphabetPuzzle {

public:
	AlphabetPuzzle(); //default constructor
	void displayPuzzle(); //display the puzzle picture
	int playPuzzle(); //check for user input and see if input is correct
    bool init(); //Starts up SDL and creates window - function prototype
    bool loadMedia( string filename ); //Loads media - function prototype
    void close(); //Frees media and shuts down SDL - function prototype


private:
	int points; //depending on how many tries it took player to get right answer, points value changes

};


#endif
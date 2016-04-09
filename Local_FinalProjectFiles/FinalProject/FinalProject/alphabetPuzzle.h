/* Emily Koh
FCII Final Project
Spring 2016
Alphabet Puzzle Class
*/
#ifndef ALPHABETPUZZLE_H
#define ALPHABETPUZZLE_H
#include <iostream>
using namespace std;

class AlphabetPuzzle {

public:
	AlphabetPuzzle(); //default constructor
	void displayPuzzle(); //display the puzzle picture
	int playPuzzle(); //check for user input and see if input is correct
    bool loadMedia();

private:
	int points; //depending on how many tries it took player to get right answer, points value changes
    LTexture backgroundImage;
    LTexture statements;

};


#endif
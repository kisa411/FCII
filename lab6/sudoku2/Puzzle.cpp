
#include "Puzzle.h" 
#include <string>
#include <vector> 
#include <fstream> //for reading in the txt file
#include <sstream> //for reading from a string
#include <iostream>
using namespace std;

//non-default constructor
Puzzle::Puzzle(string name) {

	
/*		------Initialize------		*/

	//counters
	int i,j,k;

	//explicitly allocate space in grid
	for (i=0; i<9; i++) {
		grid.push_back(intvec());
	}

	//initialize possValues
	intvec temp1(9,1); 
	int2vec temp2(9, temp1);
	int3vec temp3(9, temp2);

	possValues = temp3;			


/*		------Read from txt file------		*/


	//open up appropriate fstream and open file with the given name string
	ifstream readFile;
	readFile.open( name.c_str() );

	//make sure file opens
	if(!readFile.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	//use tempory string and vector of strings to read in and store from the file
	string line;
	vector <string> temp;
	while (getline(readFile, line)) {
		temp.push_back(line);
	}
	
	//close the file
	readFile.close();

	grid.resize(9);
	possValues.resize(9);


/*		------Store data from txt file into grid------		*/


	//use stringstream to read from temp
	for (i=0; i<9; ++i) {

		string s = temp[i];
		istringstream stringin(s);
		int c;	
	
		for (j=0; j<9; ++j) {

			stringin >> c;
			grid[i].push_back(c);

		} //end second for loop

	} //end first for loop
	
}

//prints the current state of the sudoku board
void Puzzle::printGrid() {

	cout << endl;
	for (int i=0; i<9; i++) {
		if (i == 3 || i == 6) {

			//for appearance, add horizontal border to separate mini grids
			for (int k=0; k<22; k++) {
			cout << " ";
			}
			cout << endl;
		}

		for (int j=0; j<9; j++) {

			if (grid[i][j]==0 || grid[i][j]=='0') {
			   cout << "*"; //substitute * for 0
			} else {
			   cout << grid[i][j];
			}
			if (j==2 || j==5) {
			   cout << "   ";
			} else {
			   cout << " ";
			} 
		}
		cout << endl;
	}
	cout << endl;
}

//prints all possible values for each spot in grid. For testing/debugging.
void Puzzle::printPossValues() {
	cout << endl;
	
	for (int i=0; i<9; i++) {
	   for (int j=0; j<9; j++) {
	      for (int k=0; k<9; k++) {
		  if (possValues[i][j][k]==1) {
		     cout << "In row " << i+1 << " and col " << j+1
		     << ", " << k+1 << " is a possible value." << endl;
		  } else {
		     cout << "***" << endl;
		  }

	      }
		 cout << endl;
	   }
	} 
	
	cout << endl;
}

//solves sudoku puzzle using basic and singleton (coming soon)
void Puzzle::Solve() {
	int counter=0;
	while(isComplete()==0 && counter<1000) {
		basicSolve();
		singletonSolve();
		counter++;
	}
	if (isComplete()==0) {
		cout << "Puzzle could not be solved using this program's algorithms." << endl;
	}
}


/*     ----Private Functions----      */


//sets appropriate slot in possValues to 0.
void Puzzle::eliminatePoss(int i, int j, int k) {
	possValues[i][j][k]=0;
}

//Uses possValues to fill in any solved spots in the grid.
void Puzzle::possFill() {
	int i,j,k;
	for (i=0; i<9; i++) {
	   for (j=0; j<9; j++) {
	      int counter=0;
	      int digit;
	      for (k=0; k<9; k++) {
			 if (possValues[i][j][k]==0) {
			    ++counter;
			 } else {
			    digit=k+1; //record for later, if counter==8, and offset by 1 for real board.
			 }
	      }
	      if (counter==8) { //all values expect one are invalid (found correct value)
		 makeMove(i,j,digit);
		 eliminatePoss(i,j,digit-1);
	      }
	   }
	}
		 
}

//returns true if the move is valid by duplicity in row, col, and minigrid
int Puzzle::validMove(int i,int j,int digit) {			

	//intialize counters
	int k,l;
	
	//check if in grid
	if (i>8 || i<0 || j>8 || j<0) {
		return 0;
	}

	//check if valid digit input
	if(digit>8 || digit<0) {
		return 0;
	} 

	//check if free space
	if (grid[i][j]!=0) {
		return 0;
	}

	//check row
	for (k=0; k<9; k++) {
		if (grid[i][k]==digit+1) {
			return 0;
		}
	}

	//check col
	for (k=0; k<9; k++) {
		if (grid[k][j]==digit+1) {
			return 0;
		}
	}

	//check minigrid

	//intialize variables for the for loop conditions
	int horizBegin=0;
	int horizEnd=0;
	int vertiBegin=0;
	int vertiEnd=0;

	//run through loop 3 times to check for each grid horizontally/vertically
	for (k=0; k<3; k++) {
		if ( i>=k*3 && i<(k+1)*3 ) {
			horizBegin = k*3;
			horizEnd = (k+1)*3;
		}
		if ( j>=k*3 && j<(k+1)*3 ) {
			vertiBegin = k*3;
			vertiEnd = (k+1)*3;
		}
	}

	for (k=horizBegin; k<horizEnd; k++) {
		for (l=vertiBegin; l<vertiEnd; l++) {
			if (grid[k][l]==digit+1) {
				return 0;
			}
		}
	}
	return 1; 
}

//uses validMove (above) to determine which possValues to eliminate, and then updates grid
void Puzzle::basicSolve() {
	int i,j,k;
	for (i=0; i<9; i++) {
	   for (j=0; j<9; j++) {
	      for (k=0; k<9; k++) {
	         if (validMove(i,j,k)==0) {
		    eliminatePoss(i,j,k);
		 }
	      }
	   }
	}
	possFill();
}

//updates grid based on singletons determined by possValues
void Puzzle::singletonSolve() {

	for (int i=0; i<9; i++) { //check for each row
	   for(int k=0; k<9; k++) { //check for each digit

	      int counter=0; //will be 1 if singleton
	      int rowNum; //for recording row of singleton
   	      int colNum; //for recording col of singleton
   	      int singleton;

	      for(int j=0; j<9; j++) { //go through 9 entries of row
	      	if(possValues[i][j][k]==1) {
	      		counter++;
	      		rowNum=i;
	      		colNum=j;
	      		singleton=k+1;
	      	}
	      }
	      if (counter==1) {
	      	if (validMove(rowNum,colNum,singleton-1)!=0){
	      		makeMove(rowNum,colNum,singleton);
	      	}
	      }
	  }
	}

}


//puts the input digit into the grid at i, j
void Puzzle::makeMove(int i, int j, int digit) {
	grid[i][j]=digit;
}

//returns true if the grid is full
int Puzzle::isComplete() {

	//determine if grid is full
	int i,j,k;
	int counter = 0;
	for (i=0; i<9; i++) {
		for (j=0; j<9; j++) {
			if (grid[i][j]==0) {
				++counter;
			}
		}
	}
	
	//return true if grid is full
	if (counter==0) {
		return 1;
	}

	return 0;

}

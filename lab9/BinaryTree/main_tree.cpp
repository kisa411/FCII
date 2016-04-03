#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "binaryTree.h"
#include "Node.h"

using namespace std;

int main ( int argc, char *argv[] ) { //read in the name of the file from command line (argc = number of words in command line, argv[] = stores the actual words used in command line)

	BinaryTree<int> bracket;

 	Node<int>* node;
 	Node<int>* firstNode; 

	//set up for reading from the textfile
	bracket.createTree( "bracket.txt" ); 

	bracket.finalFour();
	cout << endl;
	bracket.finalTwo();
	cout << endl;
	bracket.champion();	
	cout << endl;


	//prove search function works
	bracket.searchResults( 10 ); 

	

	firstNode = bracket.getFirst(); //save the location of the root node of the bracket
	cout << "Bracket printed pre order: " << endl;
	bracket.preOrder( firstNode );
	cout << endl;

	firstNode = bracket.getFirst(); //save the location of the root node of the bracket
	cout << "Bracket printed in order: " << endl;
	bracket.inOrder( firstNode );
	cout << endl;

	firstNode = bracket.getFirst(); //save the location of the root node of the bracket
	cout << "Bracket printed post order: " << endl;
	bracket.postOrder( firstNode );
	cout << endl;



	return 0;
}
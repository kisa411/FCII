#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctype.h>


using namespace std;

int main () { 
	map<string, int> englishMap;
	map<string, int> frenchMap;
	string word, filename;
	int loop = 0, i=0;
	char c; 

	//make a map of english dictionary 
	cout << "Reading english dictionary..." << endl;
	filename = "english.txt";
	//read in files
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> word; //take the first thing (until space) and put it in key 
			for ( int j=0; j<word.length(); j++ ) {
		    	// c=word[i];
		    	word[j]=(tolower(word[j]));
		    	j++;
  			}//convert all the letters to lower case
			if ( englishMap.find(word) == englishMap.end() ) {  //if the key is not yet in the map
				englishMap.insert(pair<string, int>( word, 1 )); //insert the new key and default count value is 1
			} else { //if the key is in the map already
				englishMap[word]++; //just increment the number of occurrences of the key
			}		
		}

		loop = 1;

		stream.close(); //close file after done reading from it
	}


	//make a map of french dictionary
	cout << "Reading french dictionary..." << endl;
	filename = "french.txt";
	loop=0;
	//read in files
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> word; //take the first thing (until space) and put it in key
			for ( int j=0; j<word.length(); j++ ) {
		    	// c=word[i];
		    	word[j]=(tolower(word[j]));
		    	j++;
  			}//convert all the letters to lower case
			if ( frenchMap.find(word) == frenchMap.end() ) {  //if the key is not yet in the map
				frenchMap.insert(pair<string, int>( word, 1 )); //insert the new key and default count value is 1
			} else { //if the key is in the map already
				frenchMap[word]++; //just increment the number of occurrences of the key
			}		
		}

		loop = 1;

		stream.close(); //close file after done reading from it
	}

	//read in a test file and test against english and french dictionaries
	cout << "What's the name of the test file?" << endl;
	cin >> filename;
	loop=0;

	int french=0, english=0;
	//read in files
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> word; //take the first thing (until space) and put it in key
			// transform( word.begin(), word.end(), word.begin(), ::tolower); 
			for ( int j=0; j<word.length(); j++ ) {
		    	word[j]=(tolower(word[j]));
		    	j++;
		    }
  			//convert all the letters to lower case
			if ( frenchMap.find(word) != frenchMap.end() ) {  //if the key is in the french dictionary, increment the french word occurrence
				french++;
				cout << "word: " << word << endl;
				cout << "french " << french << endl;
			} else if ( englishMap.find(word) != englishMap.end() ) { //if the key is in the english dictionary, increment the english word occurrence
				english++;
				cout << "word: " << word << endl;
				cout << "english " << english << endl;
			} else {
				cout << "This word is not in either dictionary." << endl;
			}		
		}

		loop = 1;

		stream.close(); //close file after done reading from it
	}

	//compare the word occurrences
	if ( french>english ) {
		cout << french << " " << english << endl;
		cout << "This article is in french." << endl;
	} else if ( english>french ) {
		cout << french << " " << english << endl;
		cout << "This article is in english." << endl;
	} else {
		cout << "I couldn't tell what language this article is in." << endl;
	}



	return 0;


}
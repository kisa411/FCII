#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctype.h>


using namespace std;

int main () { 
	map<string, int> wordMap;
	string word, filename;
	int loop = 0, i=0;
	char c; 

	cout << "What's the name of the first file?" << endl;
	cin >> filename;
	//read in files
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> word; //take the first thing (until space) and put it in key
			// transform( word.begin(), word.end(), word.begin(), static_cast<int(*)(int)>(std::tolower)); 
			for ( int j=0; j<word.length(); j++ ) {
		    	// c=word[i];
		    	word[j]=(tolower(word[j]));
		    	j++;
  			}//convert all the letters to lower case
			if ( wordMap.find(word) == wordMap.end() ) {  //if the key is not yet in the map
				wordMap.insert(pair<string, int>( word, 1 )); //insert the new key and default count value is 1
			} else { //if the key is in the map already
				wordMap[word]++; //just increment the number of occurrences of the key
			}		
		}

		//display the number of unique words in the first file
		cout << "The number of unique words in this file is: " << wordMap.size() << endl;

		wordMap.clear(); //empty the map container
		loop = 1;

		stream.close(); //close file after done reading from it
	}

	cout << "What's the name of the second file?" << endl;
	cin >> filename;
	loop=0;
	//read in files
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> word; //take the first thing (until space) and put it in key
			// transform( word.begin(), word.end(), word.begin(), ::tolower); 
			for ( int j=0; j<word.length(); j++ ) {
		    	// c=word[i];
		    	word[j]=(tolower(word[j]));
		    	j++;
  			}//convert all the letters to lower case
			if ( wordMap.find(word) == wordMap.end() ) {  //if the key is not yet in the map
				wordMap.insert(pair<string, int>( word, 1 )); //insert the new key and default count value is 1
			} else { //if the key is in the map already
				wordMap[word]++; //just increment the number of occurrences of the key
			}		
		}

		
		//display the words and their counts
		for ( map<string, int>::const_iterator it = wordMap.begin(); it!=wordMap.end(); ++it ) { //set up an iterator
			cout << it->first << " " << it->second << " " << endl; //print out the map values (it->first = key, it->second = element)
		}

		

		wordMap.clear(); //empty the map container
		loop = 1;

		stream.close(); //close file after done reading from it
	}


	return 0;


}
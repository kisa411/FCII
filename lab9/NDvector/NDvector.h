#ifndef NDVECTOR_H
#define NDVECTOR_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T> //using templates to make the program generic - make it work for numbers and characters
class NDvector {

	// friend ostream &operator<<( ostream &output, NDvector<T> &vectorArray ); //overload << operator so that cout << board can actually display the board - parameters: what array to use to store the output, what class to act on (goes before public or private categories)

public:
	NDvector( int number=10 ); //constructor
	NDvector<T> operator=( const NDvector &copy ); //override assignment operator
	T operator[]( int index ) const; //random access function
	NDvector( const NDvector &original ); //copy constructor
	~NDvector(); //deconstructor
	void push_back( T element ); //T - element to add to back of vector
	void pop_back(); //remove element from back
	int getSize() const; //return the number of elements in the vector
	T back(); //return the last element, but do not remove from vector
	void clear(); //clear the vector
	void shuffle(); //shuffle the vector

private:
	int size, maxSize;
	T *vector; //make a vector that contains a reference to elements - pointer to T

};

// template <typename T>
// ostream &operator<<( ostream &output, NDvector<T> &vectorArray ) { //overload << operator to display the elements of the card deck


// 	for( int i=0; i<vectorArray.getSize()-2; i++ ) { 
// 		output << vectorArray[i] << ", "; 
// 	}

// 	output << vectorArray[vectorArray.getSize()-1];
// 	cout << endl;

// 	return (output);

// }

template <typename T>
NDvector<T>::NDvector( int number ) { //fall-back value of 10 elements
	maxSize = number;
	size = 0; 
	vector = new T[maxSize]; //create an array and sets the pointer to the start of the array (vector is an array now)
	// for ( int i=0; i<maxSize; i++ ) { //initialize all the element values to 0
	// 	vector[i] = 0;
	// }

}

template <typename T>
NDvector<T> NDvector<T>::operator=( const NDvector &copy ) {  //overload assignment operator, make a copy of the copy vector into the original vector and then return the original vector 
	
	if ( maxSize != copy.getSize() ) { //if the vectors are of different sizes, then clear the vector and then re-allocate memory
		maxSize = copy.getSize();
		clear();
	}

	for ( int i=0; copy.getSize(); i++ ) {
		push_back( copy[i] );
	}
	return (*this); //returns reference to vector 
}

template <typename T>
T NDvector<T>::operator[]( int position ) const {  //overload random index operator
	if ( position<(size) ) { //if the position is a valid index
		//cout << vector[position] << endl;
		return vector[position];
	} else {
		cout << "size: " << size << endl;
		cout << "That's not a valid position" << endl;
	}
}

template <typename T>
NDvector<T>::NDvector( const NDvector &original ) {  //copy constructor

	if ( maxSize != original.getSize() ) { //if the vectors are of different sizes, then clear the vector and then re-allocate memory
		maxSize = original.getSize();
		clear();
	}

	for ( int i=0; original.getSize(); i++ ) {
		vector[i] = original[i];
	}
}

template <typename T>
NDvector<T>::~NDvector() {  //destructor
	delete[] vector;
}

template <typename T>
void NDvector<T>::push_back( T element ) { 
	if ( size == (maxSize-1) ) { //the vector is full and there are no more spots in the array
		maxSize*=2;
		clear();
	}
	vector[size]=element; //add the element to the end of the vector
	size++; //increase the count of the number of elements in the vector
}

template <typename T>
void NDvector<T>::pop_back() { 
	vector[size-1]=NULL; //remove the last element of the vector
	size--; //decrement the size since one element was removed from the vector
}

template <typename T>
int NDvector<T>::getSize() const { 
	return size;
}

template <typename T>
T NDvector<T>::back() { 
	return vector[size-1]; //return the last element of the vector
}

template <typename T>
void NDvector<T>::clear() { 

	T* vector2 = new T[maxSize];
	for ( int i=0; i<size; i++ ) { //copy over elements from previous vector
		vector2[i] = vector[i];
	}

	delete[] vector; //delete the current vector
	vector = vector2; //make a new vector
}

template <typename T>
void NDvector<T>::shuffle() { 

	// Use a different seed value so that we don't get same result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't need to run for the first element that's why i > 0
    for (int i = size-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        T temp = vector[i];
	    vector[i] = vector[j];
	    vector[j] = temp;
    }
}



#endif




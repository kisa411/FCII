#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;


template <typename T> //using templates to make the program generic - make it work for numbers and characters
class BinaryTree {

public:
	BinaryTree(); //constructor
	~BinaryTree(); //destructor
	Node<T> *getFirst(); //return the first node
	// void insert( T key, Node<T> *leaf ); //add a new node to the binary tree
	Node<T> *search( T query, Node<T> *root ); //search function to look for specific value
	void searchResults( T query );
	void createTree( string filename );
	void inOrder( Node<T> *root ); //traverse tree and print out values in order 
	void preOrder( Node<T> *root ); //traverse tree and print out values preorder
	void postOrder( Node<T> *root); //traverse tree and print out values postorder
	void finalFour(); //print the labels of the final four
	void finalTwo(); //print the labels of the final two
	void champion(); //print the label of the champion
	Node<T> *chooseWinner( Node<T> *node1, Node<T> *node2 ); //set the key and label of the parent node to the child node with bigger key

private:
	Node<T> *first;                // first element in the list
  	Node<T> *newNode(const T &, string s);   // helper function; creates a new node

};

template <typename T>
BinaryTree<T>::BinaryTree() { 
	first = NULL; //set the first element to null when you create the first binary tree
}

template<typename T>
BinaryTree<T>::~BinaryTree() { //destructor
 	if (first!=NULL) { // follow the links, clobbering as we go
 	Node<T> *p=first;

	    while (p != NULL) { //while you're not at the first node - delete left subtree
	     	Node<T> *left = p->left; // retrieve this node's "left" subtree nodes before we clobber it
	     	delete p;
	     	p = left;
	    };

	    while (p != NULL) { //while you're not at the first node - delete right subtree
	      	Node<T> *right = p->right; // retrieve this node's "right" subtree nodes before we clobber it
	       	delete p;
	       	p = right;
	    };
  	}
}

template <typename T>
Node<T>* BinaryTree<T>::getFirst() { 
	return first;
}


template <typename T>
void BinaryTree<T>::createTree( string filename ) {
	queue<Node<T> > bracket;
	int key, loop = 0;
	string label; 

	//read in lines from textfile - (key, label)
	while ( loop == 0 ) {
		//argv[1] is the name of the file to open
		ifstream stream( filename.c_str() ); //open the file that was input in command line
		while( !stream.eof() ) { //while EOF of file is not reached
			stream >> key; //take the first thing (until space) and put it in key
			stream >> label; //take the next thing (until space) and put it in label
			Node<int> *node = newNode( key, label ); //instantiate new node object
			bracket.push( *node ); //add newly created node to bracket queue
		}
		loop = 1;

		stream.close(); //close file after done reading from it
	}

	

	//implement a queue - first in first out
	
	Node<T> *parent, *node1, *node2;

	//initial queue contains nodes with key and label - as read in file, create node and push node into queue
	//take the first two nodes

	while ( bracket.size() != 1 ) {
		node1 = &bracket.front(); //first thing out of the queue is the parent's left child
		bracket.pop();

		node2 = &bracket.front(); //second thing out of the queue is the parent's right child
		bracket.pop();
		
		parent = chooseWinner( node1, node2 );
		//push parent node to end of queue
		bracket.push( *parent );
	} 

	first = &bracket.front(); //the only thing left in the queue is the overall root node
}

template <typename T>
Node<T>* BinaryTree<T>::search( T query, Node<T> *root ) {  //query - node to look for
	if ( root!=NULL ) { //if the node the search is starting from 
		if ( query==(root->getData()) ) { //if the first node's label matches the query label
			return root; //return the first node
		} if ( query < root->getData() ) { //if the query searching for is less than the first node's label, search the left side
			cout << root->getLabel() << endl;
			return search( query, root->getLeft() );
		} else { //if the query searching for is greater than the first node's label, search the right side
			cout << root->getLabel() << endl;
			return search( query, root->getRight() ); 
		}
	} else {
		return NULL; //the node couldn't be found even at the very end of the binary tree, node with given query doesn't exist
	}
}

template <typename T>
void BinaryTree<T>::searchResults( T query ) {
	Node<T> *found = search( query, first );
	cout << "Found pokemon was: " << found->getLabel() << endl;
}

template <typename T>
void BinaryTree<T>::preOrder( Node<T> *root ) {
	if ( root!=NULL ) { //if the first node has child nodes
		cout << root->getLabel() << " "; //print out the node's data
		preOrder( root->getLeft() ); //traverse the left subtree until you reach null (no more child nodes)
		// cout << "here" << endl;
		preOrder( root->getRight() ); //traverse the right subtree until you reach null (no more child nodes)
		// cout << "here2" << endl;
	}
}

template <typename T>
void BinaryTree<T>::postOrder( Node<T> *root ) { 
	if ( root!=NULL ) { //if the first node has child nodes
		postOrder( root->getLeft() ); //traverse the left subtree until you reach null (no more child nodes)
		postOrder( root->getRight() ); //traverse the right subtree until you reach null (no more child nodes)
		cout << root->getLabel() << " "; //print out the node's data
	}
}

template <typename T>
void BinaryTree<T>::inOrder( Node<T> *root ) { 
	if ( root!=NULL ) { //if the first node has child nodes
		inOrder( root->getLeft() ); //traverse the left subtree until you reach null (no more child nodes)
		cout << root->getLabel() << " "; //print out the node's data
		inOrder( root->getRight() ); //traverse the right subtree until you reach null (no more child nodes)
	}
}

// utility function to create a node
template<typename T>
Node<T> *BinaryTree<T>::newNode(const T &value, string s) {
 	
 	return new Node<T>(value, s); //create a new node instance with the given value and string label
}


template <typename T>
void BinaryTree<T>::finalFour() { //print out the final four winners

	cout << "The final four are: " << endl;

	cout << first->left->left->label << endl;
	cout << first->left->right->label << endl;
	cout << first->right->left->label << endl;
	cout << first->right->right->label << endl;

}

template <typename T>
void BinaryTree<T>::finalTwo() { //print out the final two winners
	
	cout << "The final two are: " << endl;
	cout << first->left->label << endl;
	cout << first->right->label << endl;
}

template <typename T>
void BinaryTree<T>::champion() { //print out the champion
	cout << "The final champion is: " << endl;
	cout << first->label << endl;
}

template <typename T>
Node<T> *BinaryTree<T>::chooseWinner( Node<T> *node1, Node<T> *node2 ) { 
	 
	//compare values and then set the bigger node to parent node
	//set parent left and child nodes

	Node<T> *root = newNode( node1->key, node1->label );

	if ( node1->key >= node2->key ) { //node1 wins
		root->left = node2; //root's left child becomes node2
		root->right = node1; //root's right child becomes node1
	} else { //node2 wins
		root->key = node2->key;
		root->label = node2->label;
		root->left = node1;
		root->right = node2;
	}
	
	return root;
}


#endif







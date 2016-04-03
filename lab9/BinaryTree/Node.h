#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

template<typename T> class BinaryTree; // forward declaration of List

template<typename T>   // templated node type
class Node {

  friend class BinaryTree<T>;    // make the main class a friend

 public:
  Node(const T &info = 0, string = NULL);     // constructor
  T getData() const;   // get function
  string getLabel() const;   // get function
  Node<T> *getLeft() const;   // get function
  Node<T> *getRight() const;   // get function

 private:
  T key;           // data for linked list node
  string label;		// string label
  Node<T> *right;   // pointer to right child
  Node<T> *left; 	// pointer to left child
};


// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(const T &info, string s) :key(info),right(NULL), left(NULL), label(s) {}

// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { 
	return key; 
}

template<typename T>
string Node<T>::getLabel(void) const { 
	return label; 
}

template<typename T>
Node<T> *Node<T>::getLeft(void) const { 
	return left; 
}

template<typename T>
Node<T> *Node<T>::getRight(void) const { 
	return right; 
}

#endif






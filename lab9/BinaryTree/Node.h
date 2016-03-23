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
  Node(const T &, string s);     // constructor
  T getData() const;   // get function

 private:
  T data;           // data for linked list node
  string label;		// string label
  Node<T> *right;   // pointer to right child
  Node<T> *left; 	// pointer to left child
};


// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(const T &info, string s) :data(info),right(NULL), left(NULL), label(s) {}

// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { 
	return data; 
}

#endif






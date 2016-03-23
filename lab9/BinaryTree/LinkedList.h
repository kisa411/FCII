#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"     // contains the node information
#include <iostream>   // for using cout

using namespace std;

template<typename T>    // templated class
class LinkedList {
public:
  LinkedList();    // constructor
  ~LinkedList();   // deconstructor
  void appendNode(const T &, string s);   // add a node to end of list
  bool removeEndNode(T &);      // remove the end of the list
  bool removeFrontNode (T &);   // remove the front of the list
  bool empty();                 // if the list is empty
  void print();                 // display contents of the list
  int nodeCount();              // how many nodes are in the list
  // void prependNode(const T &, string s);  // add node to the front of the list

private:
  Node<T> *first;                // first element in the list
  Node<T> *newNode(const T &);   // helper function; creates a new node
};

// constructor (empty body)
template<typename T>
LinkedList<T>::LinkedList() :first(NULL) {}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
 if (!empty()) { // follow the links, clobbering as we go
  Node<T> *p=first;

    while (p != NULL) {
     Node<T> *left = p->next; // retrieve this node's "left" subtree nodes before we clobber it
     delete p;
     p = next;
    };
     while (p != NULL) {
       Node<T> *right = p->next; // retrieve this node's "right" subtree nodes before we clobber it
       delete p;
       p = next;
    };
  }
}

/*TODO*/
template<typename T>
void LinkedList<T>::appendNode(const T &data, string s) {
 // allocate a new node, copying supplied data into it.
 Node<T> *nn  = newNode(data, s);

 if (empty()) { // make a new node
  first = nn;
}
 else { // list already has nodes
  Node<T> *p = first;
  while (p->next != NULL) p = p->next; // go to end of list
  p->next = nn;
}

 nn->next = NULL; // be safe
}

/*TODO*/
template<typename T>
bool LinkedList<T>::removeEndNode(T &result) {
 // 3 cases here.
 // 1. List is empty: return false.
 // 2. List has one element: set first = NULL, clobber first node
 //    (save its value before clobber and return it)
 // 3. List has >1 element: find node BEFORE end; copy end node data;
 //    fixup pointer in node before end; clobber last node.

 if (empty()) {
  //cout << "empty!" << endl;
  return false;
  } // case 1
 else if (first->next == NULL) { // case 2
  result = first->data;
  delete first;
  first = NULL;
  //cout << "case2!" << endl;
  return true;
}
else {
  // otherwise, case 3
  Node<T> *p = first;
  while (p->next->next != NULL) p = p->next; // woo!
  //cout << hex << "case3: p is " << (int)p << " successor value " 
  //     << p->next->getData() << endl;
  // when we get here, p points to the node before the last node.
  result = p->next->data;
  delete p->next;
  p->next = NULL;
  return true;
}
}

// predicate: is this list empty?
template<typename T>
bool LinkedList<T>::empty() { return (first == NULL); }

// utility function to create a node
template<typename T>
Node<T> *LinkedList<T>::newNode(const T &value, string s) {
 return new Node<T>(value, s);
}

// debug function for printing contents and pointer values
template<typename T>
void LinkedList<T>::print() {
   Node<T> *p=first;
   for( ; p != NULL; p = p->next) {
    cout << p->getData() << endl;
  }
}

template<typename T>
int LinkedList<T>::nodeCount(void) {
 int n=0;
 for(Node<T> *p = first; p != NULL; p = p->next) n++;
   return n;
}

// template<typename T>
// void LinkedList<T>::prependNode (const T &value) {
//  Node<T> *x = newNode(value);

//  x->next = first;
//  first = x;
// }

#endif



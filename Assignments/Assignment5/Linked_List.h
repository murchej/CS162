/**********************************************************************
 * Program Name: assign5.cpp
 * Author: Joseph Murche
 * Date: 6/2/21
 * Description: Creates linked lists and sorts using merge sort ascending or descending
 * Input: int
 * Output: ints, strings
 ***********************************************************************/
#ifndef LL_H
#define LL_H

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;


class Linked_List {
private:
   unsigned int length; // the number of nodes contained in the list
   Node *head; // a pointer to the first node in the list
   // anything else you need...
public:
   int get_length();
   Linked_List();
   ~Linked_List();
   // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   void print(); // output a list of all integers contained within the list
   void clear(); // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
   unsigned int insert(int j, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
   void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
   // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
   void sort_descending(); // sort the nodes in descending order
   // you can add extra member variables or functions as desired
    void merge_sort_ascending(Node **);
    void merge_sort_descending(Node **);
    Node* merge_ascend(Node *, Node *);
    Node* merge_descend(Node *, Node *);
    bool prime(int);
    int prime_n_amount(); //returns primes in list
    void print_prime_n(); // prints primes in list
    void swap(Node **, Node *, Node *, Node *);
    void splitup(Node *, Node **, Node **);
};



#endif
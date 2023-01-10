/**********************************************************************
 * Program Name: assign5.cpp
 * Author: Joseph Murche
 * Date: 6/2/21
 * Description: Creates linked lists and sorts using merge sort ascending or descending
 * Input: int
 * Output: ints, strings
 ***********************************************************************/

#ifndef N_H
#define N_H

#include <iostream>
#include <cstdlib>

using namespace std;


class Node {
public:
   
   Node();
   int val;    // the value that this node stores
   Node *next; // a pointer to the next node in the list
   // you can add constructors or other functionality if you find it useful or necessary
};

#endif
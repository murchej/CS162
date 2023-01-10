/**********************************************************************
 * Program Name: assign5.cpp
 * Author: Joseph Murche
 * Date: 6/2/21
 * Description: Creates linked lists and sorts using merge sort ascending or descending
 * Input: int
 * Output: ints, strings
 ***********************************************************************/

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Linked_List.h"


using namespace std;



Linked_List::Linked_List(){ //constructor
  
  length = 0;
  head = new Node;

}


Linked_List::~Linked_List(){ //deconstructor
  
  Node *x;
  x = head;

    do{
    
    for (int i = 0; i < length; ++i){
      if (x->next != nullptr) 
      
      x = x->next; //function clears memory
      delete x;
      length--;
    }
  } while (length > 1);

  delete head;
}



int Linked_List::get_length(){ //accessor function for the length variable
  return length;
}



void Linked_List::print(){ //function for printing linked list
  
  Node *t = head;
  int x = 0;
  
  do {
    cout << t->val << " ";//prints the numbers side by side
    t = t->next;
    ++x;
  } while (x != length);
  
  cout << endl; //creates spacing
  t = nullptr;
  
}



void Linked_List::clear(){ //clears the list
  
  Node *x;
  x = head;

  do{
    for (int i = 0; i < length;++i){
      if (x->next != nullptr) x = x->next;
      
      delete x;
      length--;
    }
  } while (length > 1);
  
  head->next = nullptr;
  
  length = 0;
  head->val = 0;
  
}


unsigned int Linked_List::insert(int j, unsigned int index){ //inserts the elements in their respective index
  
  Node *x, *y = new Node;
  x = head;
  y->val = j; //pointers

   if(index > length)
  cout << "Error: You entered an invalid index." << endl; //check for valid input
   


  else{
  if (index == 1) 
    
    push_front(j);
    
    else {
      
      for (int i = 1; i < index - 1; ++i){
        if (x->next != nullptr) 
        x = x->next;
      }

      y->next = x->next;
      x->next = y;

      length++;
    } 
  }
}


unsigned int Linked_List::push_front(int j){ //function for adding a new element at front of the list

Node *x;
  
  if (length = 0) 
  head->val = j;
  
  else if(length > 0) {
    x = new Node;
    x->val = head->val;
    x->next = head->next;
    head->next = x;
    head->val = j;
  }

  length++; //increments nodes forward
}


unsigned int Linked_List::push_back(int p){ //function to add an element to the end of the list
  
  Node *x, *y = head;

   if (length == 0) {
    head->val = p;
  } 
  
  
    else if (length != 0) {
    
    for (int i = 0; i < length; ++i){
      if (y->next != nullptr) 
      y = y->next;
     
      else if(y->next == nullptr) {
        x = new Node;
        x->val = p;
        y->next = x;
      }
    }
  }
  
  length++;
}


void Linked_List::sort_ascending(){ //recursive function for merge sort in ascending order
  merge_sort_ascending(&head);
}


void Linked_List::merge_sort_ascending(Node **ref){ //actual merge sort function
  
  Node *topnode = *ref, *x, *y;
  
  if (topnode == nullptr || topnode->next == nullptr) 
  return;
  
  splitup(topnode, &x, &y);
  merge_sort_ascending(&x);
  merge_sort_ascending(&y);
  *ref = merge_ascend(x, y);
}


Node* Linked_List::merge_ascend(Node *x, Node *y){ //merge lists in ascending order
  
  if (x == nullptr) 
  return y;
  
  if (y == nullptr) 
  return x;

  Node *topnode = nullptr;
  
  if (x->val <= y->val) {
    topnode = x;
    topnode->next = merge_ascend(topnode->next, y);
  } 
  else {
    topnode = y;
    topnode->next = merge_ascend(topnode->next, x);
  }
  
  return topnode;
}



void Linked_List::splitup(Node *listnode, Node **x, Node **y){ //function for splitting list
 
  if (listnode == nullptr || listnode->next == nullptr){
    *x = listnode;
    *y = nullptr;
  } 
  
  else {
    
    Node *fast, *slow;
    fast = listnode->next;
    slow = listnode;

    if(fast != nullptr && fast->next != nullptr){
      
      fast = fast->next->next;
      slow = slow->next;
    } 
    
    *x = listnode;
    *y = slow->next;
    
    slow->next = nullptr;
  }
}



void Linked_List::sort_descending(){//recurvise descending function
  merge_sort_descending(&head);
}



Node* Linked_List::merge_descend(Node *x, Node *y){ //function for merge desced
  
  if (x == nullptr) 
    return y;
  
  if (y == nullptr) 
    return x;

  Node *topnode = nullptr;
  
  if (x->val >= y->val) {
    topnode = x;
    topnode->next = merge_descend(topnode->next, y);
  } 
  
  else {
    topnode = y;
    topnode->next = merge_descend(topnode->next, x);
  }
  
  return topnode;
}



void Linked_List::merge_sort_descending(Node **ref){ //function for descending merge sort
  
  Node *topnode = *ref, *x, *y;
  
  if (topnode == nullptr || topnode->next == nullptr) 
  return;
  
  splitup(topnode, &x, &y);
  merge_sort_descending(&x);
  merge_sort_descending(&y);
  *ref = merge_descend(x, y);
}



bool Linked_List::prime(int val){ //bool function, returns true if prime, using cstdlib functions
  
if(abs(val) == 1){
  return false;
}
  
  for (int i=2; i < abs(val); ++i){
    if (abs(val) % i == 0) 
    
    return false;
  }

  return true;

}



int Linked_List::prime_n_amount(){ //counts how many prime numbers there were
  
  Node *x = head;
  
  int i = 0;
  int num = 0;
   
    do{//do-while loop to check for number of prime integers
    if (prime(x->val)==true) num++;
    x = x->next;
    i++;
    }
    while (i != length);
    
    x = nullptr;
   return num;
  
 
}



void Linked_List::print_prime_n(){ //function for printing the prime numbers
  
  Node *x = head;
  int i = 0;
  
  do{  
    if (prime(x->val)==true){
      cout << x->val << " ";
    }
        x = x->next;
        ++i;
  }
  while (i != length);
  
  cout << endl;
  x = nullptr;
  cout << endl;

}

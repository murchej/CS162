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
#include "Linked_List.h"
#include "Node.h"

using namespace std;

int main(){

Linked_List Ll;
  
  int num;
  
  char c = 'y'; 
  char sort; //variable to store user response for sorting order
  char replay = 'y';
  



  do{
    cout << "Welcome to the Linked List Program!" << endl;
    cout << "Please enter a number: "; // asking user for initial value for the list
    cin >> num;
    Ll.push_back(num);
    ;

    while (c == 'y'){ // more values
      cout << "Do you want to add another number (y or n)? ";
      cin >> c;
      
      if (c == 'y') {
        cout << "Please enter a number: ";
        cin >> num;
        Ll.push_back(num);

      }
    }

    cout << "Your linked list is: "; //prints list
    Ll.print();
    

    
    
    cout << "Sort list in ascending or descending order (a or d)? ";
    cin >> sort;
    
    if (sort == 'a') {
      cout << "Sorting ascending." << endl;
      Ll.sort_ascending();
    } 
    
    else if (sort == 'd') {
      cout << "Sorting descending." << endl;
      Ll.sort_descending();
    }

    
    
    cout << "Your linked list is: ";
    Ll.print();
    
    cout << "You have " << Ll.prime_n_amount() << " prime number(s) in your list: ";
    Ll.print_prime_n(); //prints prime numbers

    cout << "Would you like to go again (y or n)? ";
    cin >> replay;
    
    
    if (replay == 'y') {
      c = 'y';
      Ll.clear();
    }
  }

  while(replay == 'y'); //end of do while loop for game

  Ll.~Linked_List(); //clear memory



    return 0;
}
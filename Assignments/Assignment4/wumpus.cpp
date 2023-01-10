/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include <iostream>
#include "wumpus.h"
#include "event.h"

using namespace std;

wumpus::wumpus(){ //wumpus class
  
}

void wumpus::percept(){
  cout << "You smell a terrible stench." << endl;
}

void wumpus::encounter(){
  /*cout << "You enter the same room as the sleeping Wumpus.\n";
  cout << "You disturbed his slumber...\n";
  cout << "He awakes in a fury, he lets out a mighty roar and he devours you!\nGame Over.\n";*/
  
}
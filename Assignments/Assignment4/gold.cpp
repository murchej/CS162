/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include <iostream>
#include "gold.h"
#include "event.h"

using namespace std;

gold::gold(){
  
}

void gold::percept(){
  cout<< "You see a glimmer nearby." << endl; //reads out to player
}

void gold::encounter(){
  //cout << "You have found a huge room overflowing with gold!\n";
  //cout << "You load up as much gold as you can carry.\n";
}
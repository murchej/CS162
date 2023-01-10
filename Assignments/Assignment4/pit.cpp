/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include <iostream>
#include "pit.h"
#include "event.h"

using namespace std;

pit::pit(){
  
}

void pit::percept(){
  cout <<"You feel a breeze."<< endl; //reads out to player
}

void pit::encounter(){
  //cout << "You fall into a deep pit of sharp rocks.\n";
  //cout << "You did not stick the landing.\n";
  //cout << "Game Over." << endl;
}
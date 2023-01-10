/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

  
#ifndef BATS_H
#define BATS_H

#include <iostream>
#include <cstring>
#include "event.h"
#include "room.h"


using namespace std;

class bats : public event { //the bats class
  public:
    bats();
    void encounter();
    void percept();
};

#endif
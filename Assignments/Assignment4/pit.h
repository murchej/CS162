/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <string>
#include "event.h"
#include "room.h"

using namespace std;

class pit : public event { //class for the pit event
  
  public:
    pit();
    void encounter();
    void percept();
};

#endif
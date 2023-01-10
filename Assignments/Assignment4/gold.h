/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef GOLD_H
#define GOLD_H

#include <cstring>
#include "event.h"
#include "room.h"

using namespace std;

class gold : public event{ //gold class

    public:
    gold();
     void encounter();
     void percept();
};

#endif
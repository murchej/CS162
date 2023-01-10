/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <cstring>



using namespace std;

class event{
    public:
    event();
    virtual void encounter();
    virtual void percept();

    
};

#endif
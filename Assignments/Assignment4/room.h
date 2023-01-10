/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include "event.h"

using namespace std;

class room{ //the class containing the variables and functions for the rooms, events in the cave
    
    private:
        bool rope;
        bool event_t;
        event *e;
        string mark;

    public:
        room();
        ~room();
        room(int);
        string get_mark();
        bool get_event();
        void set_event(bool x);
        void percept();
        void encounter();
        bool get_rope();
        void set_rope(bool r);


};

#endif
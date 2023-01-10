/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "event.h"
#include "pit.h"
#include "room.h"

using namespace std;


//getters and setters for functions in the room class


room::room(){ //function fills rooms with different events
 mark = "  ";
 e = nullptr;
 event_t = false;
}

room::room(int x){
    switch(x){
		case 0: e = new gold; mark = " g "; break;
		case 1: e = new wumpus; mark = " w "; break;
		case 2: e = new bats; mark = " b "; break;
		case 3: e = new pit; mark = " p "; break;
	}
    event_t = true;
}


string room::get_mark(){
    return this->mark;
}

void room::set_event(bool x){
    this->event_t = x;
    
}

void room::percept(){
    this->e->percept();
}

bool room::get_event(){

    return this-> event_t;
}

bool room::get_rope(){
    return this-> rope;
}

void room::set_rope(bool r){
    this-> rope = true;
}

room::~room(){
    delete this-> e;

}




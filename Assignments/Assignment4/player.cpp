/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "event.h"

using namespace std;

//grid position setter and getter
void player::setxg(int j){
    this->xg = j;
}

void player::setyg(int j){
    this->yg = j;
}

player::player(){ //default constructor with 3 variables initialized
    arrows = 3;
    wumpus = false;
    gold = false;
}

void player:: reset_pos(){ //resets the position/coordinates to the initial state when the player enters the same cave
    this->arrows = 3;
    this->gold = false;
    this->wumpus = false;
    this->yg = inityg;
    this->xg = initxg;
}

player::player(int width){ //constructor for alternating (copy constructor)
    srand(time(NULL));

    arrows = 3;
    wumpus = false;
    gold = false; 

    int y = rand() % width;
    int x = rand() % width;

    initxg = x;
    inityg = y;
    xg = x;
    yg = y;
}
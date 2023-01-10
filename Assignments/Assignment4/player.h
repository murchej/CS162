/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "event.h"

using namespace std;


class player{
public:
    bool gold;
    bool wumpus;
    int arrows;

    int initxg;
    int inityg;
    int xg;
    int yg;

    player();
    player(int width);
    void setxg(int);
    void setyg(int);
    void set_gold(bool gld){this-> gold = gld;}
    bool get_gold() {return gold;}
    bool get_wump() {return wumpus;}
    void set_wump(bool w) {this-> wumpus = w;}
    void reset_pos();

};

#endif
/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#ifndef CAVE_H
#define CAVE_H

#include <iostream>
#include  <vector>
#include "player.h"
#include "room.h"
#include "event.h"
#include "gold.h"
#include "player.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"

class cave{
private:
    int width;
    player *playr;

    vector< vector<room> > wumpcave; //cave vector

public:
    cave();
    cave(int width);
    void playr_choice();
    void build_cave();
    void percept();
    void print_cave();
    void clear_cave();
    void fill_cave();
    void chk_prcpts();
    void playr_move();
    void find_playr();
    void shoot(); //fire arrow
    void miss(); //miss like an idiot
    void kill_wump();
    void report_game(int & run, bool debug);
    void chk_if_win(int & run);
    void chk_danger(int & run);
    void collect_gold();
    void replay(int & play, bool & samegame); //play game again
    void s_bats();
    void reset();
    
    int chk_up(int x);
	int chk_down(int x);
	int chk_right(int x);
	int chk_left(int x);




};

#endif
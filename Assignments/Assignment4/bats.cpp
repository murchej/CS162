/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/
#include <iostream>
#include "bats.h"
#include "event.h"

using namespace std;

bats::bats(){
   
    
}

void bats::percept(){
    cout << "You hear wings flapping." << endl;  //message to player about the bats
}

void bats::encounter(){ //where the player gets carried away by the super bats
    /*cout << "You enter a room crawling with scary Super Bats.\n"; 
    cout << "They swoop down and snatch you, and they carry you off to another room.\n";*/

}


/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main(){
 int playagain = 0;
    Game cardgame;
    Game();
    
    do {
        cardgame.get_string();
        cardgame.play();
        cardgame.check_winner();
        
        
        
        
        cout << "Would you like to play again? (1=No, 2 = Yes): ";
        cin >> playagain;

    }while(playagain == 2);
    
    
    return 0;
}
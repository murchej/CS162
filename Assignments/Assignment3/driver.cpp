/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/
#include <iostream>
#include <string>
#include "animal.h"
#include "Lemur.h"
#include "blackbear.h"
#include "Tiger.h"
#include "zoo.h"

using namespace std;

int main()
{
   Zoo game;

   Zoo();
   
   do{ //do while loop to keep program running until the user is done
       game.newMonth();
       game.sickanimal();
       game.randomevent();
       game.attendanceBoom();
       game.newbabyborn();
       game.buyanimal();
       game.payforfood();
       game.calculateRevenue();
       game.playerturn();
       game.~Zoo();
       
   }
    while(game.playerturn() == 1);

       
       game.~Zoo(); //all memory freed

   
   return 0;
}


/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "wumpus.h"
#include "gold.h"
#include "room.h"
#include "event.h"
#include "bats.h"
#include "cave.h"
#include "player.h"
#include "pit.h"

using namespace std;

int main(int argc, char * argv[]){
    
    int run = 1;
    int play = 1;

    bool samegame;

    if(argc != 3 || atoi(argv[1]) < 4){ //checks for valid command line argument
        cout << "The command line argument is invalid" << endl;
        return 0;
    }


    while(play == 1){
        cave map(atoi(argv[1]));
        map.build_cave();
        map.fill_cave();


        if(string(argv[2]) == "false"){
            while(run){
                map.report_game(run, false);
            }
            map.replay(play, samegame);

            if(play != 1){map.clear_cave(); break;}

            if(samegame){
                run = 1;
                map.reset();
                while(run){
                    map.report_game(run, false);
                }

            }

            else{
                map.clear_cave();
                cave map(atoi(argv[1]));
                map.build_cave();
                map.fill_cave();

                run = 1;

                while(run){
                    map.report_game(run, false);
                }
            }
        }

        else if(string(argv[2]) == "true"){
            while(run){
                map.report_game(run ,true);
            }
            map.replay(play, samegame);

            if(play != 1){map.clear_cave(); break;}

            if(samegame){
                run  = 1;
                map.reset();
                while(run){
                    map.report_game(run, true);
                }
            }

            else{
                map.clear_cave();
                
                cave map(atoi(argv[1]));
                
                map.build_cave();

                map.fill_cave();

                run = 1;

                while(run){
                    map.report_game(run, true);
                }
            }
        }

        else{
            cout << "Command line argument is invalid." << endl;
            play = 0;
        }
        
        }
    return 0;


}

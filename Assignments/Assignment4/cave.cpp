/********************************************************
 * Program Name: wumpus.cpp
 * Author: Joseph Murche
 * Date: May 21st, 2021
 * Description: play as an adventurer on a quest to get the gold from the wumpus cave.
 * Input: integers.
 * Output: integers and strings.
 ********************************************************/

#include "player.h"
#include "cave.h"
#include "room.h"
#include "wumpus.h"
#include "gold.h"
#include "event.h"
#include "bats.h"
#include "pit.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>

using namespace std;

cave::cave(){ //default cave constructor
    width = 0;
}


cave::cave(int width){ //copy constructor
    this->width = width;
    playr = new player(width);
}


void cave::playr_choice(){ //player choice function, for loop for choice
    int playrchoice;

    cout << "Please select what you would like to do: " << endl;
    cout << "(1) Move" << endl;
    cout << "(2) Fire Arrow" << endl;
    cout << "Enter choice: ";
    cin >> playrchoice;

    switch(playrchoice){
		case 1: playr_move(); break;
		case 2: shoot(); break;
	}

}


void cave::build_cave(){
    wumpcave = vector< vector<room> > (width, vector<room>(width)); //cave vector
    
    for(int i = 0; i < width; i++){ //nested loop to create rooms in cave
        for(int j = 0; j < width; j++){
            room c;
            wumpcave[i][j] = c;
        }
    }

}


void cave::print_cave(){ //function for creating the cave graphic
    	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){	
			cout << "+---";
		}
		cout << "+" << endl;
		    for(int x = 0; x < width; x++){
			    if((i == this->playr->xg) && (x == this->playr->yg)){
				cout << "|" << " * ";
			    }
			    else{
				    cout << "|" << wumpcave[i][x].get_mark();
			    }
		    }
		        cout << "|" << endl;
	    }
	
            for(int y = 0; y < width; y++){
		        cout << "+---";
	        }
	            cout << "+";
	            cout << endl;

}


int cave::chk_up(int x){//up movement function
    if(x-1 >= 0){
        return 1;
    }
        return 0;
}

int cave::chk_down(int x){ //down movement function
    if(x+1 < width){
        return 1;
    }
        return 0;
}

int cave::chk_left(int x){ //left movement function
    if(x-1 >= 0){
        return 1;
    }
        return 0;
}

int cave::chk_right(int x){ //right movement function
    if(x+1 <= width){
        return 1;
    }
        return 0;
}



void cave::playr_move(){ //player move function with wasd keys
    cin.ignore();
    string move;

    cout << "Which way would you like to move?";
    getline(cin, move);
	
	if(move == "d"){
		if(chk_right(this->playr->yg)){
			this->playr->yg = this->playr->yg+1;
		}
	}
	if(move == "a"){
		if(chk_left(this->playr->yg)){
			this->playr->yg = this->playr->yg-1;
		}
	}
	if(move == "w"){
		if(chk_up(this->playr->xg)){
			this->playr->xg = this->playr->xg-1;
		}
	}
	if(move == "s"){
		if(chk_right(this->playr->xg)){
			this->playr->xg = this->playr->xg+1;
		}
	}

}


void cave::shoot(){ //arrow shooting function
    cin.ignore();
    string directn;
    bool wump = false;

    this->playr->arrows--;

    cout << "Which way would you like to shoot an arrow?";
    getline(cin, directn);

    if(directn == "w"){
        cout << "Arrow shot up." << endl;
        
        for(int i = this->playr->xg-1; i >=0; i--){
			if(wumpcave[i][this->playr->yg].get_mark() == " w "){
				cout << endl << endl << "Wumpus has been killed." << endl;
				wump = true;
				kill_wump();
			}
		}
    }
            else if(directn == "s"){
		        cout << "Shooting down" << endl;
		        for(int i = this->playr->xg+1; i < width; i++){
			        if(wumpcave[i][this->playr->yg].get_mark() == " w "){
				        cout << endl << endl << "Wumpus has been killed" << endl;
				            wump = true;
				            kill_wump();
			}
		}
	}
                    	else if(directn == "d"){
		                    cout << "Shooting right" << endl;
		                    for(int i = this->playr->yg+1; i < width; i++){
			                    if(wumpcave[this->playr->xg][i].get_mark() == " w "){
				                    cout << endl << endl << "Wumpus has been killed" << endl;
				                        wump = true;
				                        kill_wump();
			                        }
		                        }
	                    }

                               	else if(directn == "a"){
		                            cout << "Shooting left" << endl;
		                            for(int i = this->playr->yg-1; i >=0; i--){
			                            if(wumpcave[this->playr->xg][i].get_mark() == " Wumpus "){
				                            cout << endl << endl << "Wumpus has been killed" << endl;
				                                wump = true;
				                                kill_wump();
			                                }
		                                }
	                            } 

}


void cave::miss(){ //function for missing arrow shot
    srand(time(NULL));

    int x = rand() % 3;

    if(x != 1){
        cout << "The arrow hits the wall, and the Wumpus moves away..." << endl;
        room r;

        for(int i = 0; i < width; i++){
            for(int j = 0; j < width; j++){
                if(wumpcave[i][j].get_mark() == "w"){
                    wumpcave[i][j] = r; 
                }
            }
        }
    

            bool slp = true;
            int x = rand() % width;
            int y = rand() % width;

            while(slp){
                if(wumpcave[x][y].get_event()){
                    x = rand() % width;
                    y = rand() % width;
                }
                else{
                    slp = false;
                }
            } 

            room wmp(0);

            wumpcave[x][y] = wmp;
        }
        else{
            cout << "It sleeps..." << endl;
        }
}


void cave::kill_wump(){ //function for the wumpus getting clapped
    room r;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(wumpcave[i][j].get_mark() == "Wump"){
                wumpcave[i][j] = r;
            }
        }
    }
            this->playr->wumpus = true;
}


void cave::collect_gold(){ //function for collecting the gold
    cout << "You recovered the gold!" << endl;

    this->playr->gold = true;
    
    room r;

    wumpcave[this->playr->xg][this->playr->yg] = r;
}


void cave::s_bats(){ //function for the super bats (batman?)
    srand(time(NULL));

    int x = rand() % width;
    int y = rand() % width;

    this->playr->xg = x;
    this->playr->yg = y;

    print_cave();
}


void cave::reset(){ //function for resetting game
    this->playr->reset_pos();
}


void cave::chk_prcpts(){ //function for checking percepts during the game
    
    if(chk_right(this->playr->yg)){
		if(wumpcave[this->playr->xg][this->playr->yg+1].get_event()){
			wumpcave[this->playr->xg][this->playr->yg+1].percept();
		}
	}
	
    if(chk_left(this->playr->yg)){
		if(wumpcave[this->playr->xg][this->playr->yg-1].get_event()){
			wumpcave[this->playr->xg][this->playr->yg-1].percept();
		}
	}
	
    if(chk_up(this->playr->xg)){
		if(wumpcave[this->playr->xg-1][this->playr->yg].get_event()){
			wumpcave[this->playr->xg-1][this->playr->yg].percept();
		}		
	}

	if(chk_down(this->playr->xg)){
		if(wumpcave[this->playr->xg+1][this->playr->yg].get_event()){	
			wumpcave[this->playr->xg+1][this->playr->yg].percept();
		}
	}
}


void cave::fill_cave(){ //function to fill the rooms in the cave
    srand(time(NULL));

    wumpcave[this->playr->xg][this->playr->yg].set_rope(true);
    wumpcave[this->playr->xg][this->playr->yg].set_event(true);

    room wmp(0);//wumpus
    room gld(1);//gold
    room pit1(2);//pit
    room pit2(2);//pit
    room sb1(3);//bat
    room sb2(3);//bat



    for(int i = 0; i < 7; i++){
        int x = rand() % width;
        int y = rand() % width;

        bool slp = true;

            while(slp){
                if(wumpcave[x][y].get_event()){
                    x = rand() % width;
                    y = rand() % width;
                }
                else{
                    slp = false;
                }
            }
            switch(i){ //filling rooms
                case 0: wumpcave[x][y] = wmp; break;
                case 1: wumpcave[x][y] = gld; break;
                case 2: wumpcave[x][y] = sb1; break;
                case 3: wumpcave[x][y] = sb2; break;
                case 4: wumpcave[x][y] = pit1; break;
                case 5: wumpcave[x][y] = pit2; break;
            }
    }
                wumpcave[this->playr->xg][this->playr->yg].set_event(false);
}


void cave::chk_danger(int & run){ //hazard functions, reads text out to user depending on siuation

    if(wumpcave[this->playr->xg][this->playr->yg].get_mark() == " Wumpus "){
		cout << "You just bumped into the Wumpus!" << endl;
		run = 0;
	}
	
    if(wumpcave[this->playr->xg][this->playr->yg].get_mark() == " Gold "){
		collect_gold();
	}
	
    if(wumpcave[this->playr->xg][this->playr->yg].get_mark() == " Pit "){
		cout << "You arent watching your step and you fall into a bottomless pit." << endl;
		run = 0;
	}
	
    if(wumpcave[this->playr->xg][this->playr->yg].get_mark() == " Bat "){
		cout << "Super bats come pick you up and carry you away!" << endl;
		s_bats();	
	}
	
    if(this->playr->arrows == 0){
		cout << "You are out of arrows, and you haven't killed the Wumpus!" << endl;
		run = 0;
	}

}


void cave::chk_if_win(int & run){ //function to check if the player has completed the necessary items to win
    int win = 0;

    if(this->playr->gold == true){
        win++;
    }

    if(this->playr->wumpus == true){
        win++;
    }

    if(wumpcave[this->playr->xg][this->playr->yg].get_rope()){
        win++;
    }

    if(win == 3){
        cout << "Well done, you have won!" << endl;
    }
}


void cave::replay(int & play, bool & samegame){ //function to allow player to go again
    int playrchoice;
    cout << "Would you like to hunt the Wumpus again?" << endl;
    cout << "(1)Let's hunt the Wumpus!" << endl;
    cout << "(2)No" << endl;
    cout << "Choice: ";
    cin >> play;

    if(play == 1){
        cout << "Would you like to play with the same or a different cave layout?"<< endl;
        cout << "(1)Same" << endl;
        cout << "(2)Different" << endl;
        cout << "Choice: ";
        cin >> playrchoice;

        if(playrchoice == 1){
            samegame = true;
        }
            else{
                samegame = false;
            }

            
    }
        else{
            play = 0;
        }


}

void cave::report_game(int & run, bool debug){ //function that gives status report to the player
    if(debug){
        cout<<endl;
        cout<<endl;
        cout<<endl;
        print_cave();
    }

    chk_danger(run);;
    if(run){
        chk_prcpts();
        playr_choice();
    }
    chk_if_win(run);
}


void cave::clear_cave(){ //deconstructor for the program, clears memory allocation with nested loop
    
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(wumpcave[i][j].get_event()){
                wumpcave[i][j].~room();
            }
        }
    }
                delete this->playr;
    
}
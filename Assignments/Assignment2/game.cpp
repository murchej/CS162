/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#include <iostream>
#include "game.h"
#include "card.h"
#include "player.h"
#include "deck.h"


using namespace std;

Game::Game(){
    players[0].set_name(get_string());
    players[1].set_name("CPU");
    cardpile.setnumcards(0);
    cards.create_deck(52);
    cards.shuffle_deck(0);
    Card t = cards.get_cards(0);
    players[0].set_hand(cards);
    players[1].set_hand(cards);
    cardpile.setnumcards(cardpile.getnumcards() +1);
    cards.set_cards(0,-1,-1);
    cardpile.set_cards(0, t.get_rank(), t.get_suit());
    cards.wipe();
}

void Game::play(){
    cout << "Welcome to crazy eights!" << endl;
    cout << "First up is " << players[0].get_name() << "." << endl;
    cout << "At the top of the pile is: ";
    cardpile.printtopcard();

    do{
        players[0].turn(cardpile, cards);
        cout << "The card at the top of the pile is: ";
        cardpile.printtopcard();

        players[1].cpu_turn(cardpile, cards);
        cout << "The card at the top of the pile is: ";
        cardpile.printtopcard(); 
    } while(check_winner() == false);
}

Player Game::get_players(int p){
    while(p >=0 && p < 2){
        return players[p];
    }
}

const Deck Game::get_cards(){
    return cards;
}

string Game::get_string(){
    string n;

    cout << "Enter name: ";
    cin >> n;

    return n;
}

bool Game::check_winner(){
    do{
        if(players[0].can_go(cardpile) || players[1].can_go(cardpile) == true){
            return false;
        }
        do{
            cout << "Player won!\n";
        } while(players[0].numinhand() > players[1].numinhand());

        do{
            cout << "The cpu has fewer cards and beat you!" << endl;
            return true;
        } while(players[0].numinhand() < players[1].numinhand());

        do{
            cout << players[0].get_name() << "'s hand is empty and wins the game!\n";
            return true; 
        } while(players[0].empty_hand() == true);

        do{
            cout << "CPU's hand is empty and beat you!\n";
            return true;
        } while(players[1].empty_hand() == true);
    
    }while(cards.draw() == false);
    return false;
}
    
    

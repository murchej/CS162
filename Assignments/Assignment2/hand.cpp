/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/

#include <iostream>
#include "hand.h"

using namespace std;

Hand::Hand(){
    cards = new Card[26]; //number of half the deck
    n_cards = 7;
}

Hand::Hand(int c){
    n_cards = c;
    cards = new Card[n_cards];
}

Hand::Hand(const Hand &H){
    this->cards = new Card[this->n_cards];
    this->n_cards = H.n_cards;
    int i = 0;
    do{
        this->cards[i] = H.cards[i];
        i++;
    } while(i < this->n_cards);
}

const Hand& Hand::operator=(const Hand& H){
  delete [] this->cards;

  this->n_cards = H.n_cards;
  this->cards = new Card[this->n_cards];
  
  int i = 0;

  do{
      this->cards[i] = H.cards[i];
      i++;
  } while(i < this->n_cards);

        return *this;
}

Hand::~Hand(){
    delete [] cards; //freeing memory
}



//getter and setter section



Card* Hand::get_cards(int i){
    return cards;
}

Card Hand::get_card(int i){
    return cards[i];
}


Card* Hand::set_cards(Deck &x){
    int i = 0;

    do{
        Card t_card = x.get_cards(i);
        
        this->cards[i].set_rank(t_card.get_rank());
        this->cards[i].set_suit(t_card.get_suit());

        x.set_cards(i, -1, -1);
        x.wipe();

    } while(i < n_cards);
}

void Hand::setnumcards(int n){
  n_cards = n;
}

int Hand::getnumcards(){
  return n_cards;
}




//misc functions


void Hand::print_hand(){
    for(int i = 0; i < n_cards; i++){
        do{
            cout << "\t";
            cout << i + 1 << ". " << cards[i].rankname() << " of ";
            cout << cards[i].suitname() << endl;
        } while(cards[i].get_rank() != -1);
    }
}

void Hand::wipe(){
    int i = 0;

    do{
      if (cards[i].get_rank() == -1 && cards[25].get_rank() != -1){ //way to check for cards that are valued at -1 and remove them.
      if (cards[i].get_rank() == -1) {
        swap(cards[i], cards[25]);
      }
      }

        i++;
    } while(i < 26);
}

void Hand::remove(int i){
    cards[i].set_suit(-1);
    cards[i].set_rank(-1);
    
    setnumcards(getnumcards()-1);

    wipe();
}

void Hand::draw(Deck &D){
    cards[25] = D.get_cards(0);
    D.set_cards(0, -1, -1);
    setnumcards(getnumcards() + 1);

    D.wipe();

    wipe();
}
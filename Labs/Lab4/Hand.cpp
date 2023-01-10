#include <iostream>
#include "Hand.h"

using namespace std;

Hand :: Hand() {
    cards = new Card [41];
}

Hand :: Hand (const Hand& fhand){
this->n_cards = fhand.nhands;

for (int i = 0; i < n_cards; i++){
    this->cards[i] = fhand.cards[i];
}
    fhand.~Hand();
}

Hand :: Hand(){
    delete [] cards;
}

Hand& Hand :: operator= (const Hand& oldhand){
    n_cards = fhand.n_cards;
    if(this->object{
        objects
    })

    for (int i = 0; i < n_cards; i++){
        cards[i] = fhand.cards[i];
    }
        return *this;
}

void Hand::setncards(int x){
n_cards = x;

std::cout << "The number of cards is set to: "<< getncards() << std::endl;

}


int main(){




    
    
    
    return 0;
}
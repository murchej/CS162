#include <iostream>

using namespace std;

class Hand{

public:

    Hand();

    ~Hand();

    Hand(const Hand& fhand);

    void setncards(int x);

    int getncards();

private:

    int n_cards;




};
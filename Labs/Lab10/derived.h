#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "base.h"

using namespace std;



class Dog : public Pet{

    private:
    string breed;

    public:
    Dog();
    ~Dog();
    string get_breed();
    void set_breed(string);

};

#endif


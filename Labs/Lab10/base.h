#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

using namespace std;

class Pet{

    public:
    Pet();
    Pet(int, string);
    ~Pet();
    int get_weight();
    void set_weight(int);
    string get_name();
    void set_name(string);
    string getLifespan(int);


    private:
    string name;
    int weight;





};

#endif
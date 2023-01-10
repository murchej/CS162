#include <iostream>
#include "base.h"
#include <string>

using namespace std;


Pet::getLifespan(){
    
    return "unkown lifespan";

}

int Pet::get_weight(){

    cout<< "What is the weight of your dog? ";
    cin >> weight;
    return weight;

}

void Pet::set_weight(int w){

    weight = w;

}

string Pet::get_name(){

    return name;

}

//void Pet::set_name(string){

    //return name;

//}


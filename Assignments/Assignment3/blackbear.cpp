/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include "animal.h"
#include "blackbear.h"

using namespace std;

 Blackbears::Blackbears() : Animal(){ //initializing member variables
     this->age = 1;
     this->cost = 6000;
     this->numBabies = 2;
     this->baseFoodCost = 80;
     this->payoff = 600;
}

Blackbears::Blackbears(int x) : Animal(){ //constructor with params
    this->age = x;
    this->cost = 6000;
    this->numBabies = 2;
    this->baseFoodCost = 80;
    this->payoff = 600;
}

int Blackbears::getCost(){ //cost getter 
    return this->cost;
}

int Blackbears::getAge(){ //age getter
    return age;
}

void Blackbears::setAge(int x){ //age setter
    this->age = x;
}

void Blackbears::setNumBabies(int x){ //num babies setter
    this-> numBabies = x;
}

int Blackbears::getNumBabies(){ //num babies getter
    return numBabies;
}

int Blackbears::getBaseFoodCost(){ //base food cost getter
    return this->baseFoodCost;
}

int Blackbears::getPayoff(){ //payoff getter
    return this->payoff;
}
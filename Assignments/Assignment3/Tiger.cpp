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
#include "Tiger.h"

using namespace std;

 Tigers::Tigers() : Animal(){ //initializing member variables
     this->age = 1;
     this->cost = 15000;
     this->numBabies = 3;
     this->baseFoodCost = 80;
     this->payoff = 1500;
}

Tigers::Tigers(int x) : Animal(){ //constructor with params
    this->age = x;
    this->cost = 15000;
    this->numBabies = 3;
    this->baseFoodCost = 80;
    this->payoff = 1500;
}

int Tigers::getCost(){ //cost getter 
    return this->cost;
}

int Tigers::getAge(){ //age getter
    return age;
}

void Tigers::setAge(int x){ //age setter
    this->age = x;
}

void Tigers::setNumBabies(int x){ //num babies setter
    this-> numBabies = x;
}

int Tigers::getNumBabies(){ //num babies getter
    return numBabies;
}

int Tigers::getBaseFoodCost(){ //base food cost getter
    return this->baseFoodCost;
}

int Tigers::getPayoff(){ //payoff getter
    return this->payoff;
}
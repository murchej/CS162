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
#include "Lemur.h"

using namespace std;
 Lemur::Lemur() : Animal(){ //initializing member variables
     this->age = 1;
     this->cost = 700;
     this->numBabies = 1;
     this->baseFoodCost = 80;
     this->payoff = 140;
}

Lemur::Lemur(int x) : Animal(){ //constructor with params
    this->numBabies = 1;
    this->baseFoodCost = 80;
    this->payoff = 140;
}

int Lemur::getCost(){ //cost getter 
    return this->cost;
}

int Lemur::getAge(){ //age getter
    return age;
}

void Lemur::setAge(int x){ //age setter
    this->age = x;
}

void Lemur::setNumBabies(int x){ //num babies setter
    this-> numBabies = x;
}

int Lemur::getNumBabies(){ //num babies getter
    return numBabies;
}

int Lemur::getBaseFoodCost(){ //base food cost getter
    return this->baseFoodCost;
}

int Lemur::getPayoff(){ //payoff getter
    return this->payoff;
}
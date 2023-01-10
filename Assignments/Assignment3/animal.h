/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Animal {
protected:
	int age;	
	int cost;
	int numBabies;
	int baseFoodCost;
	int payoff;
public:
	Animal();
	Animal(int);
	
	
};

#endif
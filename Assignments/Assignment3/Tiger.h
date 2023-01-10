/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/

#ifndef TIGER_H
#define TIGER_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "animal.h"

using namespace std;

class Tigers : public Animal {
public:
Tigers();
Tigers(int);
void addMonth();
void setAge(int);
void setNumBabies(int);
int getAge();
int getCost();
int getNumBabies();
int getBaseFoodCost();
int getPayoff();

};
#endif
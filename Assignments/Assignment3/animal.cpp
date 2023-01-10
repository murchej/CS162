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

using namespace std;

Animal::Animal()
{
   age = 0;
   cost = 0;
   numBabies = 0;
   baseFoodCost = 80;
   payoff = 0;
}
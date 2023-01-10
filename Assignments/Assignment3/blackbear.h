/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/

#ifndef BB_H
#define BB_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "animal.h"

using namespace std;


class Blackbears : public Animal {
   public:
      Blackbears();
      Blackbears(int);
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
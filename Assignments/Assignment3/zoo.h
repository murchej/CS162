/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "Tiger.h"
#include "Lemur.h"
#include "blackbear.h"

class Zoo
{
   private:
      int money;
      int choice;
      int tigerSize;
      int Lemursize;
      int blackbearSize;
      Tigers** tigers;
      Lemur** Lemurs;
      Blackbears** blackbears;
      int tigerNum;
      int lemNum;
      int bearNum;
   public:
      Zoo();
      Zoo(int);
      ~Zoo(); 
      void newMonth();
      int playerturn();
      void payforfood();
      void randomevent();
      void calculateRevenue();
      void buyanimal();
      void sickanimal();
      void attendanceBoom();
      void newbabyborn();
      int getmoney();
      int gettigerSize();
      int getlemurSize();
      int getblackBSize();
      void setmoney(int);
      void settigerSize(int);
      void setlemurSize(int);
      void setblackbSize(int);
      
};
#endif
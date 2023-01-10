/************************************************
 * Program Name: Zoo Tycoon
 * Author: Joseph Murche
 * Date: 2/2/21
 * Input:int
 * Output:strings,int
 * ***********************************************/
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include "zoo.h"
#include "animal.h"
#include "Lemur.h"
#include "blackbear.h"
#include "Tiger.h"

using namespace std;

//beginning of game
Zoo::Zoo(){
    money = 100000;//100k to start
    tigerSize = 10;//the capacity for each animal, for array use.
    Lemursize = 10;
    blackbearSize = 10;

      blackbears = new Blackbears*[blackbearSize]; //blackbear array
   for (int i = 0; i < blackbearSize; i++){
      blackbears[i] = 0;
   }

    tigers = new Tigers*[tigerSize]; //tiger array
    for(int j = 0; j < tigerSize; j++){
        tigers[j] = 0;
    }

    Lemurs = new Lemur*[Lemursize]; //lemur array
    for(int k = 0; k < Lemursize; k++){
        Lemurs[k] = 0;
    }
        
        //introduction piece
        
        cout << "You are the proud new owner of the Corvallis Zoo!!" << endl;
        cout << "You have $100,000 in the bank and no animals." << endl;
        cout << "Please purchase one of each animal(1 = purchase): " << endl;
        cin >> choice;

        money = money - 21700;

        cout << "Woohoo! You now have $"<< money << " and a Tiger, Black Bear, and a Lemur!" << endl;

        tigers[0] = new Tigers();
        Lemurs[0] = new Lemur();
        blackbears[0] = new Blackbears();
        
        bearNum = 1;
        lemNum = 1;
        tigerNum = 1;
}


//new month section
void Zoo :: newMonth(){ //adds a month to the age of the animals
    
    for(int x = 0; x < bearNum; x++){ //makes the bear(s) a month older
        int m;
        m = blackbears[x]->getAge();
        blackbears[x]->setAge(m++); 
    }

    for(int y = 0; y < tigerNum; y++){ //makes the tiger(s) a month older
        int n;
        n = tigers[y]->getAge();
        tigers[y]->setAge(n++);
    }

    for(int z = 0; z < lemNum; z++){ //makes the lemur(s) a month older
        int o;
         o = Lemurs[z]->getAge();
        Lemurs[z]->setAge(o++);
    }
}


//section for sick animals
void Zoo::sickanimal()
{
   srand(time(NULL));
   int r = (rand() % 3) + 1;
   if (r == 1 && tigerNum != 0) //tigers
   {
      cout << "A tiger passed away." << endl;
      tigers[tigerNum-1] == 0;
      tigerNum--;
      cout << "You have " << tigerNum << " tigers left in your zoo." << endl;
   }
   else if (r == 2 && lemNum != 0) //lemurs
   {
       cout << "A lemur passed away" << endl;
       Lemurs[lemNum - 1] == 0;
       lemNum--;
       cout << "You have " << lemNum << " lemurs left in your zoo." << endl;
   }
   else if (r == 3 && bearNum != 0) //blackbears
   {
      cout << "A black bear has died." << endl;
      blackbears[bearNum - 1] == 0;
      bearNum--;
      cout << "You have " << bearNum << " black bears left in your zoo." << endl;
   }
}


//random event section
void Zoo::randomevent()
{
   srand(time(NULL)); // seeds the random number generator for randomly picking event.
   int r = (rand() % 4) + 1;
   if (r == 1)
   {
      cout << "Congradulations, a new baby has been born!" << endl;
      newbabyborn();
   }
   else if (r == 2)
   {
      cout << "It's a beautiful day and the zoo is packed!" 
           << "Special bonus ($150-$400) for each lemur you have!" << endl;
      attendanceBoom();
   }
   else if (r == 3)
   {
      cout << "Uh oh, you have a sick animal!" << endl;
      sickanimal();
   }
   else if (r == 4)
   {
      cout << "Just another great day at the zoo!" << endl;
   }
}


//section where the bonuses are granted for lemurs
void Zoo::attendanceBoom()
{
   int num = 0;
   for (int x = 0; x < lemNum; x++)
   {
      num += rand() % 250 + 150;
   }
   cout << "You made $" << num << " in bonus from your lemurs!" << endl;
   money += num;
   cout << "You now have $" << money << " in the bank." << endl;
}


//section where the new babies are born
void Zoo::newbabyborn()
{
   srand(time(NULL));
   int r = (rand() % 3) + 1;
   if (r == 1) //if it is tigers
   {
      cout << " Congradulations! A new baby tiger has been born!" << endl;
      for (int x = 0; x < tigerNum; x++)
      {
         if ((tigers[x]->getAge() >= 3) && (tigers[x]->getNumBabies() == 1))
         {
            if (tigerNum < tigerSize)
            {
               tigers[tigerNum] = new Tigers(0);
            }
            else
            {
               Tigers* temp = new Tigers[tigerSize + 3];
               for (int i = 0; i < tigerSize; i++)
               {
                   temp[i] = *tigers[i];
               }
              
               delete [] tigers;
               *tigers = temp;
               int oldTigSize = tigerSize;
               tigerSize = tigerSize + 3;
               tigers[oldTigSize] = new Tigers(0);
               
            }
            tigerNum++;
            cout << "You now have " << tigerNum << " tigers." << endl;
            tigers[x]->setNumBabies(0);
            break;
         }
      }
   }
   
   
   else if (r == 2) //if it is a new lemur
   {
      cout << "Congradulations! You have a new baby lemur in your zoo!!!" << endl;
      for (int y = 0; y < lemNum; y++)
      {
         int numB = Lemurs[y]->getNumBabies();
         if ((Lemurs[y]->getAge() >=3) && (numB > 0))
         {
            if (lemNum < Lemursize)
            {
               Lemurs[lemNum] = new Lemur(0);
            }
            else
            {
               Lemur* temp = new Lemur[Lemursize + 1];
               for (int j = 0; j < Lemursize; j++)
               {
                  temp[j] = *Lemurs[j];
               }
              
               delete [] Lemurs;
               *Lemurs = temp;
               int initLemursize = Lemursize;
               Lemursize = Lemursize + 1;
               Lemurs[Lemursize] = new Lemur(0);
               
            }
            lemNum++;
            cout << "You now have " << lemNum << " lemurs in your zoo!" << endl;
            numB++;
            Lemurs[y]->setNumBabies(numB);
            break;
         }
      }
   }
   else if (r == 3) //if it is black bears
   {
      cout << "You have a new baby black bear!!" << endl;
      for (int z = 0; z < bearNum; z++)
      {
         int cubs = blackbears[z]->getNumBabies();
         if ((blackbears[z]->getAge() >= 3) && (cubs > 0))
         {
            if (bearNum < blackbearSize)
            {
               blackbears[bearNum] = new Blackbears(0);
            }
            else
            {
               Blackbears* temp = new Blackbears[blackbearSize + 2];
               for (int h = 0; h < blackbearSize; h++)
               {
                  temp[h] = *blackbears[h];
               }
             
               delete [] blackbears;
               *blackbears = temp;
               int initBearSize = blackbearSize;
               blackbearSize = blackbearSize + 2;
               blackbears[initBearSize] = new Blackbears(0);
             
            }
            bearNum++;
            cout << "You now have " << bearNum << " black bears in your zoo!!" << endl;
            cubs--;
            blackbears[z]->setNumBabies(cubs);
            break;
         }
      }
   }
}



void Zoo::buyanimal()
{
   int answer;
   while (1)
   {
      cout << "There is a sale on exotic animals right now!"
           << " Enter 1 for tiger, 2 for lemur, 3 for black bear,"
           << " or 4 for none." << endl;
      cin >> answer;

      if (answer == 1)  //tigers
      {
         if (tigerNum < tigerSize)
         {
            tigers[tigerNum] = new Tigers(3);
            tigerNum++;
         }

         else 
         {
            Tigers* temp;
            temp = new Tigers[(tigerSize * 2)];
         
            for (int i = 0; i < tigerSize; i++)
            {
                 temp[i] = *tigers[i];
            }
           
            delete [] tigers;

            *tigers = temp;
            int oldTigSize = tigerSize;
            tigerSize = tigerSize + 1;
            tigers[oldTigSize] = new Tigers(3);
            tigerNum++;
         }
         money = money - 15000;
         cout << "You have bought a tiger! You now have $" << money << "." << endl;
      }


      else if (answer == 2)
      {
         if (lemNum < Lemursize)
         {
            Lemurs[lemNum] = new Lemur(3);
            lemNum++;
         }

         else 
         {

            Lemur* temp;
            temp = new Lemur[(Lemursize * 2)];
            for (int h = 0; h < Lemursize; h++)
            {
               temp[h] = *Lemurs[h];
            }
           
            delete [] Lemurs; //freeing memory
            *Lemurs = temp;
            int initLemSize = Lemursize;
            Lemursize = Lemursize + 1;
            Lemurs[initLemSize] = new Lemur(3);
            lemNum++;
         }
         money = money - 700;
         cout << "You just bought a lemur! You now have $" << money << "." << endl;
      }

      else if (answer == 3)
      {
         if (bearNum < blackbearSize)
         {
            blackbears[bearNum] = new Blackbears(3);
            bearNum++;
         }
         else 
         {
            Blackbears* temp;
            temp = new Blackbears[(blackbearSize * 2)];
            for (int z = 0; z < blackbearSize; z++)
            {
               temp[z] = *blackbears[z];
            }
          
            delete [] blackbears;
            *blackbears = temp;
            int initblackbearSize = blackbearSize;
            blackbearSize = blackbearSize + 1;
            blackbears[initblackbearSize] = new Blackbears(3);
            bearNum++;
         }
         money = money - 6000;
         cout << "You bought a black bear! You now have $" << money << ".\n";
      }
  
      else if (answer == 4)
      {
         cout << "You did not buy an animal today." << endl;
      }
   
      else 
      {
         cout << "Please enter 1, 2, 3, or 4." << endl; //valid input check
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         continue;
      }
      cin.ignore (numeric_limits<streamsize>::max(), '\n');
      break;
     
   }   
}


//where the player purchases food
void Zoo::payforfood()
{
   int tigerFood = 80;
   int lemurFood = 80;
   int blackbearFood = 80;
   int total = 0;

   for (int x = 0; x < tigerNum; x++)
   {
      tigerFood = tigerFood * 5; //cost of tiger food is 5x the base cost
   }

   for (int y = 0; y < lemNum; y++)
   {
         lemurFood = lemurFood; //cost of lemur food is equal to the base cost
   }

   for (int z = 0; z < bearNum; z++)
   {
         blackbearFood = blackbearFood * 3; //cost of black bear food is 3x the base cost
   }

   total = tigerFood + lemurFood + blackbearFood; //totals the cost of all of the food
   money = (money - total);
   cout << "You spent: $" << total << " on food this month."<< endl;
    cout << "You have: $" << money << " remaining." << endl; //prints how much money the user still has
}

//section where the revenue from all of the animals is located
void Zoo::calculateRevenue()
{
   int tigerR = 0;
   int lemurR = 0;
   int blackbearR = 0;
   int total; //will be used to store the total revenue

   for (int x = 0; x < tigerNum; x++)
   {
      tigerR = tigerR + 1500; //tigers make 1500 each
   }

   for (int y = 0; y < lemNum; y++)
   {
      lemurR = lemurR + 120; //Lemur make 120 each
   }
   
   for (int z = 0; z < bearNum; z++) 
   {
      blackbearR = blackbearR + 600; //blackbears make 600 each
   }
  
   total = tigerR + lemurR + blackbearR;
   money = money + total;
   cout << "Woohoo! Your Zoo made $" << total << " today." << endl;
   cout << "You now have: $" << money << "." << endl;
}

//section where the user decides to take their turn
int Zoo::playerturn()
{
   cout << "Another day, Another dollar! Let's have a great day!" << endl;
   cout << "\n \n";
   if (money != 0)
   {
      
     
      cout << "Would you like to keep going? Enter '1' for yes "
           << "or '0' for no." << endl;
      cin >> choice;
      
      if (choice == 1)
      {
         cout << "It's a brand new day! \n \n" << endl;
         return 1;
      }
      else if (choice == 0) // else if / if else loop for player to keep playing
      {
         cout << "Come back soon!" << endl;
         return 0;
      }
      else
      {
         while (choice != 1 && choice != 0)
         {
            cout << "Please enter valid input." << endl; //check for valid input
            cin.clear();
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            
            if (choice == 1)
            {
               return 1;
            }
            else if (choice == 0)
            {
               return 0;
            }
         }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
   }
   else 
   {
      cout << "Oops, it looks like you went broke, better luck next time!"<< endl;//end of game
           
      return 0;
   }
}


//section dedicated to getters and setters for member variables
int Zoo::getmoney()
{
   return money;
}

 int Zoo::gettigerSize() //get the population size of tigers
{
   return tigerSize;
}

 int Zoo::getlemurSize() //get the population size of lemurs
{
   return Lemursize;
}

 int Zoo::getblackBSize() //get the population size of black bears
{
   return blackbearSize;
}

 void Zoo::setmoney(int x) //set the money number
{
   money = x;
}

 void Zoo::settigerSize(int x) //sets the population of the tigers
{
   tigerSize = x;
}

 void Zoo::setblackbSize(int x) //sets the population size of the black bears
{
   blackbearSize = x;
}  

 void Zoo::setlemurSize(int x) //sets the population size of the lemurs
{
   Lemursize = x;
}


//free the allocated memory
Zoo::~Zoo() //free's the memory
{
   for (int x = 0; x < tigerSize; x++) //frees the tiger array
   {
      delete tigers[x];
   }
   delete [] tigers;

  
   for (int y = 0; y < blackbearSize; y++) //frees the blackbear array
   {
      delete blackbears[y];
   }
   delete [] blackbears;
    
   
   for (int z = 0; z < Lemursize; z++) //frees the lemur array
   {
      delete Lemurs[z];
   }
   delete [] Lemurs;
}
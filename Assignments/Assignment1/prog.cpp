/*************************************************
 * Program: catalog.cpp
 * Author: Joseph Murche
 * Date: January 14th, 2021
 * Description: Sorts spells and spellbooks 
 * in predetermined orders that the user can select.
 * Input: Integers
 * Output: Structs
***************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "catalog.h"

using namespace std;

int main(int argc, char* argv[]){
     
     int n;
     ifstream file;
     string tmp_string;

     int goagain = 1;// variable for replaying program
     
     file.open("spellbooks.txt");
        if(!file.is_open()){
            cout << "Unable to open file!"<< endl; // to check if file is open and ready on command line
            return 1;
        }

        getline(file,tmp_string,'\n');

        

        n = atoi(tmp_string.c_str());

        spellbook* spellbooks = create_spellbooks(n);

        get_spellbook_data(spellbooks, n, file);

        while(goagain){
        print_spellbook_data(spellbooks, n);
        cout << "Would you like to go again? (Press 1 for yes, 0 for no): ";//loop to redo program
        cin >> goagain;
        }

        delete_spellbook_data(spellbooks, n); // freeing memory

         
        
 return 0; 
}
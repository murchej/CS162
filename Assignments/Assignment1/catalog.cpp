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
#include <string.h>
#include <fstream>
#include "catalog.h"

using namespace std;

spellbook* create_spellbooks(int n){// creates spellbook array
    spellbook* book;

    book = new spellbook[n];
    return book;
}

void get_spellbook_data(spellbook* spellbooks, int n, ifstream &file){// function for reading file into the array

    string temp_string;

    for(int i = 0; i < n; i++) {// reading into array

        getline(file, temp_string, ' ');
        spellbooks[i].title = temp_string;

        getline(file, temp_string, ' ');
        spellbooks[i].author = temp_string;

        getline(file, temp_string, ' ');
        spellbooks[i].num_pages = atoi(temp_string.c_str());

        getline(file, temp_string, ' ');
        spellbooks[i].edition = atoi(temp_string.c_str());

        getline(file, temp_string, '\n');
        spellbooks[i].num_spells = atoi(temp_string.c_str());

        spellbooks[i].s = create_spells(spellbooks[i].num_spells);

        get_spell_data(spellbooks[i].s, spellbooks[i].num_spells, file);

        for(int j = 0; j < spellbooks[i].num_spells; j++) {

            spellbooks[i].avg_success_rate += spellbooks[i].s[j].success_rate;
        }
        spellbooks[i].avg_success_rate = (spellbooks[i].avg_success_rate/spellbooks[i].num_spells);
      
    }
    
}

spell* create_spells(int n){// function for creating spell array
    spell* singlespell;

    singlespell = new spell[n];
    return singlespell;

}

void get_spell_data(spell* spells, int n, ifstream &file){//gets spell data from file

    string temp_string;

    for(int j = 0; j < n; j++) {

        getline(file, temp_string, ' ');
        spells[j].name = temp_string;

        getline(file, temp_string, ' ');
        spells[j].success_rate = atoi(temp_string.c_str());

        getline(file, temp_string, '\n');
        spells[j].effect = temp_string;

    }
}

void sort_page(spellbook* spellbooks, int n) {//function for sorting pages

    int array[n];
    for(int i = 0; i < n; i++) {
        array[i] = spellbooks[i].num_pages;
    }

    int i;
    int key;
    int j;
    //loop through full array
    for(i = 1; i < n; i++) {

        key = array[i];
        j = i -1;
        //while j is greter than 0 and the value at array index j is greater than the current value at
        // array index i continue
        while( j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }

    for(int i = 0; i < n; i++) {
        cout << spellbooks[i].title << " " << array[i] << endl;
    }
}

void sort_effect(spellbook* spellbooks, int n) {//function to sort spells by their effect

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < spellbooks[i].num_spells; j++) {
            
           if(spellbooks[i].s[j].effect.find("bub") == 0){
            cout << spellbooks[i].s[j].name << " "<< spellbooks[i].s[j].effect << endl;
            }
            
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < spellbooks[i].num_spells; j++) {
            
           if(spellbooks[i].s[j].effect.find("mem") == 0){
            cout << spellbooks[i].s[j].name << " "<< spellbooks[i].s[j].effect << endl;
            }
            
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < spellbooks[i].num_spells; j++) {
            
           if(spellbooks[i].s[j].effect.find("fir") == 0){
            cout << spellbooks[i].s[j].name << " "<< spellbooks[i].s[j].effect << endl;
            }
            
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < spellbooks[i].num_spells; j++) {
            
           if(spellbooks[i].s[j].effect.find("pois") == 0){
            cout << spellbooks[i].s[j].name <<" "<< spellbooks[i].s[j].effect << endl;
            }
            
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < spellbooks[i].num_spells; j++) {
            
           if(spellbooks[i].s[j].effect.find("deat") == 0){
            cout << spellbooks[i].s[j].name <<" "<< spellbooks[i].s[j].effect << endl;
            }
            
        }
    }
    
}

void success_rate(spellbook* spellbooks, int n) {// function for sorting by success rate

    float array[n];
    for(int i = 0; i < n; i++) {
        array[i] = spellbooks[i].avg_success_rate;
    }

    int i;
    float key;
    int j;
    //loop through full array
    for(i = 1; i < n; i++) {

        key = array[i];
        j = i -1;
        //while j is greter than 0 and the value at array index j is greater than the current value at
        // array index i continue
        while( j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
    for(int i = 0; i < n; i++) {
        cout << spellbooks[i].title << " " << array[i] << endl;
    }
}


void print_spellbook_data(spellbook* spellbooks, int n){// primary function for printing data to terminal, contains all of the other functions
    int order = 0;
    cout << "Which option would you like to choose?"<< endl;
    cout << "Sort spellbooks by number of pages (Press 1):"<< endl;
    cout << "Group spells by their effect (Press 2)"<< endl;
    cout << "Sort spellbooks by their average success rate (Press 3)"<< endl;
    cout << "Quit Program (Press 4)"<< endl;
    cin >> order;

    if(order == 1){

        sort_page(spellbooks, n);  
    }
    
    else if(order == 2) {
        sort_effect(spellbooks, n);
    }

    else if(order == 3) {
        success_rate(spellbooks, n);
    }


}


void delete_spellbook_data(spellbook* spellbooks, int n){

    for(int j = 0; j < n ; j++) {

        delete [] spellbooks[j].s;
        
    }
    delete [] spellbooks;
}

/*************************************************
 * Program: catalog.cpp
 * Author: Joseph Murche
 * Date: January 14th, 2021
 * Description: Sorts spells and spellbooks 
 * in predetermined orders that the user can select.
 * Input: Integers
 * Output: Structs
***************************************************/

#ifndef CATALOG_H
#define CATALOG_H


#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell* s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};


spellbook* create_spellbooks(int); 
void get_spellbook_data(spellbook*, int, ifstream &); 
spell* create_spells(int);
void get_spell_data(spell*, int, ifstream &); 
void delete_spellbook_data(spellbook*, int);
void print_spellbook_data(spellbook*, int);
void sort_effect(spellbook*, int);
void success_rate(spellbook* , int );
void sort_page(spellbook*, int);
#endif
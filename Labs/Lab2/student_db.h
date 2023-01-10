
#ifndef STUDENT_DB_H
#define STUDENT_DB_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct student {
  int id;
  string first_name;
  string last_name;
  string major;
};


student* create_student_db(int);
void get_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student **, int);
void sortwrite_student_db(student *, int);


#endif
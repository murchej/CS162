#include <iostream>
#include <fstream>
#include <string>
#include "student_db.h"

using namespace std;

int main() {
  int num_of_students;
  string temp_string;
  ifstream fin;

  
  fin.open("input.txt");
  if (!fin.is_open()) {
    cout << "Error, unable to open file.\n";
    return 1;
  }


  getline(fin, temp_string, '\n');
  num_of_students = stoi(temp_string);
  cout << "Number of Students: " << num_of_students << endl;


  student *studentdb = create_student_db(num_of_students);
  get_student_db_info(studentdb, num_of_students, fin);
  fin.close();


  sortwrite_student_db(studentdb, num_of_students);

  
  delete [] studentdb;

  return 0;
}





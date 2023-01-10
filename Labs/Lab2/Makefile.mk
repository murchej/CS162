CC = g++ -std=c++11
exe_file = student_db
$(exe_file): student_db.o Lab2.o 
     $(CC) student_db.o Lab2.o -o $(exe_file)
student_db.o: student_db.cpp
     $(CC) -c student_db.cpp
Lab2.o: Lab2.cpp
     $(CC) -c Lab2.cpp


clean:
     rm –f *.out *.o $(exe_file)
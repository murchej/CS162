CC = g++

exe_file - Hand
$(exe_file): Hand.o 
$(CC)Hand.o -o $(exe_file)
Hand.o: Hand.h Hand.cpp
    $(CC) -c Hand.cpp
Hand.o: Hand.h 
    $(CC) -c Hand.h
    clean:
    rm -f *.out *.o $(exe_file)
CC = g++ -std=c++11
exe_file = runll

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS := -g -Wall
else
    CFLAGS := -DNDEBUG -O3
endif

$(exe_file): Linked_List.o Node.o other_functions.o main.o 
    $(CC) Linked_List-o Node-o other_functions-o main-o $(exe_file) $(CFLAGS)
Linked_List.o: Linked_List.cpp
    $(CC) -c Linked_List.cpp $(CFLAGS)
Node.o: Node.cpp
    $(CC) -c Node.cpp $(CFLAGS)
main.o: main.cpp
    $(CC) -c main.cpp $(CFLAGS)
misc_functions.o: misc_functions.cpp
    $(CC) -c misc_functions.cpp $(CFLAGS)
 
clean:
    rm -f *.out *.o $(exe_file)

.PHONY: clean

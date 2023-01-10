CC = g++ -std=c++11
exe_file = Assignment_One

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): catalog.o prog.o
	$(CC) catalog.o prog.o -o $(exe_file) $(CFLAGS)
catalog.o: catalog.cpp
	$(CC) -c catalog.cpp $(CFLAGS)
prog.o: prog.cpp
	$(CC) -c prog.cpp $(CFLAGS)


clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean

CC = g++ -std=c++11
exe_file = zootycoongame

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS := -g -Wall
else
    CFLAGS :+ -DNDEBUG -O3
endif

$(exe_file): Lemur.o blackbear.o zoo.o Tiger.o animal.o driver.o
    $(CC) Lemur-o blackbear-o zoo-o Tiger-o animal-o driver-o $(exe_file) $(CFLAGS)
Lemur.o: Lemur.cpp
    $(CC) -c Lemur.cpp $(CFLAGS)
blackbear.o: blackbear.cpp
    $(CC) -c blackbear.cpp $(CFLAGS)
Tiger.o: Tiger.cpp
    $(CC) -c tiger.cpp $(CFLAGS)
driver.o: driver.cpp
    $(CC) -c driver.cpp $(CFLAGS)
zoo.o: zoo.cpp
    $(CC) -c zoo.cpp $(CFLAGS)
animal.o: animal.cpp
    $(CC) -c animal.cpp $(CFLAGS)
 
clean:
    rm -f *.out *.o $(exe_file)

.PHONY: clean
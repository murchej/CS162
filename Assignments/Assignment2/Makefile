CC = g++ -std=c++11
exe_file = crazyeights

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS :+ -DNDEBUG -03
endif

$(exe_file): card.o card.o deck.o deck.o player.o player.o game.o game.o hand.o hand.o driver.o
	$(CC) card-o card-o deck-o deck-o player-o player-o game-o game-o hand-o hand-o driver-o $(exe_file) $(CFLAGS)
card.o: card.cpp
	$(CC) -c card.cpp $(CFLAGS)
card.o: card.h
	$(CC) -c card.h $(CFLAGS)
deck.o: deck.cpp
	$(CC) -c deck.cpp $(CFLAGS)
deck.o: deck.h
	$(CC) -c deck.h $(CFLAGS)
hand.o: hand.cpp
	$(CC) -c hand.cpp $(CFLAGS)
hand.o: hand.h
	$(CC) -c hand.h $(CFLAGS)
game.o: game.cpp
	$(CC) -c game.cpp $(CFLAGS)
game.o: game.h
	$(CC) -c game.h $(CFLAGS)
player.o: player.cpp
	$(CC) -c player.cpp $(CFLAGS)
player.o: player.h
	$(CC) -c player.h $(CFLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
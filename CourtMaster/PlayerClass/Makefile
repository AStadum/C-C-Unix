CC=g++ -Wall -std=c++11

CFLAGS=-c

all: main

main: Player.o player-test.o
	$(CC) Player.o player-test.o -o main

Player.o: Player.cpp
	$(CC) $(CFLAGS) Player.cpp

player-test.o: player-test.cpp
	$(CC) $(CFLAGS) player-test.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o main
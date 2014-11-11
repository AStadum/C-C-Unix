CC=g++ -Wall -std=c++11

CFLAGS=-c

all: main

main: Player.o PlayerQueue.o main.o
	$(CC) Player.o PlayerQueue.o main.o -o main

Player.o: Player.cpp
	$(CC) $(CFLAGS) Player.cpp

PlayerQueue.o: PlayerQueue.cpp
	$(CC) $(CFLAGS) PlayerQueue.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o main
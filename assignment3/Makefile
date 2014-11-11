SOURCES = myMaze.c maze.c
HEADERS = myMaze.h
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

maze: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)


clean: 
	$(RM) maze $(OBJECTS)

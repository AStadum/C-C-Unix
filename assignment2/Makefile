SOURCES = square1.c square2.c diamond.c main.c
HEADERS = square1.h square2.h diamond.h
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)


clean: 
	$(RM) main $(OBJECTS)
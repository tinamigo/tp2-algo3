.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=dijkstra.o defines.o

INPUT-1 = ../test1.txt
INPUT-2 = ../test2.txt

all: dijkstraExe

dijkstraExe: $(OBJS) dijkstraExe.cpp
	$(CC) $(LFLAGS) $(OBJS) dijkstraExe.cpp -o dijkstraExe

dijkstra.o: dijkstra.h dijkstra.cpp
	$(CC) $(CFLAGS) dijkstra.cpp -o dijkstra.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm dijkstraExe

test-otro: dijkstraExe
	@./dijkstraExe < $(INPUT) > dijkstraTest.txt

test-simples: dijkstraExe
	@./dijkstraExe < $(INPUT-1) > dijkstraTest1.txt
	@./dijkstraExe < $(INPUT-2) > dijkstraTest2.txt
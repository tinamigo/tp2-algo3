.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=bellmanFord.o defines.o

INPUT-1 = ../test1.txt
INPUT-2 = ../test2.txt

all: bellmanFordExe

bellmanFordExe: $(OBJS) bellmanFordExe.cpp
	$(CC) $(LFLAGS) $(OBJS) bellmanFordExe.cpp -o bellmanFordExe

bellmanFord.o: bellmanFord.h bellmanFord.cpp
	$(CC) $(CFLAGS) bellmanFord.cpp -o bellmanFord.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm bellmanFordExe

test-otro: bellmanFordExe
	@./bellmanFordExe < $(INPUT) > bellmanFordTest.txt

test-simples: bellmanFordExe
	@./bellmanFordExe < $(INPUT-1) > bellmanFordTest1.txt
	@./bellmanFordExe < $(INPUT-2) > bellmanFordTest2.txt
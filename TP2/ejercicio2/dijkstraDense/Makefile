.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=dijkstraDense.o defines.o

INPUT-1 = ../test1.txt
INPUT-2 = ../test2.txt

all: dijkstraDenseExe

dijkstraDenseExe: $(OBJS) dijkstraDenseExe.cpp
	$(CC) $(LFLAGS) $(OBJS) dijkstraDenseExe.cpp -o dijkstraDenseExe

dijkstraDense.o: dijkstraDense.h dijkstraDense.cpp
	$(CC) $(CFLAGS) dijkstraDense.cpp -o dijkstraDense.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm dijkstraDenseExe

test-otro: dijkstraDenseExe
	@./dijkstraDenseExe < $(INPUT) > dijkstraDenseTest.txt

test-simples: dijkstraDenseExe
	@./dijkstraDenseExe < $(INPUT-1) > dijkstraDenseTest1.txt
	@./dijkstraDenseExe < $(INPUT-2) > dijkstraDenseTest2.txt
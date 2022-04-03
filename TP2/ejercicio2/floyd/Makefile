.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-pthread -g -std=$(CPP_STANDARD)

OBJS=floyd.o defines.o

INPUT-1 = ../test1.txt
INPUT-2 = ../test2.txt

all: floydExe

floydExe: $(OBJS) floydExe.cpp
	$(CC) $(LFLAGS) $(OBJS) floydExe.cpp -o floydExe

floyd.o: floyd.h floyd.cpp
	$(CC) $(CFLAGS) floyd.cpp -o floyd.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm floydExe

test-otro: floydExe
	@./floydExe < $(INPUT) > floydTest.txt

test-simples: floydExe
	@./floydExe < $(INPUT-1) > floydTest1.txt
	@./floydExe < $(INPUT-2) > floydTest2.txt
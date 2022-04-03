.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=disjointSet.o defines.o

INPUT-KOALA = ../experimentacion/ImagenesTxtGray/koala.txt
INPUT-HALCON = ../experimentacion/ImagenesTxtGray/halcon.txt
INPUT-GATOS = ../experimentacion/ImagenesTxtGray/gatos.txt

all: arrayExe

arrayExeComp: $(OBJS) arrayExeComp.cpp
	$(CC) $(LFLAGS) $(OBJS) arrayExeComp.cpp -o arrayExeComp

arrayExe: $(OBJS) arrayExe.cpp
	$(CC) $(LFLAGS) $(OBJS) arrayExe.cpp -o arrayExe

disjointSet.o: disjointSet.h disjointSet.cpp
	$(CC) $(CFLAGS) disjointSet.cpp -o disjointSet.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm arrayExeComp
	rm arrayExe

test-koala: arrayExeComp
	@./arrayExeComp < $(INPUT-KOALA) 2> koalaarray.txt

test-halcon: arrayExeComp
	@./arrayExeComp < $(INPUT-HALCON) 2> halconarray.txt

test-gatos: arrayExeComp
	@./arrayExeComp < $(INPUT-GATOS) 2> gatosarray.txt

tests: arrayExeComp
	@echo "Tiempo Koala array"
	@./arrayExeComp < $(INPUT-KOALA) 2> koalaarray.txt
	@echo "Tiempo Halcon array"
	@./arrayExeComp < $(INPUT-HALCON) 2> halconarray.txt
	@echo "Tiempo Gatos array"
	@./arrayExeComp < $(INPUT-GATOS) 2> gatosarray.txt
.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=disjointSet.o defines.o

INPUT-KOALA = ../experimentacion/ImagenesTxtGray/koala.txt
INPUT-HALCON = ../experimentacion/ImagenesTxtGray/halcon.txt
INPUT-GATOS = ../experimentacion/ImagenesTxtGray/gatos.txt

all: treeExe

treeExeComp: $(OBJS) treeExeComp.cpp
	$(CC) $(LFLAGS) $(OBJS) treeExeComp.cpp -o treeExeComp

treeExe: $(OBJS) treeExe.cpp
	$(CC) $(LFLAGS) $(OBJS) treeExe.cpp -o treeExe

disjointSet.o: disjointSet.h disjointSet.cpp
	$(CC) $(CFLAGS) disjointSet.cpp -o disjointSet.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm treeExeComp
	rm treeExe

test-koala: treeExeComp
	@./treeExeComp < $(INPUT-KOALA) 2> koalatree.txt

test-halcon: treeExeComp
	@./treeExeComp < $(INPUT-HALCON) 2> halcontree.txt

test-gatos: treeExeComp
	@./treeExeComp < $(INPUT-GATOS) 2> gatostree.txt

tests: treeExeComp
	@echo "Tiempo Koala tree"
	@./treeExeComp < $(INPUT-KOALA) 2> koalatree.txt
	@echo "Tiempo Halcon tree"
	@./treeExeComp < $(INPUT-HALCON) 2> halcontree.txt
	@echo "Tiempo Gatos tree"
	@./treeExeComp < $(INPUT-GATOS) 2> gatostree.txt
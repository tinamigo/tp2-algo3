.PHONY: all clean

CC=g++
CPP_STANDARD=c++11
CFLAGS=-c -g -std=$(CPP_STANDARD)
LFLAGS=-g -std=$(CPP_STANDARD)

OBJS=disjointSet.o defines.o

INPUT-KOALA = ../experimentacion/ImagenesTxtGray/koala.txt
INPUT-HALCON = ../experimentacion/ImagenesTxtGray/halcon.txt
INPUT-GATOS = ../experimentacion/ImagenesTxtGray/gatos.txt

all: treePathRelinkingExe

treePathRelinkingExeComp: $(OBJS) treePathRelinkingExeComp.cpp
	$(CC) $(LFLAGS) $(OBJS) treePathRelinkingExeComp.cpp -o treePathRelinkingExeComp

treePathRelinkingExe: $(OBJS) treePathRelinkingExe.cpp
	$(CC) $(LFLAGS) $(OBJS) treePathRelinkingExe.cpp -o treePathRelinkingExe

disjointSet.o: disjointSet.h disjointSet.cpp
	$(CC) $(CFLAGS) disjointSet.cpp -o disjointSet.o

defines.o: ../defines.h ../defines.cpp
	$(CC) $(CFLAGS) ../defines.cpp -o defines.o

clean:
	rm $(OBJS)
	rm treePathRelinkingExeComp
	rm treePathRelinkingExe

test-koala: treePathRelinkingExeComp
	@./treePathRelinkingExeComp < $(INPUT-KOALA) 2> koalatreePathRelinking.txt

test-halcon: treePathRelinkingExeComp
	@./treePathRelinkingExeComp < $(INPUT-HALCON) 2> halcontreePathRelinking.txt

test-gatos: treePathRelinkingExeComp
	@./treePathRelinkingExeComp < $(INPUT-GATOS) 2> gatostreePathRelinking.txt

tests: treePathRelinkingExeComp
	@echo "Tiempo Koala treePathRelinking"
	@./treePathRelinkingExeComp < $(INPUT-KOALA) 2> koalatreePathRelinking.txt
	@echo "Tiempo Halcon treePathRelinking"
	@./treePathRelinkingExeComp < $(INPUT-HALCON) 2> halcontreePathRelinking.txt
	@echo "Tiempo Gatos treePathRelinking"
	@./treePathRelinkingExeComp < $(INPUT-GATOS) 2> gatostreePathRelinking.txt
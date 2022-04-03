#!/bin/bash

if [ "$1" != "" ]; then

	cd bellmanFord/ && make INPUT=../$1 test-otro && cd ../
	cd dijkstra/ && make INPUT=../$1 test-otro && cd ../
	cd dijkstraDense/ && make INPUT=../$1 test-otro && cd ../
	cd floyd/ && make INPUT=../$1 test-otro && cd ../

	echo "Comparando outputs de test dado, si no devuelve nada entonces esta bien:  "
	diff bellmanFord/bellmanFordTest.txt dijkstra/dijkstraTest.txt 
	diff bellmanFord/bellmanFordTest.txt dijkstraDense/dijkstraDenseTest.txt 
	diff bellmanFord/bellmanFordTest.txt floyd/floydTest.txt

else

    cd bellmanFord/ && make test-simples && cd ../
	cd dijkstra/ && make test-simples && cd ../
	cd dijkstraDense/ && make test-simples && cd ../
	cd floyd/ && make test-simples && cd ../

	echo "Comparando outputs de test1, si no devuelve nada entonces esta bien:  "
	diff bellmanFord/bellmanFordTest1.txt dijkstra/dijkstraTest1.txt 
	diff bellmanFord/bellmanFordTest1.txt dijkstraDense/dijkstraDenseTest1.txt 
	diff bellmanFord/bellmanFordTest1.txt floyd/floydTest1.txt

	echo "Comparando outputs de test2, si no devuelve nada entonces esta bien:  "
	diff bellmanFord/bellmanFordTest2.txt dijkstra/dijkstraTest2.txt 
	diff bellmanFord/bellmanFordTest2.txt dijkstraDense/dijkstraDenseTest2.txt 
	diff bellmanFord/bellmanFordTest2.txt floyd/floydTest2.txt

fi
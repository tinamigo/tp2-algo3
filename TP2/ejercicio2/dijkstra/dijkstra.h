#ifndef EJERCICIO2_DIJKSTRA_H
#define EJERCICIO2_DIJKSTRA_H

#include "../defines.h"

void addNeighbours(grafo& G, vertice v, priority_queue<edge>& Q);
void Dijkstra (grafo& G, vertice v, vector<int>& costs);

#endif //EJERCICIO2_DIJKSTRA_H

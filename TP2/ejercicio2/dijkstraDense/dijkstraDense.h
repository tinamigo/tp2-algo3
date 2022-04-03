#ifndef EJERCICIO2_DIJKSTRADENSE_H
#define EJERCICIO2_DIJKSTRADENSE_H

#include "../defines.h"

int find_next_edge(vector<int>& temporal_costs, vector<int>& costs);
void addNeighbourhood (grafo& G, vertice v, priority_queue<edge>& Q);
void DijkstraDense (grafo& G, vertice v, vector<int>& costs);

#endif //EJERCICIO2_DIJKSTRADENSE_H

#ifndef EJERCICIO2_BELLMANFORD_H
#define EJERCICIO2_BELLMANFORD_H

#include "../defines.h"

vector<edge> neighboursToEdges(grafo& G);
void BellmanFord(grafo& G, vertice v, vector<int>& costs);

#endif //EJERCICIO2_BELLMANFORD_H

#include "dijkstra.h"

using namespace std;

void addNeighbours(grafo& G, vertice v, priority_queue<edge>& Q, vector<int>& costs) {
    for (int i = 0; i < G[v].size(); ++i) {
        int b,c;
        tie(b,c) = G[v][i];
        c = c + costs[v];
        Q.push({-c,v,b});
    }
}

void Dijkstra (grafo& G, vertice v, vector<int>& costs) {   //G es lista de adyacencias
    priority_queue<edge> Q;            // elementos de Q = (costo, ciudad origen, ciudad destino)
    costs[v] = 0;
    // agrego a Q los vecinos de v y sus costos
    addNeighbours(G, v, Q, costs);

    while(not Q.empty()) {
        int cost, a, b;
        tie(cost, a, b) = Q.top();
        cost = -cost;
        Q.pop();
        // me fijo si ya esta definido
        if(costs[b] == undefined) {
            costs[b] = cost;
            //agrego sus vecinos
            addNeighbours(G, b, Q, costs);
        }
    }
}

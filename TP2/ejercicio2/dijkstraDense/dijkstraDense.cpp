#include "dijkstraDense.h"



int find_next_edge (vector<int>& temporal_costs, vector<int>& costs) {
    int res = undefined;
    int res_cost = infinity;
    for (int i = 0; i < temporal_costs.size(); ++i) {
        if (costs[i] == undefined and temporal_costs[i] < res_cost) {
            res_cost = temporal_costs[i];
            res = i;
        }
    }
    return res;
}

void addNeighbourhood (grafo& G, vertice v, vector<int>& temporal_costs) {
    for (neighbour e : G[v]) {
        if (temporal_costs[dst(e)] > cost(e) + temporal_costs[v]) {
            temporal_costs[dst(e)] = cost(e) + temporal_costs[v];
        }
    }
}

void DijkstraDense (grafo& G, vertice v, vector<int>& costs) {
    int n = G.size();
    vector<int> temporal_costs(n, infinity);
    costs [v] = 0;
    temporal_costs[v] = 0;
    addNeighbourhood (G, v, temporal_costs);

    for (int i = 0; i < n-1; ++i) {
        // devuelve el vertice que hay que agregar
        int w = find_next_edge(temporal_costs, costs);
        // si devuelve w = undefined se rompio;
        if (w == -1) { return; }
        addNeighbourhood(G, w, temporal_costs);
        costs[w] = temporal_costs[w];
    }
}
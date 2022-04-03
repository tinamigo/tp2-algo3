#include "bellmanFord.h"

using namespace std;

vector<edge> neighboursToEdges(grafo& G) {
    vector<edge> res;
    for (int i = 0; i < G.size(); ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            edge tmp(i, dst(G[i][j]), cost(G[i][j]));
            res.push_back(tmp);
        }
    }
    return res;
}

void BellmanFord(grafo& G, vertice v, vector<int>& costs) {
    vector<edge> edges = neighboursToEdges(G);
    costs[v] = 0;
    bool modified = true;
    for (int k = 0; k < G.size() and modified; ++k) {
        modified = false;
        for (int i = 0; i < edges.size(); ++i) {
            int x,y,cxy;
            x = src(edges[i]);
            y = dst(edges[i]);
            cxy = cost(edges[i]);
            if ((costs[x] != infinity) and costs[x] + cxy < costs[y]) {   // D[x] + c(xy) < D[y]
                modified = true;
                costs[y] = costs[x] + cxy;     // D[y] = D[x] + c(xy)
            }
        }
    }
}
#include "floyd.h"

using namespace std;

int minimumInt(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void Floyd(grafo& G, vector<vector<int>>& D) {   //G es lista de adyacencia y costs es un array de n*n
    int n = G.size();
    for (int i = 0; i < n; ++i) {
        D[i][i] = 0;
        for (int j = 0; j < G[i].size(); ++j) {
            D[i][dst(G[i][j])] = cost(G[i][j]);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (D[i][k] != infinity and D[k][j] != infinity and D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }




    // return;
}
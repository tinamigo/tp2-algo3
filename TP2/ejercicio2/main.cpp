#include "dijkstra.h"
#include "bellmanFord.h"
#include "floyd.h"
#include "dijkstraDenso.h"

using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    vector<edge> G_orig(2*m);
    vector<int> price(n);
    for (int i = 0; i < n; ++i) {       // Guardo precio de la nafta de cada ciudad
        cin >> price[i];
    }
    for (int j = 0; j < m; j++) {       // Guardo aristas en lista de aristas modo digrafo
        int a,b,c;
        cin >> a ;
        cin >> b ;
        cin >> c;
        edge tmp(a,b,c);
        edge tmp2(b,a,c);
        G_orig[2*j] = tmp;    // ida
        G_orig[2*j+1] = tmp2; // vuelta
    }

    // Transformo lista de aristas en grafo para buscar camino mínimo
    vector<vector<neighbour>> G(TANK_SIZE*n);  // Tengo 60 vertices -cant nafta: [0,59]- por cada ciudad

    for (edge e: G_orig) {             // Para cada arista
        int a = src(e);
        int b = dst(e);
        int dist = cost(e);
        for (int l = 0; l < TANK_SIZE; ++l) {
            int maximum = TANK_SIZE - l;    // maxima cantidad de litros a cargar
            int min = max((dist - l),0);         // minima cantidad de litros a cargar
            for (int loading = min; loading <= maximum; ++loading) {    // loading = cant litros cargados
                int remaining_fuel = l + loading - dist;
                neighbour tmp(b*TANK_SIZE + remaining_fuel, loading*price[a]);
                G[a*TANK_SIZE+l].push_back(tmp);
            }
        }
    }

    // Aplico camino minimo a cada vertice partiendo con 0 litros
    // --------------   DIJKSTRA DESDE ACA   -------------------------------------
    int D[n][n];      // diccionario de costos minimos n * n
    for (int i = 0; i < n; ++i) {       // para cada vertice i
        vector<int> cost(n * TANK_SIZE, undefined);                                              // -1 = indefinido
        Dijkstra(G, i * TANK_SIZE, cost);      // calculo su costo minimo al resto
        for (int j = 0; j < n; ++j) {           // para cada otro vertice j
            D[i][j] = cost[j * TANK_SIZE];
        }
    }

    //ret
    cout << "Dijkstra: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {              //no imprimo costo a mi mismo siempre 0 no hay ciclos negativos
                cout << i << " " << j << " " << D[i][j] << endl;
            }
        }
    }
    // --------------------------DIJKSTRA TERMINA ACA ---------------------------

    // --------------   DIJKSTRA DENSO DESDE ACA   -------------------------------------
    int D2[n][n];      // diccionario de costos minimos n * n
    for (int i = 0; i < n; ++i) {       // para cada vertice i
        vector<int> cost(n * TANK_SIZE,undefined);                                              // -1 = indefinido
        DijkstraDense(G, i * TANK_SIZE, cost);      // calculo su costo minimo al resto
        for (int j = 0; j < n; ++j) {           // para cada otro vertice j
            D2[i][j] = cost[j * TANK_SIZE];
        }
    }

    //ret
    cout << "Dijkstra Denso: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {              //no imprimo costo a mi mismo siempre 0 no hay ciclos negativos
                cout << i << " " << j << " " << D2[i][j] << endl;
            }
        }
    }
    // --------------------------DIJKSTRA DENSO TERMINA ACA ---------------------------

    // --------------------------BELLMAN  EMPIEZA ACA   -------------------------------------------------
    int D3[n][n];      // diccionario de costos minimos n * n
    for (int i = 0; i < n; ++i) {       // para cada vertice i
        vector<int> cost(n * TANK_SIZE,infinity);                                              // -1 = indefinido
        BellmanFord(G, i * TANK_SIZE, cost);      // calculo su costo minimo al resto
        for (int j = 0; j < n; ++j) {           // para cada otro vertice j
            D3[i][j] = cost[j * TANK_SIZE];
        }
    }

    //ret
    cout << "BellmanFord: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {              //no imprimo costo a mi mismo siempre 0 no hay ciclos negativos
                cout << i << " " << j << " " << D3[i][j] << endl;
            }
        }
    }
    // -------------------------------- BELLMAN TERMINA ACA -------------------------------------------

    // ---------------------------FLOYD EMPIEZA ACA ----------------------------
    vector<vector<int>> D4(n * TANK_SIZE, vector<int> (n * TANK_SIZE, infinity));
    Floyd(G, D4);

    //ret
    cout << "Floyd: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {              //no imprimo costo a mi mismo siempre 0 no hay ciclos negativos
                cout << i << " " << j << " " << D4[i*TANK_SIZE][j*TANK_SIZE] << endl;
            }
        }
    }
    //---------------------------FLOYD TERMINA ACA -------------------------------------

    return 0;
}
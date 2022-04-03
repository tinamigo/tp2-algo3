#include "disjointSet.h"
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int K = 255;
    if (argc == 2) {
        K = atoi(argv[1]);
    }
    int h, w;
    cin >> w >> h;
    matrix image(h, vector<int>(w));
    // Levanto los pixeles de la imagen
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> image[i][j];
        }
    }
    // Creo el grafo correspondiente -uniendo 8 cercanos-
    graph G;
    buildGraph(image, G, h, w);         // construyo el grafo con lista de aristas
    counting_sort(G);

    disjointSet components(h*w);        // inicializo un disjoint set con la cant de pixeles
    vector<int> max_edge(h*w,0);        // inicializo maxima arista de cada componente en 0, es valido para la indexacion en el rep de la comp

    for (int k = 0; k < G.size(); ++k) {
        int a,b,w;
        tie(a,b,w) = G[k];
        int finda = components.find(a);
        int findb = components.find(b);
        if (finda != findb and w < min(max_edge[finda] + K/ components.size(finda) , max_edge[findb] + K/components.size(findb))) {
            components.unite(finda, findb);
            max_edge[components.find(finda)] = maximum(w, max_edge[finda], max_edge[findb]);
        }
    }

    // Imprimo por pantalla la solucion
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << components.find(which_vertix(i,j,w)) << " ";
        }
        cout << endl;
    }
    return 0;
}

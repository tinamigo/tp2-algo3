#include "defines.h"

using namespace std;

vertix which_vertix(int i, int j, int w) {
    return w * i + j;
}

int dif(int a, int b) {
    if (a > b) {
        return a-b;
    }
    return b-a;
}

int weight(edge a) {
    return get<2>(a);
}

void buildGraph(matrix& image, graph& G, int h, int w) {
    // Voy a agregar aristas con un orden topografico de hacia abajo y a la derecha
    // Calculo cuatro esquinas
    // Esquina superior izquierda
    G.push_back({ which_vertix(0,0,w), which_vertix(0,1,w), dif(image[0][0], image[0][1]) });
    G.push_back({ which_vertix(0,0,w), which_vertix(1,0,w), dif(image[0][0], image[1][0]) });
    G.push_back({ which_vertix(0,0,w), which_vertix(1,1,w), dif(image[0][0], image[1][1]) });
    // Esquina inferior izquierda
    G.push_back({ which_vertix(h-1,0,w), which_vertix(h-1,1,w), dif(image[h-1][0], image[h-1][1]) });
    // Borde superior
    for (int i = 1; i < w-1; ++i) {
        G.push_back({ which_vertix(0,i,w), which_vertix(0,i+1,w), dif(image[0][i], image[0][i+1]) });
        G.push_back({ which_vertix(0,i,w), which_vertix(1,i-1,w), dif(image[0][i], image[1][i-1]) });
        G.push_back({ which_vertix(0,i,w), which_vertix(1,i+1,w), dif(image[0][i], image[1][i+1]) });
        G.push_back({ which_vertix(0,i,w), which_vertix(1,i,w), dif(image[0][i], image[1][i]) });
    }
    // Borde inferior
    for (int i = 1; i < w-1; ++i) {
        G.push_back({ which_vertix(h-1,i,w), which_vertix(h-1,i+1,w), dif(image[h-1][i], image[h-1][i+1]) });
    }
    // Borde izquierdo
    for (int j = 1; j < h-1; ++j) {
        G.push_back({ which_vertix(j,0,w), which_vertix(j+1,0,w), dif(image[j][0], image[j+1][0]) });
        G.push_back({ which_vertix(j,0,w), which_vertix(j+1,1,w), dif(image[j][0], image[j+1][1]) });
        G.push_back({ which_vertix(j,0,w), which_vertix(j,1,w), dif(image[j][0], image[j][1]) });
    }
    // Borde derecho + esquina superior derecha
    for (int k = 0; k < h-1; ++k) {
        G.push_back({ which_vertix(k,w-1,w), which_vertix(k+1,w-1,w), dif(image[k][w-1], image[k+1][w-1]) });
        G.push_back({ which_vertix(k,w-1,w), which_vertix(k+1,w-2,w), dif(image[k][w-1], image[k+1][w-2]) });
    }
    // Interior
    for (int i = 1; i < h-1; ++i) {
        for (int j = 0; j < w-1; ++j) {
            G.push_back({ which_vertix(i,j,w), which_vertix(i,j+1,w), dif(image[i][j], image[i][j+1]) });
            G.push_back({ which_vertix(i,j,w), which_vertix(i+1,j-1,w), dif(image[i][j], image[i+1][j-1]) });
            G.push_back({ which_vertix(i,j,w), which_vertix(i+1,j,w), dif(image[i][j], image[i+1][j]) });
            G.push_back({ which_vertix(i,j,w), which_vertix(i+1,j+1,w), dif(image[i][j], image[i+1][j+1]) });
        }
    }
}

int maximum(int a, int b, int c) {
    if (a >= b and a >= c) {
        return a;
    } else if ( b >= a and b >= c ) {
        return b;
    } else {
        return c;
    }
}

void counting_sort(graph& G) {
    graph H;
    vector<vector<edge>> weight_count(256);
    for (int i = 0; i < G.size(); ++i) {
        weight_count[weight(G[i])].push_back(G[i]);
    }
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i < weight_count[j].size(); ++i) {
            H.push_back(weight_count[j][i]);
        }
    }
    G = H;
}

#ifndef ENTREGABLE_DEFINES_H
#define ENTREGABLE_DEFINES_H

#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

typedef int vertix;
typedef pair<int,int> neighbour;
typedef tuple<int,int,int> edge;
typedef vector<tuple<int,int,int>> graph;
typedef vector<vector<int>> matrix;

vertix which_vertix(int i, int j, int w);
int dif(int a, int b);
int weight(edge a);
void buildGraph(matrix& image, graph& G, int h, int w);
int maximum(int a, int b, int c);
void counting_sort(graph& G);

#endif //ENTREGABLE_DEFINES_H

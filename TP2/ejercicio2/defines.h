#ifndef EJERCICIO2_DEFINES_H
#define EJERCICIO2_DEFINES_H
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>
#include <climits>


using namespace std;

#define TANK_SIZE 60
#define undefined -1
#define infinity INT_MAX
typedef int vertice;
typedef pair<int,int> neighbour;
typedef tuple<int,int,int> edge;
typedef vector<vector<neighbour>> grafo;

int dst(neighbour n);
int cost(neighbour n);
int src(edge e);
int dst(edge e);
int cost(edge e);


#endif //EJERCICIO2_DEFINES_H

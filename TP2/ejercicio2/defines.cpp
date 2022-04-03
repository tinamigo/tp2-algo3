#include "defines.h"

int dst(neighbour n) { return get<0>(n); }
int cost(neighbour n) { return get<1>(n); }
int src(edge e) { return get<0>(e); }
int dst(edge e) { return get<1>(e); }
int cost(edge e) { return get<2>(e); }
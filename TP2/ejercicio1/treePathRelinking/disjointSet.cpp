#include "disjointSet.h"

using namespace std;

disjointSet::disjointSet(int n):_name(), _size() {
    for (int i = 0; i < n; ++i) {
        _name.push_back(i);
        _size.push_back(1);
    }
}

void disjointSet::unite(int i, int j) { //i come a j
    int rep_j = find(j);
    int rep_i = find(i);
    _name[rep_j] = rep_i;
    _size[rep_i] = _size[rep_i] + _size[rep_j];
}

int disjointSet::find(int i) {
    int it = i;
    if(it != _name[it]) {
        _name[it] = find(_name[it]);
    }
    return _name[it];
}

int disjointSet::size(int i) {
    return _size[find(i)];
}
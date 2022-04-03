#include "disjointSet.h"

using namespace std;

disjointSet::disjointSet(int n):_name(), _size() {
    for (int i = 0; i < n; ++i) {
        _name.push_back(i);
        _size.push_back(1);
    }
}

void disjointSet::unite(int i, int j) {
    int rep_j = find(j);
    int rep_i = find(i);
    if (rep_i != rep_j) {
        for (int k = 0; k < _name.size(); ++k) {
            if (_name[k] == rep_j) {
                _name[k]= rep_i;
            }
        }
        // actualizo size
        _size[rep_i] = _size[rep_i] + _size[rep_j];
    }
}

int disjointSet::find(int i) {
    return _name[i];
}

int disjointSet::size(int i) {
    return _size[find(i)];
}
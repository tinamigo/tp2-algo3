
#ifndef ENTREGABLE_DISJOINTSET_H
#define ENTREGABLE_DISJOINTSET_H

#include "../defines.h"
#include<vector>

using namespace std;

class disjointSet {
public:
    disjointSet(int n);
    void unite(int i, int j);
    int find(int i);
    int size(int i);
private:
    vector<int> _name;
    vector<int> _size;
};


#endif //ENTREGABLE_DISJOINTSET_H

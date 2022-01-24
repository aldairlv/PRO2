#include "max_min.hh"

parint max_min1(const vector<int>& v) {
    int t = v.size();
    parint m;
    m.prim = m.seg = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > m.prim) m.prim = v[i];
        if (v[i] < m.seg) m.seg = v[i];
    }
    return m;
}

pair<int,int> max_min2(const vector<int>& v) {
    int t = v.size();
    pair <int,int> m;
    m.first = m.second = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > m.first) m.first = v[i];
        if (v[i] < m.second) m.second = v[i];
    }
    return m;
}
 
void max_min3(const vector<int>& v, int& x, int& y) {
    int t = v.size();
    x = y = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}


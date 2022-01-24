#include "max_min_vest1.hh"

parint nota_maxmin_v1_vest1(const vector<Estudiant>& v) {
    int t = v.size();
    parint m;
    // m.prim = maxima nota
    // m.seg = minima nota

    int i = 0;
    while (not v[i].te_nota() and i < t) ++i;
    m.prim = m.seg = v[i].consultar_nota();
    ++i;
    for (int j = i; j < t; ++j) {
        if (v[j].consultar_nota() > m.prim) m.prim = v[j].consultar_nota();
        else if (v[j].consultar_nota() < m.seg) m.seg = v[j].consultar_nota();
    }
    
    return m;
}

pair<double,double> nota_maxmin_v1_vest2(const vector<Estudiant>& v) {
    int t = v.size();
    pair <double,double> m;
  
    int i = 0;
    while (not v[i].te_nota() and i < t) ++i;
    m.first = m.second = v[i].consultar_nota();
    ++i;
    for (int j = i; j < t; ++j) {
        if (v[j].consultar_nota() > m.first) m.first = v[j].consultar_nota();
        else if (v[j].consultar_nota() < m.second) m.second = v[j].consultar_nota();
    }

    return m;
}
 
void nota_maxmin_v1_vest3(const vector<Estudiant>& v, double& x, double& y) {
    int t = v.size();
    int i = 0;
    while (not v[i].te_nota() and i < t) ++i;
    x = y = v[i].consultar_nota();
    i++;
    for (int j = i; j < t; ++j) {
        if (v[j].consultar_nota() > x) x = v[j].consultar_nota();
        if (v[j].consultar_nota() < y) y = v[j].consultar_nota();
    }
}


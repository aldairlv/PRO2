#include "max_min_vest3.hh"

parint nota_maxmin_v3_vest1(const vector<Estudiant>& v) {
    int t = v.size();
    parint m;
    m.maxPos = m.minPos = -1;
    int i = 0;
    bool found = false;
    while (not found and i < t) {
        if (v[i].te_nota()) {
            m.maxPos = m.minPos = i;
            found = true;
        }
        else ++i;
    }
    ++i;
    for (int j = i; j < t; ++j) {
        if (v[j].te_nota()) {   
            // Si su nota es mayor o igual
            if (v[j].consultar_nota() > v[m.maxPos].consultar_nota()) m.maxPos = j;
            else if (v[j].consultar_nota() == v[m.maxPos].consultar_nota() and 
                     v[j].consultar_DNI() < v[m.maxPos].consultar_DNI()) m.maxPos = j;
            // Si su nota es menor o igual
            if (v[j].consultar_nota() < v[m.minPos].consultar_nota()) m.minPos = j;
            else if (v[j].consultar_nota() == v[m.minPos].consultar_nota() and 
                     v[j].consultar_DNI() < v[m.minPos].consultar_DNI()) m.minPos = j;
        }
    }
    return m;
}

pair<int,int> nota_maxmin_v3_vest2(const vector<Estudiant>& v) {
    int t = v.size();
    pair <int,int> posMaxMin;    
    posMaxMin.first = posMaxMin.second = -1;
    int i = 0;
    bool found = false;
    while (not found and i < t) {
        if(v[i].te_nota()) {
            posMaxMin.first = posMaxMin.second = i;
            found = true;
        }
        else ++i;
    }
    ++i;
    for (int j = i; j < t; ++j) {
        if (v[j].te_nota()) {
            // Si su nota es mayor o igual
            if (v[j].consultar_nota() > v[posMaxMin.first].consultar_nota()) posMaxMin.first = j;
            else if (v[j].consultar_nota() == v[posMaxMin.first].consultar_nota() and 
                     v[j].consultar_DNI() < v[posMaxMin.first].consultar_DNI()) posMaxMin.first = j;
            // Si su nota es menor o igual
            if (v[j].consultar_nota() < v[posMaxMin.second].consultar_nota()) posMaxMin.second = j;
            else if (v[j].consultar_nota() == v[posMaxMin.second].consultar_nota() and 
                     v[j].consultar_DNI() < v[posMaxMin.second].consultar_DNI()) posMaxMin.second = j;
        }
    }
    return posMaxMin;
}
 
void nota_maxmin_v3_vest3(const vector<Estudiant>& v, int& posMax, int& posMin) {
    int t = v.size();
    posMax = posMin = -1;
    int i = 0;
    bool found = false;
    while (not found and i < t) {
        if(v[i].te_nota()) {
            posMax = posMin = i;
            found = true;
        }
        else ++i;
    }
    i++;
    for (int j = i; j < t; ++j) {
        if (v[j].te_nota()) {
            // Si su nota es mayor o igual
            if (v[j].consultar_nota() > v[posMax].consultar_nota()) posMax = j;
            else if (v[j].consultar_nota() == v[posMax].consultar_nota() and 
                     v[j].consultar_DNI() < v[posMax].consultar_DNI()) posMax = j;
            // Si su nota es menor o igual 
            if (v[j].consultar_nota() < v[posMin].consultar_nota()) posMin = j;
            else if (v[j].consultar_nota() == v[posMin].consultar_nota() and 
                     v[j].consultar_DNI() < v[posMin].consultar_DNI()) posMin = j;
        }
    }
}

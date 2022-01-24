#include "Estudiant.hh"
#include <vector>

pair<int,int> max_min_vest(const vector<Estudiant>& v) {
    /* Pre: v no conte repeticions de dni  */
    /* Post: si existeix a v algun estudiant amb nota, la primera component del
             resultat es la posicio de l'estudiant de nota maxima de v i la segona
             component es la posicio de l'estudiant de nota minima de v (si hi ha
             empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
             hi ha cap estudiant amb nota, totes dues components valen -1 */

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

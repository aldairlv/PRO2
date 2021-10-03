#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos) {
    /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
    /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
             nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
             ordre que a V */
    int t =  v.size();
    int j = 0;
    for (int i = 1; i < t; ++i) {
        if (v[i].consultar_DNI() == v[j].consultar_DNI()) {
            if (not v[j].te_nota() and v[i].te_nota()) v[j].afegir_nota(v[i].consultar_nota());
            else if (v[j].te_nota() and v[i].te_nota() and v[i].consultar_nota() > v[j].consultar_nota()) v[j].modificar_nota(v[i].consultar_nota()); 
        }
        else {
            ++j;
            v[j] = v[i];
        }
    }
    pos = j;
}

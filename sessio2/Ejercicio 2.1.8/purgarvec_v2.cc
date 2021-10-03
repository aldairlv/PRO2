#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

vector<Estudiant> leer_vector() {
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for (int i = 0; i < n; i++) v[i].llegir();
    return v;
}

void purgarvec(vector<Estudiant>& v, int& pos) {
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

void escribir_vector(const vector<Estudiant>& v, const int& pos) {
    for (int i = 0; i <= pos; ++i) v[i].escriure();
}

int main () {
    vector<Estudiant> v;
    v = leer_vector();
    int i = 0;
    purgarvec(v,i);
    escribir_vector(v,i);
}

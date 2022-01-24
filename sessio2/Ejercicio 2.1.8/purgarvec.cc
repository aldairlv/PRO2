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

vector<Estudiant> purgarvec(const vector<Estudiant>& v) {
    vector<Estudiant> w;
    int t =  v.size();
    Estudiant est = v[0];
    w.push_back(est);
    int j = 0;
    for (int i = 1; i < t; ++i) {
        if (v[i].consultar_DNI() == w[j].consultar_DNI()) {
            if (not w[j].te_nota() and v[i].te_nota()) w[j].afegir_nota(v[i].consultar_nota());
            else if (w[j].te_nota() and v[i].te_nota() and v[i].consultar_nota() > w[j].consultar_nota()) w[j].modificar_nota(v[i].consultar_nota());
    
        }
        else {
            ++j;
            est = v[i];
            w.push_back(est);
        }
    }
    return w;
}

void escribir_vector(const vector<Estudiant>& v) {
    int t = v.size();
    for (int i = 0; i < t; ++i) v[i].escriure();
}

int main () {
    vector<Estudiant> v;
    v = leer_vector();
    vector<Estudiant> v_result;
    v_result = purgarvec(v);
    cout << endl;
    escribir_vector(v_result);
}

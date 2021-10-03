#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

bool cmp (const Estudiant& a, const Estudiant& b) {
        if (a.consultar_nota() == b.consultar_nota()) return a.consultar_DNI() < b.consultar_DNI();
        return a.consultar_nota() > b.consultar_nota();
}

int main() {
    int m; // nombre d'estudiants
    int n; // nombre d'assignatures
    int s; // nombre d'assignatures seleccionades
    cin >> m >> n >> s;
    vector<bool> v(n,false);
    for (int i = 0; i < s; ++i) {
        int pos;
        cin >> pos;
        v[pos-1] = true;
    }
    vector<Estudiant> w(m);
    for (int i = 0; i < m; ++i) {
        int dni;
        cin >> dni;
        double nota_media = 0;
        for (int j = 0; j < n; ++j) {
            double e_nota;
            cin >> e_nota;
            if (v[j]) nota_media += e_nota;
        }
        nota_media /= double(s);
        Estudiant est(dni);
        est.afegir_nota(nota_media);
        w[i] = est;
    }
    sort(w.begin(), w.end(), cmp);
    for (int i = 0; i < m; i++) w[i].escriure();
}


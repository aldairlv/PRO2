#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

void insertion_sort(vector<Estudiant>& v) {
    int t = v.size();
    for (int i = 1; i < t; ++i) {
        double x = v[i].consultar_nota();
        int e_dni = v[i].consultar_DNI();
        int  j = i;
        while (j > 0 and v[j-1].consultar_nota() < x) {
            v[j] = v[j-1];
            --j;
        }
        Estudiant est(e_dni);
        est.afegir_nota(x);
        v[j] = est;
    }
}

void escribir_vector(const vector<Estudiant>& w, const int& k) {
    cout << "Los " << k << " mejores estudiantes y sus medias:" << endl;
    for (int i = 0; i < k; i++) w[i].escriure();
}

int main() {
    int m; // nombre d'estudiants
    int k; // nombre d'estudiants seleccionats
    int n; // nombre d'assignatures
    int s; // nombre d'assignatures seleccionades
    cin >> m >> k >> n >> s;
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
    insertion_sort(w);
    escribir_vector(w,k);
}


#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

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
    for (int i = 0; i < m; ++i) {
        int dni;
        cin >> dni;
        double nota_media = 0;
        for (int j = 0; j < n; ++j) {
            double e_nota;
            cin >> e_nota;
            if (v[j]) nota_media += e_nota;
        }
        nota_media /= s;
        cout << dni << " " << nota_media << endl;
    }
}


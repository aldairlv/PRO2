#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< pair<int,int> > fila;
typedef vector<fila> matriz;

struct result {
    int equip = 0;
    int punts = 0;
    int marcats = 0;
    int rebuts = 0;
};

void leer_matriz(matriz& m) {
    int t =  m.size();
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) cin >> m[i][j].first >> m[i][j].second;
    }
}

void mostrar_res(vector<result>& m) {
    int f = m.size();
    for (int i = 0; i < f; ++i) cout << m[i].equip << " " << m[i].punts << " " << m[i].marcats << " " << m[i].rebuts << endl;
}

void clasificacio(const matriz& m, vector<result>& r){
    int t = m.size();
    for (int pos = 0; pos < t; ++pos) {        
        r[pos].equip = pos + 1;
        for (int i = 0; i < t; ++i) {
            if (i != pos) {
                r[pos].marcats += m[pos][i].first + m[i][pos].second;
                r[pos].rebuts += m[pos][i].second + m[i][pos].first;
                //filas
		if (m[pos][i].first > m[pos][i].second) r[pos].punts += 3;
                else if (m[pos][i].first == m[pos][i].second) r[pos].punts += 1;
                //columnas
                if (m[i][pos].first < m[i][pos].second) r[pos].punts += 3;
                else if (m[i][pos].first == m[i][pos].second) r[pos].punts += 1;
	    }
	}
    }
}

bool comp(const result& a, const result& b) {
    if (a.punts == b.punts) {
        int r1 = a.marcats - a.rebuts;
        int r2 = b.marcats - b.rebuts;
        if (r1 == r2) return a.equip < b.equip;
        return r1 > r2;
    }
    return a.punts > b.punts;
}

int main() {
    int n;
    cin >> n;
    matriz mat(n,fila(n));
    leer_matriz(mat);
    vector<result> r(n);
    clasificacio(mat, r);
    sort(r.begin(), r.end(), comp);
    mostrar_res(r);
}

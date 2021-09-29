#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

using namespace std;

void redondear_vec_a(vector<Estudiant>& v) {
	int t = v.size();
	for (int i = 0; i < t; ++i) {
		if (v[i].te_nota()) {
			v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
		}
	}
}

int main() {
	vector<Estudiant> v;
	leer_vector_estudiant(v);
	redondear_vec_a(v);
	cout << endl;
	cout << "Ahora escribimos el vector para ver si ha cambiado:" << endl;
	escribir_vector_estudiant(v);
}

#include "vectorIOEstudiant.hh"

/* Leer vector d'Estudiants */

void leer_vector_estudiant(vector<Estudiant>& v) {
	cout << "Escribe el tamaño del vector:" << endl;
	int numVecEst;
	cin >> numVecEst;
	v = vector<Estudiant> (numVecEst);

	cout << "Escribe los elementos del vector:" << endl;
	for (int i = 0; i < numVecEst; ++i) {
		v[i].llegir();

	}
}

/* Escribir vector d'Estudiants */
void escribir_vector_estudiant(const vector<Estudiant>& v) {
	int t = v.size();
	for (int i = 0; i < t; ++i) {
		v[i].escriure();
	}
}

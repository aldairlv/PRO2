#include <iostream>
#include <vector>
#include "vectorIOint.hh"
using namespace std;

void intercambiar_vect(vector<int>& v, int i, int j) {
/* Pre: 0 <= i, j < v.size() */
/* Post: v[i] y v[j] tienen sus valores intercambiados respecto a los iniciales */
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int main() {
    vector<int> v;
    leer_vector_int(v);
    cout << endl;
    cout << "Introduce las posiciones que quieres intercambiar. Tened en cuenta que las posiciones disponibles son las del intervalo [0..n-1]: ";
    int i, j;
    cin >> i >> j;
    intercambiar_vect(v, i, j);
    cout << endl;
    cout << "Escribimos el vector para ver si se ha producido el intercambio:" << endl;
    escribir_vector_int(v);
}

#include <iostream>
#include "vectorIOEstudiant.hh"

using namespace std;

bool busqueda_lin_vest(const vector<Estudiant>& v, int e_dni, int& pos) {
    int t = v.size();
    for (int i = 0; i < t; ++i) {
        if (v[i].consultar_DNI() == e_dni) {
            pos = i;
            return true;
        }
    }
    return false;
}


int main() {
  vector<Estudiant> v;
  leer_vector_estudiant(v); 
  cout << "Escribe el DNI a buscar: " << endl;
  int x;
  cin >> x; 
  int pos = 0;
  bool found = busqueda_lin_vest(v,x,pos);
  if (found)  {
      cout << "El estudiante está en el vector";
      if (v[pos].te_nota()) cout << " y su nota es " << v[pos].consultar_nota() << endl;
      else cout << ", pero no tiene nota" << endl;
  }
  else cout << "El estudiante no está en el vector" << endl;
}

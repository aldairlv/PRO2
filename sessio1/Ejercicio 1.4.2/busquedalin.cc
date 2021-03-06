#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */    
bool busqueda_lin(const vector<int>& v, int x, int& pos)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) {
        pos = i;
        return true;
    } 
    else ++i;
  }
  return b;
}

int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int pos = 0;
  bool b = busqueda_lin(v,x,pos);
  if (b)  {
      cout << "El elemento " << x << " esta en el vector, en la posición " << ++pos << "." << endl << endl;
  }
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}

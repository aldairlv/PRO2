#include <iostream>
using namespace std;

int main() {
  cout << "Entra una secuencia de enteros: ";
  int suma = 0;
  int num;
  cin >> num;
  while (num != 0) {
      suma += num;
      cin >> num;
  }
  cout << "El resultado de la suma es: " << suma << endl; 
}

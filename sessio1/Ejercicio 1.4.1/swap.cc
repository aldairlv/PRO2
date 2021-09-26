#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int main() {
    int a, b;
    cout << "Introduce el valor de 'a': ";
    cin >> a;
    cout << endl;
    cout << "Introduce el valor de 'b': ";
    cin >> b;
    cout << endl;
    swap(a,b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

}

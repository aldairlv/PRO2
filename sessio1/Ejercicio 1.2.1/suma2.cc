#include <iostream>
using namespace std;

int main() {
    int num;
    int suma = 0;
    string s;
    int i = 1;
    while (cin >> num) {
        if (num == 0) {
            cout << "La suma de la secuencia " << i << " es "<< suma << endl;
            ++i;
            suma = 0;
            getline(cin, s);       
        }
        else suma += num;
    }
}

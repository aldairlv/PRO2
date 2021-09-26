#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        string s;
        while (num != x) {
            total = total + num;
            cin >> num;
        }
        getline(cin,s);
        cout << "La suma de la secuencia " << i << " es " << total << endl;
        total = 0;
    }
}

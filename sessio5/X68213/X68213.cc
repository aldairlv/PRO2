#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void mostrar(stack<string> w) {
    while (not w.empty()) {
        cout << w.top() << endl;
        w.pop();
    }
}

int main() {
    int n;
    cin >> n;
    vector<stack<string>> v(n);
    int op;
    cin >> op;
    while (op != -4) {
        if (op == -1) {
            string titulo;
            int categ;
            cin >> titulo >> categ;
            v[categ-1].push(titulo);
        }
        else if (op == -2) {
            int rm, categ;
            cin >> rm >> categ;
            for (int i = 0; i < rm; ++i) v[categ-1].pop();
        }
        else {
            int categ;
            cin >> categ;
            cout << "Pila de la categoria " << categ << endl;
            mostrar(v[categ-1]);
            cout << endl;

        }
        cin >> op;
    }

}

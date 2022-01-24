#include <iostream>
#include <stack>
using namespace std;

void llegir(stack<int>& s, const int& t) {
    for (int i = 0; i < t; ++i) {
        int num;
        cin >> num;
        s.push(num);
    }
}

bool es_palindrom(const int& n) {
    if (n < 2) return true;
    else {
        stack<int> seq;
        if (n%2 == 0) llegir(seq, n/2);
        else {
            llegir(seq, n/2 + 1);
            seq.pop();
        }
        while(not seq.empty()) {
            int num;
            cin >> num;
            if (num == seq.top()) seq.pop();
            else return false;
        }
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    bool b;
    b = es_palindrom(n);
    if (b) cout << "SI";
    else cout << "NO";
    cout << endl;
}

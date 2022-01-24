#include <iostream>
#include <stack>
using namespace std;

bool es_correcte(stack<char>& s) {
    char c;
    cin >> c;
    while (c != '.') {
    	if (s.empty()) {
	    if (c == ')' or c == ']') return false;
	    else s.push(c);
    	}
	else {
	    if (c == ')') {
		if (s.top() != '(') return false;
		else s.pop();
	    }
	    else if(c == ']') {
		if (s.top() != '[') return false;
		else s.pop();
	    }
            else if (c == '(' or c == '[') s.push(c);
	}
	cin >> c;
    }

    return s.empty();
}

int main() {
    stack<char> seq;
    bool b;
    b = es_correcte(seq);
    if (b) cout << "Correcte";
    else cout << "Incorrecte";
    cout << endl;
}

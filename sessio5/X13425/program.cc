#include <iostream>
#include <queue>
#include "ParInt.hh"
#include "CuaIOParInt.hh"

using namespace std;

void reparteixCua (queue<ParInt>& c, queue<ParInt>& a, queue<ParInt>& b) {
    int time_a = 0;
    int time_b = 0;
    while (not c.empty()) {
        if (time_a < time_b) {
            a.push(c.front());
            time_a += (c.front()).segon();
            c.pop();
        }
        else if (time_a > time_b){
            b.push(c.front());
            time_b += (c.front()).segon();
            c.pop();
        }
        else {
            a.push(c.front());
            time_a += (c.front()).segon();
            c.pop();
        }
    }
}

int main() {
    queue<ParInt> c;
    llegirCuaParInt(c);
    queue<ParInt> a;
    queue<ParInt> b;
    reparteixCua(c,a,b);
    escriureCuaParInt(a);
    cout << endl;
    escriureCuaParInt(b);
}

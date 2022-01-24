#include <iostream>
#include <queue>
#include "ParInt.hh"
using namespace std;

void llegirCuaParInt(queue<ParInt>& c) {
// Pre: c és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)
    /*int a, b;
    cin >> a >> b;
    while (not (a == 0 and b == 0)) {
        ParInt elem(a,b);
        c.push(elem);
        cin >> a >> b;
    */
    ParInt elem;
    while (elem.llegir()) c.push(elem);
    //}
}


void escriureCuaParInt(queue<ParInt> c) {
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de c
    while (not c.empty()) {
        //ParInt elem;
        //elem =  c.front();
        //cout << elem.primer() << " " << elem.segon() << endl;
        (c.front()).escriure();
        c.pop();
    }
}

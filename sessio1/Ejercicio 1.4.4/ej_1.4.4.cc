#include <iostream>
#include <vector>
#include "vectorIOint.hh"
#include "max_min.hh"

using namespace std;

int main() {
    vector<int> v;
    leer_vector_int(v);
    parint result1;
    result1 = max_min1(v);
    cout << "max_min1: " << result1.prim << " " << result1.seg << endl; 
    pair<int,int> result2;
    result2 = max_min2(v);
    cout << "max_min2: " << result2.first << " " << result2.second << endl;
    int resultx, resulty;
    max_min3(v,resultx,resulty);
    cout << "max_min3: " << resultx << " " << resulty << endl;
}

#include <iostream>
#include <vector>
#include "vectorIOEstudiant.hh"
#include "max_min_vest1.hh"

using namespace std;

int main() {
    vector<Estudiant> v;
    leer_vector_estudiant(v);
    parint result1;
    result1 = nota_maxmin_v1_vest1(v);
    cout << endl;
    cout << "nota max: " << result1.prim << " nota min: " << result1.seg << endl;

    pair<double,double> result2;
    result2 = nota_maxmin_v1_vest2(v);
    cout << endl;
    cout << "nota max: " << result2.first << " nota min: " << result2.second << endl;

    double resultx, resulty;
    nota_maxmin_v1_vest3(v,resultx,resulty);
    cout << endl;
    cout << "nota max: " << resultx << " nota min: " << resulty << endl;

}

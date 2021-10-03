#include <iostream>
#include <vector>
#include "vectorIOEstudiant.hh"
#include "max_min_vest3.hh"

using namespace std;

int main() {
    vector<Estudiant> v;
    leer_vector_estudiant(v);
    parint result1;
    result1 = nota_maxmin_v3_vest1(v);
    cout << endl;
    if (result1.maxPos == -1) cout << "no hay ningun estudiante con nota" << endl;
    else {
        cout << "estudiante con nota max: "; 
        v[result1.maxPos].escriure(); 
        cout << "estudiante con nota min: ";
        v[result1.minPos].escriure();
        cout << endl;
    }

    pair<double,double> result2;
    result2 = nota_maxmin_v3_vest2(v);
    cout << endl;
    if (result2.first == -1) cout << "no hay ningun estudiante con nota" << endl;
    else {
        cout << "estudiante con nota max: ";
        v[result2.first].escriure();
        cout << "estudiante con nota min: ";
        v[result2.second].escriure();
        cout << endl;
    }

    int result_maxPos, result_minPos;
    nota_maxmin_v3_vest3(v,result_maxPos,result_minPos);
    cout << endl;
    if (result_maxPos == -1) cout << "no hay ningun estudiante con nota" << endl;
    else {
        cout << "estudiante con nota max: ";
        v[result_maxPos].escriure();
        cout << "estudiante con nota min: ";
        v[result_minPos].escriure();
        cout << endl;
    }

}

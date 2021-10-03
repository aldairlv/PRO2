#include <iostream>
#include <vector>
#include "vectorIOEstudiant.hh"
#include "max_min_vest2.hh"

using namespace std;

int main() {
    vector<Estudiant> v;
    leer_vector_estudiant(v);
    parint result1;
    result1 = nota_maxmin_v2_vest1(v);
    cout << endl;
    cout << "estudiante con nota max: "; 
    v[result1.maxPos].escriure(); 
    cout << "estudiante con nota min: ";
    v[result1.minPos].escriure();
    cout << endl;

    pair<double,double> result2;
    result2 = nota_maxmin_v2_vest2(v);
    cout << endl;
    cout << "estudiante con nota max: ";
    v[result2.first].escriure();
    cout << "estudiante con nota min: ";
    v[result2.second].escriure();
    cout << endl;

    int result_maxPos, result_minPos;
    nota_maxmin_v2_vest3(v,result_maxPos,result_minPos);
    cout << endl;
    cout << "estudiante con nota max: ";
    v[result_maxPos].escriure();
    cout << "estudiante con nota min: ";
    v[result_minPos].escriure();
    cout << endl;

}

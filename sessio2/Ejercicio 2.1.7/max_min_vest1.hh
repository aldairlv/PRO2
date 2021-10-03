#ifndef VECTOR_EST_MAX_MIN
#define VECTOR_EST_MAX_MIN

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

struct parint {double prim, seg;};

parint nota_maxmin_v1_vest1(const vector<Estudiant>& v);

pair<double,double> nota_maxmin_v1_vest2(const vector<Estudiant>& v);
 
void nota_maxmin_v1_vest3(const vector<Estudiant>& v, double& x, double& y);

#endif

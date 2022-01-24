#ifndef VECTOR_EST_MAX_MIN_v2
#define VECTOR_EST_MAX_MIN_v2

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

struct parint {int maxPos, minPos;};

parint nota_maxmin_v2_vest1(const vector<Estudiant>& v);

pair<int,int> nota_maxmin_v2_vest2(const vector<Estudiant>& v);
 
void nota_maxmin_v2_vest3(const vector<Estudiant>& v, int& x, int& y);

#endif

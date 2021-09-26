#include <iostream>
#include <vector>
using namespace std;
 
struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v) {
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
    
    int t = v.size();
    parint m;
    m.prim = m.seg = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > m.prim) m.prim = v[i];
        if (v[i] < m.seg) m.seg = v[i];
    }
    return m;
}

pair<int,int> max_min2(const vector<int>& v) {
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
    
    int t = v.size();
    pair <int,int> m;
    m.first = m.second = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > m.first) m.first = v[i];
        if (v[i] < m.second) m.second = v[i];
    }
    return m;
}
 
void max_min3(const vector<int>& v, int& x, int& y) {
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
    int t = v.size();
    x = y = v[0];
    for (int i = 0; i < t; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}

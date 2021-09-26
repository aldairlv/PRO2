#ifndef VECTOR_MAX_MIN
#define VECTOR_MAX_MIN

#include <iostream>
#include <vector>

using namespace std;
 
struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v);
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */

pair<int,int> max_min2(const vector<int>& v);
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
 
void max_min3(const vector<int>& v, int& x, int& y);
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */

#endif

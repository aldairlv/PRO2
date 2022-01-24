#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  imax = -1;
}
  
Cjt_estudiants::~Cjt_estudiants() {}
 
void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = nest-1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 and not b) {  
    if ( dni> vest[i].consultar_DNI()) b = true;
    else {
      vest[i+1]=vest[i];
      --i;
    }
  }
 
  vest[i+1] = est;
  ++nest;
  if (imax != -1 and imax >= i + 1) ++imax;
  if (est.te_nota()) {
    if (imax == -1) imax = i + 1;
    else {
      if (est.consultar_nota() > vest[imax].consultar_nota()) imax = i + 1;
      else if(est.consultar_nota() == vest[imax].consultar_nota() and est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i + 1;
    }
  }
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}  

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  double max_nota = -1;
  if (imax != -1) max_nota = vest[imax].consultar_nota();
  vest[i] = est;
  if (est.te_nota() and imax == -1) imax = i;
 
  else if (i == imax) {
    if (est.te_nota() and (est.consultar_nota() < max_nota)) recalcular_posicio_imax();
    else if (not est.te_nota()) recalcular_posicio_imax();
  } 

  else if (est.te_nota() and imax != -1) {
      if (est.consultar_nota() > vest[imax].consultar_nota()) imax = i;
      else if (est.consultar_nota() == vest[imax].consultar_nota() and 
              est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i;
  }
}    
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  double max_nota = -1;
  if (imax != -1) max_nota = vest[imax].consultar_nota();
  vest[i-1] = est;
  
  if (est.te_nota() and imax == -1) imax = i-1;

  else if (i-1 == imax) { //i-1 jamas podra ser -1, por lo tanto si entra en este if, es porque existe un imax, si existe un imax entonces existira una max_nota
    if (est.te_nota() and (est.consultar_nota() < max_nota)) recalcular_posicio_imax(); // 
    else if (not est.te_nota()) recalcular_posicio_imax();
  } 
 
  else if (est.te_nota() and imax != -1) {
      if (est.consultar_nota() > vest[imax].consultar_nota()) imax = i-1;
      else if (est.consultar_nota() == vest[imax].consultar_nota() and 
              est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i-1;
  }
}
  
int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,comp);
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

void Cjt_estudiants::esborrar_estudiant(int dni) {
    int dni_pos = cerca_dicot(vest,0,nest-1,dni);
    for (int i = dni_pos; i < nest-1; ++i) {
        vest[i] = vest[i+1];
    }
    --nest;
    if (imax > dni_pos) --imax;
    else if (imax == dni_pos) recalcular_posicio_imax();
}
Estudiant Cjt_estudiants::estudiant_nota_max() const{
    return vest[imax];
}

void Cjt_estudiants::recalcular_posicio_imax() {
    double nota_max = -1;
    for (int i = nest - 1; i >= 0; --i) {
        if (vest[i].te_nota()) {
            if (nota_max  <= vest[i].consultar_nota()){
                nota_max = vest[i].consultar_nota();
                imax = i;
            }
        }
    }
}
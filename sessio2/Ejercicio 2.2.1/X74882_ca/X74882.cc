#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

void actualizar_conj(Cjt_estudiants& cjt_est1, const Cjt_estudiants& cjt_est2) {
    int t = cjt_est1.mida();
    for (int i = 1; i <= t; ++i) {
        if (not (cjt_est1.consultar_iessim(i)).te_nota() 
            and (cjt_est2.consultar_iessim(i)).te_nota()) 
            cjt_est1.modificar_estudiant(cjt_est2.consultar_iessim(i));

        else if ((cjt_est1.consultar_iessim(i)).te_nota() and 
                 (cjt_est2.consultar_iessim(i)).te_nota() and 
                 (cjt_est1.consultar_iessim(i)).consultar_nota() < 
                 (cjt_est2.consultar_iessim(i)).consultar_nota()) 
            cjt_est1.modificar_estudiant(cjt_est2.consultar_iessim(i));
    }
}

int main() {
    Cjt_estudiants cjt_e1, cjt_e2;
    cjt_e1.llegir();
    cjt_e2.llegir();
    actualizar_conj(cjt_e1, cjt_e2);
    cjt_e1.escriure();
}

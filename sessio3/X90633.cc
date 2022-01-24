#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    int i = nest-1;
    int dni = est.consultar_DNI();
    int j =  cerca_dicot(vest, 0, i, dni);
      if (j < MAX_NEST and vest[j].consultar_DNI() != est.consultar_DNI()) {
        b = false;
        if (est.te_nota()) {
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }

        bool ord = false;
        while (i >= 0 and not ord) {
            if (dni > vest[i].consultar_DNI()) ord = true;
            else {
                vest[i+1]=vest[i];
                --i;
            }
        }
        vest[i+1] = est;
        ++nest;
    }
    else {
        b = true;
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int dni_pos = cerca_dicot(vest,0,nest-1,dni);
    b = false;

    if (dni_pos < MAX_NEST and vest[dni_pos].consultar_DNI() == dni) {  
        b = true;
        if (vest[dni_pos].te_nota()) {
            suma_notes -= vest[dni_pos].consultar_nota();
            --nest_amb_nota;
        }
        for (int i = dni_pos; i < nest-1; ++i) vest[i] = vest[i+1];
        --nest;
    }
}

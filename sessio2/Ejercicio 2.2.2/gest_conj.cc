#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

/*
    opcion -1:  Añadir un nuevo estudiante; 
                    si no es posible, escribir un mensaje informando del motivo
                
    opción -2:  Consultar la nota de un estudiante a partir de su DNI;
                    si no es posible, escribir un mensaje informando del motivo
    
    opción -3:  Modificar la nota de un estudiante; 
                    si no es posible, escribir un mensaje informando del motivo

    opción -4:  Redondear la nota, a la décima más cercana, a todos los estudiantes del conjunto;

    opción -5:  Escribir el conjunto de estudiantes

    opción -6:  Terminar el programa

 */

int main() {
    Cjt_estudiants cjtEst;
    cjtEst.llegir();
    int i;
    cin >> i;
    while (i != -6) {
        if (i == -1) {
            /* Pre: 1) El parametre implicit no conte cap estudiant amb el dni d'est.
                    2) El nombre d'estudiants del p.i es menor que la mida maxima permesa. */
            Estudiant est;
            est.llegir();
            if (cjtEst.existeix_estudiant(est.consultar_DNI())) {       // 1)
                cout << "el estudiante " << est.consultar_DNI() << " ya estaba" << endl;
            }
            else if (cjtEst.mida() < cjtEst.mida_maxima()) {            // 2)
                cjtEst.afegir_estudiant(est);
            }
            else {
                cout << "el conjunto esta lleno" << endl;
            }
        }
        else if (i == -2) {
            /* Pre: 1) El estudiant ha d'estar al conjunt
                    2) Si está al conjunt ha de tenir nota */
            int e_dni;
            cin >> e_dni;
            if (cjtEst.existeix_estudiant(e_dni)) {
                if ((cjtEst.consultar_estudiant(e_dni)).te_nota()) {
                    cout << "el estudiante " << e_dni << " tiene nota " << (cjtEst.consultar_estudiant(e_dni)).consultar_nota() << endl;
                }
                else {
                    cout << "el estudiante " << e_dni << " no tiene nota" << endl;
                }
            }
            else {
                cout << "el estudiante " << e_dni << " no esta" << endl;
            }

        }
        else if (i == -3) {
            /* Pre: 1) El estudiant ha d'estar al conjunt */
            Estudiant est;
            est.llegir();
            if (cjtEst.existeix_estudiant(est.consultar_DNI())) {
                cjtEst.modificar_estudiant(est);
            }
            else {
                cout << "el estudiante " << est.consultar_DNI() << " no esta" << endl;
            }


        }
        else if (i == -4) {
            /* Pre: 1) L'estudiant del conjunt ha de tenir nota */
            int t = cjtEst.mida();
            for (int i = 1; i < t; ++i) {
                if ((cjtEst.consultar_estudiant(i)).te_nota()) {
                    Estudiant e_aux((cjtEst.consultar_estudiant(i)).consultar_DNI());
                    double e_nota;
                    e_nota = (cjtEst.consultar_estudiant(i)).consultar_nota();
                    e_nota = redondear(e_nota);
                    e_aux.afegir_nota(e_nota);
                    cjtEst.modificar_iessim(i,e_aux);
                }
            }

        }
        else {// i == -5
            cjtEst.escriure();
        }
        cin >> i;
    }

}

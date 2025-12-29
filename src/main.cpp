#include <iostream>
#include "LDLCIRCIPCNC.h"

using namespace std;

int main() {
    LDLCIRCIPCNC lista;
    lista.Inserta(10, 1);
    lista.Inserta(20, 2);
    lista.Inserta(30, 3);
    lista.Inserta(40, 4);
    lista.Inserta(60, 5);
    lista.Inserta(80, 6);
    lista.Inserta(85, 7);
    lista.Inserta(90, 8);
    lista.Inserta(95, 9);
    lista.Inserta(100, 10);
    lista.Despliega();
    return 0;
}
 
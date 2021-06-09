#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include <iostream>
#include "../dataType/DtInstanciaClase.h"
using namespace std;

class DtAsignatura{
    private:
        string nombre;
        string codigo;
        DtInstanciaClase* instanciaClase;
    public:
        DtAsignatura();
        DtAsignatura(string,string,DtInstanciaClase*);
        string getNombre();
        string getCodigo();
        DtInstanciaClase* getInstanciaClase();
        ~DtAsignatura();
};

#endif
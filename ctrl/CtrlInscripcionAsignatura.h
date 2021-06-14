#ifndef CTRLINSCRIPCIONASIGNATURA_H
#define CTRLINSCRIPCIONASIGNATURA_H

#include <iostream>
#include "../interface/ICtrlInscripcionAsignatura.h"

using namespace std;

class CtrlInscripcionAsignatura: public ICtrlInscripcionAsignatura{

private:
    Estudiante* estudiante;
    string codigo;
public:   
    CtrlInscripcionAsignatura();
    list<string> asignaturaNoInscripto();
    void seleccionarAsignatura(string);
    void darDeAltaInscripcion();
    ~CtrlInscripcionAsignatura();
};

#endif
#ifndef CTRLASIGNACIONDOCASIGNATURA_H
#define CTRLASIGNACIONDOCASIGNATURA_H

#include<iostream>

#include "../interface/ICtrlAsignacionDocAsignatura.h"

using namespace std;

class CtrlAsignacionDocAsignatura: public ICtrlAsignacionDocAsignatura{
private:
    string docente;
    string asignatura;
    TipoRol rol;
public:   
    CtrlAsignacionDocAsignatura();
    list<string> listarAsignaturas();
    list<string> docentesSinAsignar(string asignatura);
    void seleccionarDocente(string docente, TipoRol rol);
    void asignarDocente();
    ~CtrlAsignacionDocAsignatura();
};

#endif
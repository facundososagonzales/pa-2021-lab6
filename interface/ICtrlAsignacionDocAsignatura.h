#ifndef ICTRLASIGNACIONDOCASIGNATURA_H
#define ICTRLASIGNACIONDOCASIGNATURA_H

#include <iostream>
#include "../dataType/DtDocente.h"
#include "../dataType/DtAsignatura.h"
#include "../dataType/TipoRol.h"

using namespace std;

class ICtrlAsignacionDocAsignatura{
public:  
    virtual list<string> listarAsignaturas()=0;
    virtual list<string> docentesSinAsignar(string asignatura)=0;
    virtual void seleccionarDocente(string docente)=0;
    virtual void asignarDocente()=0;
};


#endif
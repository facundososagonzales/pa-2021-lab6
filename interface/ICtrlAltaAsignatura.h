#ifndef ICTRLALTAASIGNATURA_H
#define ICTRLALTAASIGNATURA_H

#include <iostream>
#include "../dataType/DtAsignatura.h"

using namespace std;

class ICtrlAltaAsignatura{
public:    
    virtual void ingresar(DtAsignatura datosAsignatura)=0;
    virtual void altaAsignatura()=0;
    virtual void cargarAsignaturas()=0;
};

#endif
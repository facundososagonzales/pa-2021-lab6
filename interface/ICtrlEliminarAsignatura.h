#ifndef ICTRLELIMINARASIGNATURA_H
#define ICTRLELIMINARASIGNATURA_H

#include <iostream>
#include <list>
#include "../dataType/DtAsignatura.h"

using namespace std;

class ICtrlEliminarAsignatura {
public:
    virtual list<string> listarAsignaturas()=0;
    virtual void seleccionarAsignatura(string)=0;
    virtual void eliminarAsignatura()=0;
};

#endif
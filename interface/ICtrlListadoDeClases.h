#ifndef ICTRLLISTADODECLASES_H
#define ICTRLLISTADODECLASES_H

#include <iostream>
#include <list>
#include "../dataType/DtInfoClase.h"

using namespace std;

class ICtrlListadoDeClases{
public:  
    virtual list<string> asignaturasAsignadas()=0;
    virtual list<DtInfoClase*> seleccionarAsignatura(string)=0;
};


#endif
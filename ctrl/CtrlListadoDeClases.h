#ifndef CTRLLISTADODECLASES_H
#define CTRLLISTADODECLASES_H

#include <iostream>
#include <list>
#include "../interface/ICtrlListadoDeClases.h"

using namespace std;

class CtrlListadoDeClases : public ICtrlListadoDeClases{
public:  
    list<string> asignaturasAsignadas();
    list<DtInfoClase*> seleccionarAsignatura(string);
};


#endif
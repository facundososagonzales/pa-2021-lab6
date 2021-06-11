#ifndef CTRLALTAASIGNATURA_H
#define CTRLALTAASIGNATURA_H

#include <iostream>
#include "../interface/ICtrlAltaAsignatura.h"
using namespace std;

class CtrlAltaAsignatura: public ICtrlAltaAsignatura{
private:
    DtAsignatura datosAsignatura;
public:   
    CtrlAltaAsignatura();
    void ingresar(DtAsignatura datosAsignatura);
    void altaAsignatura();
    ~CtrlAltaAsignatura();
};

#endif
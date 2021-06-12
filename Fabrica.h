#ifndef FABRICA_H
#define FABRICA_H

#include "interface/ICtrlAltaAsignatura.h"
#include "interface/ICtrlAltaUsuario.h"
#include "interface/ICtrlAsignacionDocAsignatura.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        static ICtrlAltaUsuario* getICtrlAltaUsuario();
        static ICtrlAltaAsignatura* getICtrlAltaAsignatura();
        static ICtrlAsignacionDocAsignatura* getICtrlAsignacionDocAsignatura();
        
        ~Fabrica();
        
};

#endif
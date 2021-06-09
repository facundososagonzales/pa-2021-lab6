#ifndef FABRICA_H
#define FABRICA_H

#include "interface/ICtrlAltaAsignatura.h"
#include "interface/ICtrlAltaUsuario.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        static ICtrlAltaUsuario* getICtrlAltaUsuario();
        static ICtrlAltaAsignatura* getICtrlAltaAsignatura();
        
        ~Fabrica();
        
};

#endif
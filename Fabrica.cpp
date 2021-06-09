#include "Fabrica.h"
#include "ctrl/CtrlAltaUsuario.h"
#include "ctrl/CtrlAltaAsignatura.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if(instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

ICtrlAltaUsuario* Fabrica::getICtrlAltaUsuario(){
    return new CtrlAltaUsuario;
}

ICtrlAltaAsignatura* Fabrica::getICtrlAltaAsignatura(){
    return new CtrlAltaAsignatura;
}

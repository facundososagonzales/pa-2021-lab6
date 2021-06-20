#include "Fabrica.h"
#include "ctrl/CtrlAltaUsuario.h"
#include "ctrl/CtrlAltaAsignatura.h"
#include "ctrl/CtrlAsignacionDocAsignatura.h"
#include "ctrl/CtrlInscripcionAsignatura.h"
#include "ctrl/CtrlInicioDeClase.h"
#include "ctrl/CtrlEliminarAsignatura.h"
#include "ctrl/CtrlAsisteEnVivo.h"
#include "ctrl/CtrlEnvioMensaje.h"

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

ICtrlAsignacionDocAsignatura* Fabrica::getICtrlAsignacionDocAsignatura(){
    return new CtrlAsignacionDocAsignatura;
}

ICtrlInscripcionAsignatura* Fabrica::getICtrlInscripcionAsignatura(){
    return new CtrlInscripcionAsignatura();
}

ICtrlInicioDeClase* Fabrica::getICtrlInicioDeClase(){
    return new CtrlInicioDeClase();
}

ICtrlEliminarAsignatura* Fabrica::getICtrlEliminarAsignatura() {
    return new CtrlEliminarAsignatura();
}

ICtrlEnvioMensaje* Fabrica::getICtrlEnvioMensaje() {
    return new CtrlEnvioMensaje();
}

/*
ICtrlAsisteEnVivo* Fabrica::getICtrlAsisteEnVivo() {
    return new CtrlAsisteEnVivo();
}*/
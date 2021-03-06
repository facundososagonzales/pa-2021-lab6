#ifndef FABRICA_H
#define FABRICA_H

#include "interface/ICtrlAltaAsignatura.h"
#include "interface/ICtrlAltaUsuario.h"
#include "interface/ICtrlAsignacionDocAsignatura.h"
#include "interface/ICtrlInscripcionAsignatura.h"
#include "interface/ICtrlInicioDeClase.h"
#include "interface/ICtrlEliminarAsignatura.h"
#include "interface/ICtrlAsisteEnVivo.h"
#include "interface/ICtrlEnvioMensaje.h"
#include "interface/ICtrlListadoDeClases.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        static ICtrlAltaUsuario* getICtrlAltaUsuario();
        static ICtrlAltaAsignatura* getICtrlAltaAsignatura();
        static ICtrlAsignacionDocAsignatura* getICtrlAsignacionDocAsignatura();
        static ICtrlInscripcionAsignatura* getICtrlInscripcionAsignatura();
        static ICtrlInicioDeClase* getICtrlInicioDeClase();
        static ICtrlEliminarAsignatura* getICtrlEliminarAsignatura();
        static ICtrlEnvioMensaje* getICtrlEnvioMensaje();
        static ICtrlAsisteEnVivo* getICtrlAsisteEnVivo();
        static ICtrlListadoDeClases* getICtrlListadoDeClases();
        
        ~Fabrica();
        
};

#endif
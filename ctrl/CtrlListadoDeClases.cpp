#include "../ctrl/CtrlListadoDeClases.h"
#include "../handler/HandlerUsuario.h"
#include "../handler/HandlerAsignatura.h"
#include "../class/Sesion.h"

list<string> CtrlListadoDeClases::asignaturasAsignadas(){
    list<string> asignaturasAsignadas;
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    
    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        asignaturasAsignadas = docente->getAsignaturasAsignadas();        
    }
    return asignaturasAsignadas;
}

list<DtInfoClase*> CtrlListadoDeClases::seleccionarAsignatura(string nombre){
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Asignatura* asignatura = hA->buscarAsignatura(nombre);
    list<DtInfoClase*> dtInfoClases = asignatura->getInfoClases();
    return dtInfoClases;
}
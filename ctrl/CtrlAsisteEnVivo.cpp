#include "CtrlAsisteEnVivo.h"
#include "../class/Sesion.h"
#include <time.h>

CtrlAsisteEnVivo::CtrlAsisteEnVivo(){}

list<string> CtrlAsisteEnVivo::asignaturasInscripto(){
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    list<string> asigInscripto;
    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Estudiante* estudianteLog = dynamic_cast<Estudiante*>(usuarioLog);

    if (estudianteLog != NULL) {
        asigInscripto = estudianteLog->devolverInscriptos();
    }
    return asigInscripto;
}

list<int> CtrlAsisteEnVivo::clasesOnlineDisponibles(string asigCod){
    this->codigo = asigCod;
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Asignatura* asignatura = hA->buscarAsignatura(this->codigo);
    list<int> clasesDispOnline = asignatura->getClasesOnline();
    return clasesDispOnline;
}

DtAsistir CtrlAsisteEnVivo::selectClase(int id){
    this->id = id;
    DtAsistir dtAsist = DtAsistir(this->id, this->codigo);
    return dtAsist;
}

void CtrlAsisteEnVivo::asistirClaseEnVivo(){
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Estudiante* estudianteLog = dynamic_cast<Estudiante*>(usuarioLog);
    
    if(estudianteLog!=NULL){
        HandlerClase* hC = HandlerClase::getInstancia();
        Clase* clase = hC->buscarClase(this->id);
        clase->agregarAsistenciaOnline(estudianteLog);
    }
}

CtrlAsisteEnVivo::~CtrlAsisteEnVivo(){}
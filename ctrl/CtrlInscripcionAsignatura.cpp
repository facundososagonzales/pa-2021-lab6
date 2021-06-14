#include "../ctrl/CtrlInscripcionAsignatura.h"
#include "../handler/HandlerAsignatura.h"
#include "../handler/HandlerUsuario.h"
#include "../class/Sesion.h"

CtrlInscripcionAsignatura::CtrlInscripcionAsignatura(){}

list<string> CtrlInscripcionAsignatura::asignaturaNoInscripto(){
    Sesion* sesion = Sesion::getInstancia();
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    list<string> codAsignaturas = hA->getCodAsignaturas();
    list<string> asigNoInscripto;

    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Estudiante* estudianteLog = dynamic_cast<Estudiante*>(usuarioLog);
    bool estaInscripto;

    if (estudianteLog!=NULL){
        list<Asignatura*> asigInscripto = estudianteLog->getAsignaturas();
        for(string cod: codAsignaturas){
            estaInscripto=false;
            for(Asignatura* a: asigInscripto){
                if(a->getCodigo()==cod){
                    estaInscripto=true;
                }
            }
            if(!estaInscripto){
                asigNoInscripto.push_back(cod);
            }
        }
    }
    return asigNoInscripto;
}

void CtrlInscripcionAsignatura::seleccionarAsignatura(string codigo){
    this->codigo=codigo;
}

void CtrlInscripcionAsignatura::darDeAltaInscripcion(){
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Asignatura* asignatura = hA->buscarAsignatura(this->codigo);

    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Estudiante* estudianteLog = dynamic_cast<Estudiante*>(usuarioLog);
    if(estudianteLog!=NULL){
        estudianteLog->addAsignatura(asignatura);
        cout << "La inscripcion ha sido creada correctamente" << endl;
    }
}
#include "CtrlEliminarAsignatura.h"
#include "../handler/HandlerAsignatura.h"
#include "../handler/HandlerUsuario.h"

CtrlEliminarAsignatura::CtrlEliminarAsignatura() {}

list<string> CtrlEliminarAsignatura::listarAsignaturas() {
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    list<Asignatura*> asignaturas = hA->getAsignaturas();
    list<string> codAsignatura;

    for (Asignatura* a : asignaturas) {
        codAsignatura.push_back(a->getCodigo());
    }

    return codAsignatura;
}

void CtrlEliminarAsignatura::seleccionarAsignatura(string codigo) {
    this->codigo = codigo;
}

void CtrlEliminarAsignatura::eliminarAsignatura() {
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Asignatura* asig = hA->buscarAsignatura(this->codigo);
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    list<Usuario*> us = hU->getUsuarios();
    for(Usuario* u : us){
        Estudiante* e = dynamic_cast<Estudiante*>(u);
        if (e != NULL) {
            e->eliminarInscripcion(asig);
        }
        else {
            Docente* d = dynamic_cast<Docente*>(u);
            if (d != NULL) {
                d->eliminarRol(asig);
            }
        }            
    }
    asig->eliminarAsignatura();
    hA->eliminarAsignatura(asig->getCodigo());
}

CtrlEliminarAsignatura::~CtrlEliminarAsignatura() {}
#include "HandlerAsignatura.h"

HandlerAsignatura* HandlerAsignatura::instancia=NULL;

HandlerAsignatura::HandlerAsignatura(){}

HandlerAsignatura* HandlerAsignatura::getInstancia(){
    if(instancia==NULL){
        instancia=new HandlerAsignatura();
    }
    return instancia;
}

list<Asignatura*> HandlerAsignatura::getAsignaturas(){
    list<Asignatura*> asignaturas = this->asignaturas;
    return asignaturas;
}

Asignatura* HandlerAsignatura::buscarAsignatura(string codigo){
    Asignatura* asigIter;
    for(list<Asignatura*>::iterator it = this->asignaturas.begin(); it!= this->asignaturas.end();++it){
        if((*it)->getCodigo()==codigo){
            asigIter = (*it);
        }
    }
    return asigIter;
}

void HandlerAsignatura::addAsignatura(Asignatura* asignatura){
    this->asignaturas.push_back(asignatura);
}

HandlerAsignatura::~HandlerAsignatura(){}
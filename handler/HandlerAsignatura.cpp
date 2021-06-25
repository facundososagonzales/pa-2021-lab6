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

list<string> HandlerAsignatura::getCodAsignaturas(){
    list<string> codAsignaturas;
    for(Asignatura* a: this->asignaturas){
        codAsignaturas.push_back(a->getCodigo());
    }
    return codAsignaturas;
}

Asignatura* HandlerAsignatura::buscarAsignatura(string codigo){
    Asignatura* asigIter=NULL;
    for(Asignatura* a: asignaturas){
        if(a->getCodigo()==codigo){
            asigIter = a;
        }
    }
    return asigIter;
}

/*bool HandlerAsignatura::existeAsig(string codigo){
    bool exis=false;
    for(Asignatura* a: asignaturas){
        if((a)->getCodigo()==codigo){
            exis==true;
        }
    }
    return exis;
}  ***** NO USAR*****/

void HandlerAsignatura::addAsignatura(Asignatura* asignatura){
    this->asignaturas.push_back(asignatura);
}

void HandlerAsignatura::eliminarAsignatura(string codigo){
    this->asignaturas.remove(this->buscarAsignatura(codigo));
}

HandlerAsignatura::~HandlerAsignatura(){}
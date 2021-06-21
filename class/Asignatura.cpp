#include "../class/Asignatura.h"

Asignatura::Asignatura(){}

Asignatura::Asignatura(string codigo, string nombre){
    this->codigo=codigo;
    this->nombre=nombre;
}

string Asignatura::getCodigo() {
    return this->codigo;
}

void Asignatura::setCodigo(string codigo) {
    this->codigo=codigo;
}

string Asignatura::getNombre() {
    return this->nombre;
}

void Asignatura::setNombre(string nombre) {
    this->nombre=nombre;
}

void Asignatura::setInstanciaClase(DtInstanciaClase* dtIC){
    this->dtIC=dtIC;
}

DtInstanciaClase* Asignatura::getInstanciaClase(){
    return this->dtIC;
}

list<Clase*> Asignatura::getClases() {
    return this->clases;
}

void Asignatura::addClase(Clase* clase) {
    this->clases.push_back (clase);
}

list<int> Asignatura::getClasesOnline(){
    list<int> idClases;
    for(Clase* c : this->clases){
        if(c->getRutaVideo()=="PENDIENTE"){
            idClases.push_back(c->getId());
        } 
    }
    return idClases;
}

Asignatura::~Asignatura() {}
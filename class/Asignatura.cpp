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

list<Clase*> Asignatura::getClases() {
    return this->clases;
}

void Asignatura::addClase(Clase* clase) {
    this->clases.push_back (clase);
}
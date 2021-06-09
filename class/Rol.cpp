#include "../class/Rol.h"

Rol::Rol(){}

Rol::Rol(TipoRol rol, Asignatura* asignatura){
    this->rol=rol;
    this->asignatura=asignatura;    
}

TipoRol Rol::getRol() {
    return this->rol;
}

void Rol::setRol(TipoRol rol) {
    this->rol=rol;
}

Asignatura* Rol::getAsignatura() {
    return this->asignatura;
}

void Rol::setAsignatura(Asignatura* asignatura) {
    this->asignatura=asignatura;
}
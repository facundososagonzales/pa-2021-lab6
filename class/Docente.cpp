#include "../class/Docente.h"

Docente::Docente(){}

Docente::Docente(string nombre, string imagenUrl, string email, string password, string instituto):Usuario(nombre,imagenUrl,email,password){
    this->instituto=instituto;
}

void Docente::setInstituto(string instituto) {
    this->instituto=instituto;
}

string Docente::getInstituto() {
    return this->instituto;
}

void Docente::addRol(Rol* rol) {
    this->roles.push_back (rol);
}

list<Rol*> Docente::getRoles() {
    return this->roles;
}

Docente::~Docente(){}
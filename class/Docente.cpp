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

void Docente::setRoles(list<Rol*> roles) {
    this->roles = roles;
}

void Docente::eliminarRol(Asignatura* asig) {
    Rol* r;
    list<Rol*>::iterator it1;

    for (list<Rol*>::iterator it = this->roles.begin(); it != this->roles.end(); ++it) {
        if ((*it)->getAsignatura()->getCodigo() == asig->getCodigo()) {
            r = *it;
        }
    }
    this->roles.remove(r);
    //delete(r);
    //this->roles.erase(it1);
}

list<string> Docente::getAsignaturasAsignadas(){
    list<string> asignaturasAsignadas;
    if(!this->getRoles().empty()){
        for(Rol* r: this->getRoles()){
            asignaturasAsignadas.push_back(r->getAsignatura()->getCodigo());
        }
    }
    return asignaturasAsignadas;
}

Docente::~Docente(){}
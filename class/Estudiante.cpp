#include "../class/Estudiante.h"

Estudiante::Estudiante(){}

Estudiante::Estudiante(string nombre, string imagenUrl, string email, string password, string documento):Usuario(nombre,imagenUrl,email,password){
    this->documento=documento;
}

void Estudiante::setDocumento(string documento) {
    this->documento=documento;
}

string Estudiante::getDocumento() {
    return this->documento;
}

void Estudiante::addAsignatura(Asignatura* asignatura) {
    this->asignaturas.push_back (asignatura);
}

list<Asignatura*> Estudiante::getAsignaturas() {
    return this->asignaturas;
}

void Estudiante::setAsignaturas(list<Asignatura*> asig) {
    this->asignaturas = asig;
}

void Estudiante::eliminarInscripcion(Asignatura* asig) {
    Asignatura* a;
    for (list<Asignatura*>::iterator it = this->asignaturas.begin(); it != this->asignaturas.end(); ++it) {
        if ((*it)->getCodigo() == asig->getCodigo()) {
            a = *it;
        }
    }
    this->asignaturas.remove(a);
}

Estudiante::~Estudiante(){}
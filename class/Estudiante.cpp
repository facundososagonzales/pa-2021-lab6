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

Estudiante::~Estudiante(){}
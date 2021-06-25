#include "../class/Monitoreo.h"

cm::Monitoreo::Monitoreo(){}

cm::Monitoreo::Monitoreo(int id, string nombre, DtHora inicio, list<Docente*> docente, list<Estudiante*> estudiantes)
:Clase(id, nombre, inicio, docente){
    this->estudiantes=estudiantes;
}


void cm::Monitoreo::addEstudiante(Estudiante* estudiante) {
    if(this->estudiantes.size()<16){
        this->estudiantes.push_back(estudiante);
    }
}

list <Estudiante*> cm::Monitoreo::getEstudiantes() {
    return this->estudiantes;
}

list <string> cm::Monitoreo::getEmailEstudiantes() {
    list<string> emailEst;
    for(Estudiante* e : this->estudiantes){
        emailEst.push_back(e->getemail());
    }
    return emailEst;
}

cm::Monitoreo::~Monitoreo(){}
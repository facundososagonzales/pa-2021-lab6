#include "../class/Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(int id, string nombre, DtHora inicio, DtHora fin, string rutaVideo, list<Docente*> docente, list<Estudiante*> estudiantes)
:Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->estudiantes=estudiantes;
}


void Monitoreo::addEstudiante(Estudiante* estudiante) {
    if(this->estudiantes.size()<16){
        this->estudiantes.push_back(estudiante);
    }
}

list <Estudiante*> Monitoreo::getEstudiantes() {
    return this->estudiantes;
}

Monitoreo::~Monitoreo(){}
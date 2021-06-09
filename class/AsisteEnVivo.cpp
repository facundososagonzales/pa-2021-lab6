#include "../class/AsisteEnVivo.h"

AsisteEnVivo::AsisteEnVivo(){}

AsisteEnVivo::AsisteEnVivo(DtHora inicio, DtHora fin, Estudiante* estudiante){
    this->inicio=inicio;
    this->fin=fin;
    this->estudiante=estudiante;    
}

DtHora AsisteEnVivo::getInicio() {
    return this->inicio;
}

void AsisteEnVivo::setInicio(DtHora inicio) {
    this->inicio=inicio;
}

DtHora AsisteEnVivo::getFin() {
    return this->fin;
}

void AsisteEnVivo::setFin(DtHora fin) {
    this->fin=fin;
}

Estudiante* AsisteEnVivo::getEstudiante() {
    return this->estudiante;
}

void AsisteEnVivo::setEstudiante(Estudiante* estudiante) {
    this->estudiante=estudiante;
}

AsisteEnVivo::~AsisteEnVivo(){}
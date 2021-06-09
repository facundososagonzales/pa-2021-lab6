#include "../class/AsisteDiferido.h"

AsisteDiferido::AsisteDiferido(){}

AsisteDiferido::AsisteDiferido(Estudiante* estudiante){
    this->estudiante=estudiante;    
}

list<Log> AsisteDiferido::getLogs() {
    return this->logs;
}

void AsisteDiferido::addLog(Log log) {
    this->logs.push_back(log);
}

Estudiante* AsisteDiferido::getEstudiante() {
    return this->estudiante;
}

void AsisteDiferido::setEstudiante(Estudiante* estudiante) {
    this->estudiante=estudiante;
}

AsisteDiferido::~AsisteDiferido(){}
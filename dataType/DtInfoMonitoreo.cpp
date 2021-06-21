#include "DtInfoMonitoreo.h"

DtInfoMonitoreo::DtInfoMonitoreo(){}

DtInfoMonitoreo::DtInfoMonitoreo(int id, string nombre, list<string> docentes, list<string> estudiantes)
:DtInfoClase(id,nombre,docentes){
    this->estudiantes=estudiantes;
}

list<string> DtInfoMonitoreo::getEstudiantes(){
    return this->estudiantes;
}

DtInfoMonitoreo::~DtInfoMonitoreo(){}
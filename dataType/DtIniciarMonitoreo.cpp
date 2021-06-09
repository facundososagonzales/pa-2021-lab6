#include "DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}
DtIniciarMonitoreo::DtIniciarMonitoreo(string codigo, string nombre, DtHora fechaHora, int id, list<string> habilitados)
:DtIniciarClaseFull(codigo,nombre,fechaHora,id){
    this->habilitados=habilitados;
}

list<string> DtIniciarMonitoreo::getHabilitados(){
    return habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}
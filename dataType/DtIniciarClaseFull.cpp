#include "DtIniciarClaseFull.h"

DtIniciarClaseFull::DtIniciarClaseFull(){}
DtIniciarClaseFull::DtIniciarClaseFull(string codigo, string nombre, DtHora fechaHora, int id)
:DtIniciarClase(codigo,nombre,fechaHora){
    this->id=id;
}


int DtIniciarClaseFull::getId(){
    return id;
}

DtIniciarClaseFull::~DtIniciarClaseFull(){}
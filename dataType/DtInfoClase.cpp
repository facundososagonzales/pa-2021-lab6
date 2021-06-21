#include "DtInfoClase.h"

DtInfoClase::DtInfoClase(){}

DtInfoClase::DtInfoClase(int id, string nombre, list<string> docentes){
    this->id=id;
	this->nombre=nombre;
    this->docentes=docentes;
}

int DtInfoClase::getId(){
    return id;
}
string DtInfoClase::getNombre(){
    return nombre;
}
list<string> DtInfoClase::getDocentes(){
    return docentes;
}

DtInfoClase::~DtInfoClase(){}
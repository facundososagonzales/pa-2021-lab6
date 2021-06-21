#include "DtInfoTeorico.h"

DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, string nombre, list<string> docentes, int cantAsisten)
:DtInfoClase(id,nombre,docentes){
    this->cantAsisten=cantAsisten;
}

int DtInfoTeorico::getCantAsisten(){
    return this->cantAsisten;
}

DtInfoTeorico::~DtInfoTeorico(){}
#include "DtInstanciaClase.h"

DtInstanciaClase::DtInstanciaClase(){}
DtInstanciaClase::DtInstanciaClase(bool teorico,bool monitoreo,bool practico){
    this->teorico=teorico;
	this->monitoreo=monitoreo;	
	this->practico=practico;
}


bool DtInstanciaClase::getTeorico(){
    return teorico;
}
bool DtInstanciaClase::getMonitoreo(){
    return monitoreo;
}
bool DtInstanciaClase::getPractico(){
    return practico;
}

DtInstanciaClase::~DtInstanciaClase(){}
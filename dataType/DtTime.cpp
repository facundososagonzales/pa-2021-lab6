#include "DtTime.h"

DtTime::DtTime(){}
DtTime::DtTime(int hora, int minuto, int segundo){
    this->hora=hora;
	this->minuto=minuto;	
	this->segundo=segundo;
}

int DtTime::getHora(){
    return hora;
}
int DtTime::getMinuto(){
    return minuto;
}
int DtTime::getSegundo(){
    return segundo;
}
DtTime::~DtTime(){}
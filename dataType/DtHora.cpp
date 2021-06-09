#include "DtHora.h"

DtHora::DtHora(){}
DtHora::DtHora(DtFecha fecha, int hora, int minuto, int segundo){
	this->fecha=fecha;
    this->hora=hora;
	this->minuto=minuto;	
	this->segundo=segundo;
}

DtFecha DtHora::getFecha(){
    return fecha;
}
int DtHora::getHora(){
    return hora;
}
int DtHora::getMinuto(){
    return minuto;
}
int DtHora::getSegundo(){
    return segundo;
}
DtHora::~DtHora(){}
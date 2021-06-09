#include "DtDictadoAsignatura.h"

DtDictadoAsignatura::DtDictadoAsignatura(){}
DtDictadoAsignatura::DtDictadoAsignatura(string codigo, string nombre, DtTime tiempoTotal){
    this->codigo=codigo;
	this->nombre=nombre;	
	this->tiempoTotal=tiempoTotal;
}

string DtDictadoAsignatura::getCodigo(){
    return codigo;
}
string DtDictadoAsignatura::getNombre(){
    return nombre;
}
DtTime DtDictadoAsignatura::getTiempoTotal(){
    return tiempoTotal;
}
DtDictadoAsignatura::~DtDictadoAsignatura(){}
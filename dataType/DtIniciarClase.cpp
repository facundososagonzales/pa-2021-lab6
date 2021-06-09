#include "DtIniciarClase.h"

DtIniciarClase::DtIniciarClase(){}
DtIniciarClase::DtIniciarClase(string codigo, string nombre, DtHora fechaHora){
    this->codigo=codigo;
	this->nombre=nombre;	
	this->fechaHora=fechaHora;
}


string DtIniciarClase::getCodigo(){
    return codigo;
}
string DtIniciarClase::getNombre(){
    return nombre;
}
DtHora DtIniciarClase::getFechaHora(){
    return fechaHora;
}

DtIniciarClase::~DtIniciarClase(){}
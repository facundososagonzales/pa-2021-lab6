#include "DtAsignatura.h"

DtAsignatura::DtAsignatura(){}
DtAsignatura::DtAsignatura(string nombre,string codigo,DtInstanciaClase* instanciaClase){
    this->nombre=nombre;
	this->codigo=codigo;	
	this->instanciaClase=instanciaClase;
}


string DtAsignatura::getNombre(){
    return nombre;
}
string DtAsignatura::getCodigo(){
    return codigo;
}
DtInstanciaClase* DtAsignatura::getInstanciaClase(){
    return instanciaClase;
}

DtAsignatura::~DtAsignatura(){}
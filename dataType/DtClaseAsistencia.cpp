#include "DtClaseAsistencia.h"

DtClaseAsistencia::DtClaseAsistencia(){}
DtClaseAsistencia::DtClaseAsistencia(int id, string nombre, DtTime promAsistencia){
    this->id=id;
	this->nombre=nombre;	
	this->promAsistencia=promAsistencia;
}

int DtClaseAsistencia::getId(){
    return id;
}
string DtClaseAsistencia::getNombre(){
    return nombre;
}
DtTime DtClaseAsistencia::getPromAsistencia(){
    return promAsistencia;
}
DtClaseAsistencia::~DtClaseAsistencia(){}
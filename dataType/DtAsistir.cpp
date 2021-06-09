#include "DtAsistir.h"

DtAsistir::DtAsistir(){}
DtAsistir::DtAsistir(int id,string codigo){
	this->id=id;
    this->codigo=codigo;
}

int DtAsistir::getId(){
    return id;
}
string DtAsistir::getCodigo(){
    return codigo;
}
DtAsistir::~DtAsistir(){}
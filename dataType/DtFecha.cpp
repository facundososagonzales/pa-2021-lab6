#include "DtFecha.h"

DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia, int mes, int anio){
	this->dia=dia;
	this->mes=mes;	
	this->anio=anio;
}
int DtFecha::getDia(){
    return dia;
}
int DtFecha::getMes(){
    return mes;
}
int DtFecha::getAnio(){
    return anio;
}
DtFecha::~DtFecha(){}

bool operator <(const DtFecha& dtf1,const DtFecha& dtf2){
	bool retorno;
	if (dtf1.anio < dtf2.anio){
		retorno=true;
	}else if(dtf1.anio == dtf2.anio){
		if (dtf1.mes < dtf2.mes){
			retorno=true;
		}else if(dtf1.mes == dtf2.mes){
			if (dtf1.dia < dtf2.dia){
				retorno=true;
			}else{
				retorno=false;
			}
		}
	}
	return retorno;
}
bool operator ==(const DtFecha& f1,const DtFecha& f2){
	if (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia == f2.dia) return true;
	else return false;
}

ostream& operator <<(ostream& salida,const DtFecha& dtf){
	cout << dtf.dia << "/" << dtf.mes << "/" << dtf.anio;
	return salida;
}

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

ostream& operator <<(ostream& salida, const DtAsignatura& dta){
	cout << "nombre: " << dta.nombre << "\n" 
		"codigo: " << dta.codigo << endl;
        if(dta.instanciaClase->getTeorico()){
            cout << "Tiene Teorico?: Si" << endl;
        }else{
           cout << "Tiene Teorico?: No" << endl;
        }
        if(dta.instanciaClase->getMonitoreo()){
            cout << "Tiene Monitoreo?: Si" << endl;
        }else{
            cout << "Tiene Monitoreo?: No" << endl;
        }
        if(dta.instanciaClase->getPractico()){
            cout << "Tiene Practico?: Si" << endl;
        }else{
           cout << "Tiene Practico?: No" << endl;
        }
	return salida;
}

DtAsignatura::~DtAsignatura(){}
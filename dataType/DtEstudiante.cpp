#include "../dataType/DtEstudiante.h"

DtEstudiante::DtEstudiante(){}

DtEstudiante::DtEstudiante(string nombre, string url, string email, string password, string ci): DtUsuario(nombre,url,email,password){
    this->ci=ci;
}

string DtEstudiante::getci() {
    return this->ci;
}

DtEstudiante::~DtEstudiante(){}

ostream& operator <<(ostream& salida, const DtEstudiante& dte){
	cout <<(DtUsuario) dte << "CI: " << dte.ci << endl;
	return salida;
}

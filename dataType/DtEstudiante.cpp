#include "../dataType/DtEstudiante.h"

DtEsudiante::DtEsudiante(){}

DtEsudiante::DtEsudiante(string nombre, string url, string email, string password, string ci): DtUsuario(nombre,url,email,password){
    this->ci=ci;
}

string DtEsudiante::getci() {
    return this->ci;
}

DtEsudiante::~DtEsudiante(){}

ostream& operator <<(ostream& salida, const DtEsudiante& dte){
	cout <<(DtUsuario) dte << "CI: " << dte.ci << endl;
	return salida;
}

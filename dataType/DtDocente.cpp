#include "../dataType/DtDocente.h"

DtDocente::DtDocente(){}

DtDocente::DtDocente(string nombre, string url, string email, string password, string instituto): DtUsuario(nombre,url,email,password){
    this->instituto=instituto;
}

string DtDocente::getInstituto() {
    return this->instituto;
}

DtDocente::~DtDocente(){}

ostream& operator <<(ostream& salida, const DtDocente& dtb){
	cout <<(DtUsuario) dtb << "Instituto: " << dtb.instituto << endl;
	return salida;
}

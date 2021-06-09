#include "../dataType/DtUsuario.h"

DtUsuario::DtUsuario(){}

DtUsuario::DtUsuario(string nombre,string url, string email, string pass){
    this->nombre=nombre;
    this->url=url;
    this->email=email;
    this->pass=pass;
}

string DtUsuario::getnombre() {
    return this->nombre;
}

string DtUsuario::geturl() {
    return this->url;
}

string DtUsuario::getemail() {
    return this->email;
}

string DtUsuario::getpass() {
    return this->pass;
}

DtUsuario::~DtUsuario(){}

ostream& operator <<(ostream& salida, const DtUsuario& dtu){
	cout << "id: " << dtu.nombre << "\n" 
		"email: " << dtu.email << endl <<
		"url: " << dtu.url << endl <<
        "password: " << dtu.pass << endl;
	return salida;
}

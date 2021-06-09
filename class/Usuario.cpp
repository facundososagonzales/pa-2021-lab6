#include "../class/Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string nombre, string imagenUrl, string email, string password){
    this->nombre=nombre;
    this->imagenUrl=imagenUrl;
    this->email=email;
    this->password=password;
}

string Usuario::getnombre() {
    return this->nombre;
}

void Usuario::setnombre(string nombre) {
    this->nombre=nombre;
}

string Usuario::getimagenUrl() {
    return this->imagenUrl;
}

void Usuario::setimagenUrl(string id) {
    this->imagenUrl=imagenUrl;
}

string Usuario::getemail() {
    return this->email;
}

void Usuario::setemail(string email) {
    this->email=email;
}

string Usuario::getpassword() {
    return this->password;
}

void Usuario::setpassword(string password) {
    this->password=password;
}

Usuario::~Usuario(){}

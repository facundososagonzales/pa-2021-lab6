#include "Sesion.h"
#include <list>

using namespace std;

Sesion* Sesion::instancia = NULL;

bool Sesion::iniciada = false;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
    if (instancia == NULL) 
        instancia = new Sesion();
    return instancia;
}

void Sesion::setLogin(){
    iniciada = true;
}

void Sesion::setLogout(){
    iniciada = false;
}

bool Sesion::checkIniciada(){
    return iniciada;
}

void Sesion::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}

void Sesion::setTipo(SesionType::TipoSesion tipo){
    this->tipo = tipo;
}

string Sesion::getUsuario(){
    return this->usuario->getemail();
}

string Sesion::getNombre(){
    return this->usuario->getnombre();
}

SesionType::TipoSesion Sesion::getTipo(){
    return this->tipo;
}

Sesion::~Sesion(){}
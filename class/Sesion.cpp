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

void Sesion::setLogin(TipoSesion tipoSesion){
    tipoSesion=tipoSesion;
    iniciada = true;
}

void Sesion::setLogout(){
    iniciada = false;
}

bool Sesion::checkIniciada(){
    return iniciada;
}

Sesion::~Sesion(){}
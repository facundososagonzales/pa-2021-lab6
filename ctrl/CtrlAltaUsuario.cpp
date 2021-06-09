#include "CtrlAltaUsuario.h"
#include "../class/Sesion.h"
#include "../class/Docente.h"
#include "../class/Estudiante.h"
#include "../handler/HandlerUsuario.h"

CtrlAltaUsuario::CtrlAltaUsuario(){}

void CtrlAltaUsuario::ingresarDatosPerfil(DtUsuario datosUsuario){
    this->usuario = datosUsuario;
}

void CtrlAltaUsuario::ingresarEstudiante(string doc){
    this->doc = doc;
}

void CtrlAltaUsuario::ingresarDocente(string instituto){
    this->instituto = instituto;
}

void CtrlAltaUsuario::altaUsuario(){}

void CtrlAltaUsuario::iniciarSesion(){
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Usuario* usuario = hU->buscarUsuario(this->usuario.getemail());
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->checkIniciada()==false){
        Docente* docente = dynamic_cast<Docente*>(usuario);
        if(docente!=NULL){
            Estudiante* estudiante = new Estudiante(
                this->usuario.getnombre(), 
                this->usuario.geturl(), 
                this->usuario.getemail(), 
                this->usuario.getpass(), 
                this->doc);
            sesion->setLogin();
            sesion->setUsuario(estudiante);
        }else if(docente==NULL){
            Docente* docente = new Docente(
                this->usuario.getnombre(), 
                this->usuario.geturl(), 
                this->usuario.getemail(), 
                this->usuario.getpass(), 
                this->instituto);
            sesion->setLogin();
            sesion->setUsuario(docente);
        }
    }
}

void CtrlAltaUsuario::cerrarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->checkIniciada()==true){
        sesion->setLogout();
    }
}

bool CtrlAltaUsuario::isLogged(){
    Sesion* sesion = Sesion::getInstancia();
    return sesion->checkIniciada();
}

CtrlAltaUsuario::~CtrlAltaUsuario(){}
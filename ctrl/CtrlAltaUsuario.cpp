#include "CtrlAltaUsuario.h"
#include "../dataType/DtDocente.h"
#include "../dataType/DtEstudiante.h"
#include "../class/Sesion.h"
#include "../class/Docente.h"
#include "../class/Estudiante.h"
#include "../handler/HandlerUsuario.h"

CtrlAltaUsuario::CtrlAltaUsuario(){}

void CtrlAltaUsuario::ingresarDatosPerfil(DtUsuario& datosUsuario){
    this->usuario = datosUsuario;
}

void CtrlAltaUsuario::ingresarEstudiante(string doc){
    this->doc = doc;
}

void CtrlAltaUsuario::ingresarDocente(string instituto){
    this->instituto = instituto;
}

void CtrlAltaUsuario::ingresarEmail(string email){
    this->email = email;
}

void CtrlAltaUsuario::ingresarPassword(string password){
    this->password = password;
}

void CtrlAltaUsuario::altaUsuario(DtUsuario& usuario){    
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    if(hU->existeUsuario(this->usuario.getemail())){
        cout << "El email ingresado ya existe" << endl; 
    }else{
        try{
            cout << "1-";
            DtDocente& dtDoc = dynamic_cast<DtDocente&>(usuario);
            Docente* docente = new Docente(dtDoc.getnombre(),dtDoc.geturl(),dtDoc.getemail(),dtDoc.getpass(),dtDoc.getInstituto());
            hU->addUsuario(docente);
             cout << "2-";
        }catch(bad_cast){
            try{                
                 cout << "3-";
                DtEstudiante& dtEst = dynamic_cast<DtEstudiante&>(usuario);
                if(hU->existeEstudiante(this->doc)){
                    cout << "El documento ingresado ya existe" << endl;
                }else{
                    cout << "4-";
                    Estudiante* estudiante = new Estudiante(dtEst.getnombre(),dtEst.geturl(),dtEst.getemail(),dtEst.getpass(),dtEst.getci());
                    hU->addUsuario(estudiante);
                }
            }catch(bad_cast){}
        } 
    } 
}

void CtrlAltaUsuario::iniciarSesion(){
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Usuario* usuario = hU->buscarUsuario(this->email);
    if(usuario->getpassword()==this->password){
        Sesion* sesion = Sesion::getInstancia();
        if(sesion->checkIniciada()==false){
            Docente* docente = dynamic_cast<Docente*>(usuario);
            if(docente==NULL){
                Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
                sesion->setLogin();
                sesion->setUsuario(estudiante);
            }else if(docente!=NULL){
                sesion->setLogin();
                sesion->setUsuario(docente);
            }
        cout << "Bienvenido usuario " + usuario->getnombre() << endl;
        }
    }else{
        cout << "Email o password incorrectos" << endl;
    }
}

void CtrlAltaUsuario::cerrarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->checkIniciada()==true){
        sesion->setLogout();
        cout << "La sesion se esta cerrando ..." << endl;
    }
}

bool CtrlAltaUsuario::isLogged(){
    Sesion* sesion = Sesion::getInstancia();
    return sesion->checkIniciada();
}

CtrlAltaUsuario::~CtrlAltaUsuario(){}
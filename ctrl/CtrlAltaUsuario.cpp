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
            DtDocente& dtDoc = dynamic_cast<DtDocente&>(usuario);
            Docente* docente = new Docente(dtDoc.getnombre(),dtDoc.geturl(),dtDoc.getemail(),dtDoc.getpass(),dtDoc.getInstituto());
            hU->addUsuario(docente);
        }catch(bad_cast){
            try{
                DtEstudiante& dtEst = dynamic_cast<DtEstudiante&>(usuario);
                if(hU->existeEstudiante(this->doc)){
                    cout << "El documento ingresado ya existe" << endl;
                }else{
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
    if(usuario!=NULL){
        if(usuario->getpassword()==this->password){
            Sesion* sesion = Sesion::getInstancia();
            if(sesion->checkIniciada()==false){
                Docente* docente = dynamic_cast<Docente*>(usuario);
                if(docente==NULL){
                    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
                    sesion->setLogin();
                    sesion->setUsuario(estudiante);
                    cout << "Bienvenido estudiante " + usuario->getnombre() << endl;
                }else if(docente!=NULL){
                    sesion->setLogin();
                    sesion->setUsuario(docente);
                    cout << "Bienvenido docente " + usuario->getnombre() << endl;
                }
            }
        }else{
            cout << "Los datos ingresados no coinciden con ningun usuario registrado" << endl;
        }
    }else{
        cout << "Los datos ingresados no coinciden con ningun usuario registrado" << endl;
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

bool CtrlAltaUsuario::isDocente(){
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Docente* doc = dynamic_cast<Docente*>(hU->buscarUsuario(sesion->getUsuario()));
    if(doc==NULL)
        return false;
    else
        return true;
}

void CtrlAltaUsuario::cargarUsuarios(){

    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Docente* doc1 = new Docente("admin","imgur.com/g2f13a49.png","admin@fing.edu", "admin", "fing");
    Docente* doc2 = new Docente("doc1","imgur.com/g2f13a49.png","doc1@fing.edu", "doc1", "fing");
    Docente* doc3 = new Docente("doc2","imgur.com/g2f13a49.png","doc2@gmail.com", "doc2", "fing");
    Docente* doc4 = new Docente("doc3","imgur.com/g2f13a49.png","doc3@hotmail.com", "doc3", "fing");
    Docente* test = new Docente("test","imgur.com/g2f13a49.png","test", "test", "fing");
    
    hU->addUsuario(doc1); hU->addUsuario(doc2); hU->addUsuario(doc3); hU->addUsuario(doc4); hU->addUsuario(test);

    Estudiante* est = new Estudiante("est","imgur.com/g2f13a49.png","est", "est", "1");
    Estudiante* est1 = new Estudiante("est1","imgur.com/g2f13a49.png","est1@gmail.com", "est1", "2");
    Estudiante* est2 = new Estudiante("est2","imgur.com/g2f13a49.png","est2@fing.edu", "est2pass", "3");
    Estudiante* est3 = new Estudiante("est3","imgur.com/g2f13a49.png","est3@gmail.com", "est3", "4");

    hU->addUsuario(est); hU->addUsuario(est1); hU->addUsuario(est2); hU->addUsuario(est3);
}

CtrlAltaUsuario::~CtrlAltaUsuario(){}
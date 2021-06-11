#include "HandlerUsuario.h"

HandlerUsuario* HandlerUsuario::instancia=NULL;

HandlerUsuario::HandlerUsuario(){}

HandlerUsuario* HandlerUsuario::getInstancia(){
    if(instancia==NULL){
        instancia=new HandlerUsuario();
    }
    return instancia;
}

list<Usuario*> HandlerUsuario::getUsuarios(){
    list<Usuario*> usuarios = this->usuarios;
    return usuarios;
}

Usuario* HandlerUsuario::buscarUsuario(string email){
    Usuario* userIter;
    for(list<Usuario*>::iterator it = this->usuarios.begin(); it!= this->usuarios.end();++it){
        if((*it)->getemail()==email){
            userIter = (*it);
        }
    }
    return userIter;
}

void HandlerUsuario::addUsuario(Usuario* usuario){
    this->usuarios.push_back(usuario);
}

bool HandlerUsuario::existeUsuario(string email){
    bool existeMail = false;
    for(list<Usuario*>::iterator it = this->usuarios.begin(); it!= this->usuarios.end();++it){
        if((*it)->getemail()==email){
            existeMail = true;
        }
    }
    return existeMail;
}

bool HandlerUsuario::existeEstudiante(string doc){
    bool existeDoc = false;
    for(list<Usuario*>::iterator it = this->usuarios.begin(); it!= this->usuarios.end();++it){
        Estudiante* estudiante = dynamic_cast<Estudiante*>((*it));
        if (estudiante!=NULL){
            if(estudiante->getDocumento()==doc){
                existeDoc = true;
            }
        }        
    }
    return existeDoc;
}

HandlerUsuario::~HandlerUsuario(){}
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

HandlerUsuario::~HandlerUsuario(){}
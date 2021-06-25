#include "HandlerClase.h"

HandlerClase* HandlerClase::instancia=NULL;

HandlerClase::HandlerClase(){}

HandlerClase* HandlerClase::getInstancia(){
    if(instancia==NULL){
        instancia=new HandlerClase();
    }
    return instancia;
}

list<Clase*> HandlerClase::getClases(){
    list<Clase*> clases = this->clases;
    return clases;
}

Clase* HandlerClase::buscarClase(int id){
    Clase* claseIter;
    for(list<Clase*>::iterator it = this->clases.begin(); it!= this->clases.end();++it){
        if((*it)->getId()==id){
            claseIter = (*it);
        }
    }
    return claseIter;
}

bool HandlerClase::existeClase(int id){
    bool existeId = false;
    for(list<Clase*>::iterator it = this->clases.begin(); it!= this->clases.end();++it){
        if((*it)->getId()==id){
            existeId = true;
        }
    }
    return existeId;
}


void HandlerClase::addClase(Clase* clase){
    this->clases.push_back(clase);
}

void HandlerClase::eliminarClase(int id){
    this->clases.remove(this->buscarClase(id));
}

HandlerClase::~HandlerClase(){}
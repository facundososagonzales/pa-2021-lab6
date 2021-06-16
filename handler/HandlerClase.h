#ifndef HANDLERCLASE_H
#define HANDLERCLASE_H

#include <iostream>
#include <list>
#include "../class/Clase.h"
using namespace std;

class HandlerClase{
private:
    static HandlerClase* instancia;
    list<Clase*> clases;
    HandlerClase(); 
public:
    static HandlerClase* getInstancia();
    list<Clase*> getClases();
    Clase* buscarClase(int);
    void addClase(Clase*);
    bool existeClase(int);
    virtual ~HandlerClase();
};

#endif
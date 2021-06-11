#ifndef HANDLERASIGNTURA_H
#define HANDLERASIGNTURA_H

#include <iostream>
#include <list>
#include <string.h>
#include "../class/Asignatura.h"
using namespace std;

class HandlerAsignatura{
private:
    static HandlerAsignatura* instancia;
    list<Asignatura*> asignaturas;
    HandlerAsignatura(); 
public:
    static HandlerAsignatura* getInstancia();
    list<Asignatura*> getAsignaturas();
    Asignatura* buscarAsignatura(string);
    bool existeAsig(string);
    void addAsignatura(Asignatura*);
    virtual ~HandlerAsignatura();
};

#endif
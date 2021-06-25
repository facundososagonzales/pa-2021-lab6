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
    list<string> getCodAsignaturas();
    Asignatura* buscarAsignatura(string);
    bool existeAsig(string);
    void addAsignatura(Asignatura*);
    void eliminarAsignatura(string);
    virtual ~HandlerAsignatura();
};

#endif
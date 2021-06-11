#ifndef HANDLERUSUARIO_H
#define HANDLERUSUARIO_H

#include <iostream>
#include <list>
#include "../class/Usuario.h"
#include "../class/Estudiante.h"

using namespace std;

class HandlerUsuario{
private:
    static HandlerUsuario* instancia;
    list<Usuario*> usuarios;
    HandlerUsuario(); 
public:
    static HandlerUsuario* getInstancia();
    list<Usuario*> getUsuarios();
    Usuario* buscarUsuario(string);
    void addUsuario(Usuario*);
    bool existeUsuario(string);
    bool existeEstudiante(string);
    virtual ~HandlerUsuario();
};

#endif
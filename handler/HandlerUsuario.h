#ifndef HANDLERUSUARIO_H
#define HANDLERUSUARIO_H

#include <iostream>
#include <list>
#include "../class/Usuario.h"
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
    virtual ~HandlerUsuario();
};

#endif
#ifndef CTRLALTAUSUARIO_H
#define CTRLALTAUSUARIO_H

#include<iostream>
#include "../interface/ICtrlAltaUsuario.h"
using namespace std;

class CtrlAltaUsuario: public ICtrlAltaUsuario{
private:
    DtUsuario usuario;
    string email;
    string password;
    string doc;
    string instituto;
public:   
    CtrlAltaUsuario();
    void ingresarDatosPerfil(DtUsuario& datosUsuario);
    void ingresarEstudiante(string doc);
    void ingresarDocente(string instituto);
    void ingresarEmail(string);
    void ingresarPassword(string);
    void altaUsuario(DtUsuario& usuario);
    void iniciarSesion();
    void cerrarSesion();
    bool isLogged();    
    ~CtrlAltaUsuario();
};

#endif
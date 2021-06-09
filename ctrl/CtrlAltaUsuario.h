#ifndef CTRLALTAUSUARIO_H
#define CTRLALTAUSUARIO_H

#include<iostream>
#include "../interface/ICtrlAltaUsuario.h"
using namespace std;

class CtrlAltaUsuario: public ICtrlAltaUsuario{
private:
    DtUsuario usuario;
    string doc;
    string instituto;
public:   
    CtrlAltaUsuario();
    void ingresarDatosPerfil(DtUsuario datosUsuario);
    void ingresarEstudiante(string doc);
    void ingresarDocente(string instituto);
    void altaUsuario();
    void iniciarSesion();
    void cerrarSesion();
    bool isLogged();
    ~CtrlAltaUsuario();
};

#endif
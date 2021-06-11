#ifndef ICTRLALTAUSUARIO_H
#define ICTRLALTAUSUARIO_H

#include <iostream>
#include "../dataType/DtUsuario.h"

using namespace std;

class ICtrlAltaUsuario{
public:    
    virtual void ingresarDatosPerfil(DtUsuario& datosUsuario)=0;
    virtual void ingresarEstudiante(string doc)=0;
    virtual void ingresarDocente(string instituto)=0;
    virtual void ingresarEmail(string email)=0;
    virtual void ingresarPassword(string password)=0;
    virtual void altaUsuario(DtUsuario& usuario)=0;
    virtual void iniciarSesion()=0;
    virtual void cerrarSesion()=0;
    virtual bool isLogged()=0;
};


#endif
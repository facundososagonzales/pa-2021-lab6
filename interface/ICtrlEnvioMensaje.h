#ifndef ICTRLENVIOMENSAJE_H
#define ICTRLENVIOMENSAJE_H

#include <iostream>
#include <list>
#include "../dataType/DtParticipacion.h"

using namespace std;

class ICtrlEnvioMensaje{
public:  
    virtual list<int> claseOnlineAsistiendo()=0;
    virtual list<DtParticipacion*> seleccionarClase(int)=0;
    virtual void responder(int)=0;
    virtual void ingresarTexto(string)=0;
    virtual void enviarMensaje()=0;
};


#endif
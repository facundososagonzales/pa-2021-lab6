#ifndef CTRLENVIOMENSAJE_H
#define CTRLENVIOMENSAJE_H

#include <iostream>
#include <list>
#include "../interface/ICtrlEnvioMensaje.h"
#include "../class/Clase.h"

using namespace std;

class CtrlEnvioMensaje: public ICtrlEnvioMensaje{
private:
    int id;
    int idp;
    string texto;
public:
    CtrlEnvioMensaje();
    list<int> claseOnlineAsistiendo();
    list<DtParticipacion*> seleccionarClase(int);
    void responder(int);
    void ingresarTexto(string);
    void enviarMensaje();
    ~CtrlEnvioMensaje();
};

#endif
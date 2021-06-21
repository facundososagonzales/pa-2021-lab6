#ifndef CTRLASISTEENVIVO_H
#define CTRLASISTEENVIVO_H

#include<iostream>
#include "../handler/HandlerUsuario.h"
#include "../handler/HandlerClase.h"
#include "../handler/HandlerAsignatura.h"
#include "../interface/ICtrlAsisteEnVivo.h"

using namespace std;

class CtrlAsisteEnVivo : public ICtrlAsisteEnVivo {
private:
    string codigo;
    int id;
public:
    CtrlAsisteEnVivo();
    list<string> asignaturasInscripto();
    list<int> clasesOnlineDisponibles(string);
    DtAsistir selectClase(int);
    void asistirClaseEnVivo();
    ~CtrlAsisteEnVivo();
};

#endif
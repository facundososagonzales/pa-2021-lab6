#ifndef ICTRLASISTEENVIVO_H
#define ICTRLASISTEENVIVO_H

#include <iostream>
#include <list>
#include "../dataType/DtAsistir.h"

using namespace std;

class ICtrlAsisteEnVivo {
public:
    virtual list<string> asignaturasInscripto() = 0;
    virtual list<int> clasesOnlineDisponibles(string) = 0;
    virtual DtAsistir selectClase(int) = 0;
    virtual void asistirClaseEnVivo() = 0;
};

#endif
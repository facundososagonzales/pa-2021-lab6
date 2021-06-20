#ifndef DTPARTICIPACION_H
#define DTPARTICIPACION_H

#include <iostream>
#include "../dataType/DtHora.h"

using namespace std;

class DtParticipacion{
    private:
        int id;
        DtHora fecha;
        string mensaje;
        DtParticipacion* responde;
    public:
        DtParticipacion();
        DtParticipacion(int,DtHora,string,DtParticipacion*);
        int getId();
        DtHora getFecha();
        string getMensaje();
        DtParticipacion* getResponde();
        void imprimirParticipacion();
        void imprimirParticipacion(DtParticipacion*,int);
        ~DtParticipacion();
};

#endif
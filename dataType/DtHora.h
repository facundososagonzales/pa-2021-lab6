#ifndef DTHORA_H
#define DTHORA_H

#include <iostream>
#include "../dataType/DtFecha.h"
using namespace std;

class DtHora{
    private:
        DtFecha fecha;
        int hora;
        int minuto;
        int segundo;
    public:
        DtHora();
        DtHora(DtFecha,int,int,int);
        DtFecha getFecha();
        int getHora();
        int getMinuto();
        int getSegundo();
        ~DtHora();
};

#endif

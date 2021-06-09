#ifndef DTINSTANCIACLASE_H
#define DTINSTANCIACLASE_H

#include <iostream>
using namespace std;

class DtInstanciaClase{
    private:
        bool teorico;
        bool monitoreo;
        bool practico;
    public:
        DtInstanciaClase();
        DtInstanciaClase(bool,bool,bool);
        bool getTeorico();
        bool getMonitoreo();
        bool getPractico();
        ~DtInstanciaClase();
};

#endif
#ifndef DTINICIARCLASE_H
#define DTINICIARCLASE_H

#include <iostream>
#include "../dataType/DtHora.h"
using namespace std;

class DtIniciarClase{
    private:
        string codigo;
        string nombre;
        DtHora fechaHora;
    public:
        DtIniciarClase();
        DtIniciarClase(string,string,DtHora);
        string getCodigo();
        string getNombre();
        DtHora getFechaHora();
        ~DtIniciarClase();
};

#endif
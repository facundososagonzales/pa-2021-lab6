#ifndef DTDICTADOASIGNATURA_H
#define DTDICTADOASIGNATURA_H

#include <iostream>
#include "../dataType/DtTime.h"
using namespace std;

class DtDictadoAsignatura{
    private:
        string codigo;
        string nombre;
        DtTime tiempoTotal;
    public:
        DtDictadoAsignatura();
        DtDictadoAsignatura(string,string,DtTime);
        string getCodigo();
        string getNombre();
        DtTime getTiempoTotal();
        ~DtDictadoAsignatura();

};

#endif
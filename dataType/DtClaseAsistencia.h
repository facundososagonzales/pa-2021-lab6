#ifndef DTCLASEASISTENCIA_H
#define DTCLASEASISTENCIA_H

#include <iostream>
#include "DtTime.h"
using namespace std;

class DtClaseAsistencia{
    private:
        int id;
        string nombre;
        DtTime promAsistencia;
    public:
        DtClaseAsistencia();
        DtClaseAsistencia(int,string,DtTime);
        int getId();
        string getNombre();
        DtTime getPromAsistencia();
        ~DtClaseAsistencia();

};

#endif
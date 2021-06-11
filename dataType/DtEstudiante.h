#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include<iostream>
#include "../dataType/DtUsuario.h"

using namespace std;

class DtEstudiante : public DtUsuario{
    private:
        string ci;
    public:
        DtEstudiante();
        DtEstudiante(string,string,string,string,string);
        string getci();

        ~DtEstudiante();

        friend ostream& operator << (ostream&, const DtEstudiante&);
};

#endif
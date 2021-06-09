#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include<iostream>
#include "../dataType/DtUsuario.h"

using namespace std;

class DtEsudiante : public DtUsuario{
    private:
        string ci;
    public:
        DtEsudiante();
        DtEsudiante(string,string,string,string,string);
        string getci();

        ~DtEsudiante();

        friend ostream& operator << (ostream&, const DtEsudiante&);
};

#endif
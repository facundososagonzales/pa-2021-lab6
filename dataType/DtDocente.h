#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include<iostream>
#include "../dataType/DtUsuario.h"

using namespace std;

class DtDocente : public DtUsuario{
    private:
        string instituto;
    public:
        DtDocente();
        DtDocente(string,string,string,string,string);
        string getInstituto();

        ~DtDocente();

        friend ostream& operator << (ostream&, const DtDocente&);
};

#endif
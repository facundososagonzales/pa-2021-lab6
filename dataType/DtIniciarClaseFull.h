#ifndef DTINICIARCLASEFULL_H
#define DTINICIARCLASEFULL_H

#include <iostream>
#include "../dataType/DtIniciarClase.h"
using namespace std;

class DtIniciarClaseFull : public DtIniciarClase{
    private:
        int id;
    public:
        DtIniciarClaseFull();
        DtIniciarClaseFull(string,string,DtHora,int);
        int getId();
        virtual~DtIniciarClaseFull();
};

#endif
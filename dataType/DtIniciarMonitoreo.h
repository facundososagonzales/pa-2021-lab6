#ifndef DTINICIARMONITOREO_H
#define DTINICIARMONITOREO_H

#include <iostream>
#include <list>
#include "../dataType/DtIniciarClaseFull.h"
using namespace std;

class DtIniciarMonitoreo : public DtIniciarClaseFull{
    private:
        list<string> habilitados;
    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(string,string,DtHora,int,list<string>);
        list<string> getHabilitados();
        ~DtIniciarMonitoreo();
};

#endif
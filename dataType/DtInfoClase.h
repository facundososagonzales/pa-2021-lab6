#ifndef DTINFOCLASE_H
#define DTINFOCLASE_H

#include <iostream>
#include <list>
using namespace std;

class DtInfoClase{
    private:
        int id;
        string nombre;
        list<string> docentes;
    public:
        DtInfoClase();
        DtInfoClase(int,string,list<string>);
        int getId();
        string getNombre();
        list<string> getDocentes();
        virtual ~DtInfoClase();
};

#endif
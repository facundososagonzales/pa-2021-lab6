#ifndef DTASISTIR_H
#define DTASISTIR_H

#include <iostream>

using namespace std;

class DtAsistir{
    private:
        int id;
        string codigo;
    public:
        DtAsistir();
        DtAsistir(int,string);
        int getId();
        string getCodigo();
        ~DtAsistir();
};

#endif
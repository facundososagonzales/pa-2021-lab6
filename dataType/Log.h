#ifndef LOG_H
#define LOG_H

#include <iostream>
#include "../dataType/DtHora.h"

using namespace std;

class Log{
    private:
        DtHora inicio;
        DtHora fin;
    public:
        Log();
        Log(DtHora,DtHora);
        DtHora getInicio();
        DtHora getFin();
        ~Log();

};

#endif
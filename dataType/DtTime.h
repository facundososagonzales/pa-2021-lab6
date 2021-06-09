#ifndef DTTIME_H
#define DTTIME_H

#include <iostream>
using namespace std;

class DtTime{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        DtTime();
        DtTime(int,int,int);
        int getHora();
        int getMinuto();
        int getSegundo();
        ~DtTime();

};

#endif
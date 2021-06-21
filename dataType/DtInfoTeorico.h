#ifndef DTINFOTEORICO_H
#define DTINFOTEORICO_H

#include <iostream>
#include "../dataType/DtInfoClase.h"
using namespace std;

class DtInfoTeorico : public DtInfoClase{
    private:
        int cantAsisten;
    public:
        DtInfoTeorico();
        DtInfoTeorico(int,string,list<string>,int);
        int getCantAsisten();
        ~DtInfoTeorico();
};

#endif
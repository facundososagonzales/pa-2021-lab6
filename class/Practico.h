#ifndef PRACTICO  
#define PRACTICO

#include "../class/Clase.h"

class Practico : public Clase{
public:
    Practico();
    Practico(int, string, DtHora, DtHora, string, list<Docente*>);

    ~Practico();
};

#endif
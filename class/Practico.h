#ifndef PRACTICO  
#define PRACTICO

#include "../class/Clase.h"

namespace cp{
    class Practico : public Clase{
    public:
        Practico();
        Practico(int, string, DtHora, list<Docente*>);

        ~Practico();
    };
}

#endif
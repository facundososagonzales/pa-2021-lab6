#ifndef TEORICO
#define TEORICO

#include "../class/Clase.h"

namespace ct{
    class Teorico : public Clase{
    private:
        int cantAsiste;
    public:
        Teorico();
        Teorico(int, string, DtHora, list<Docente*>);

        void setCantAsiste(int);
        int getCantAsiste();

        ~Teorico();
    };
}

#endif
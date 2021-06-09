#ifndef TEORICO
#define TEORICO

#include "../class/Clase.h"

class Teorico : public Clase{
private:
    int cantAsiste;
public:
    Teorico();
    Teorico(int, string, DtHora, DtHora, string, list<Docente*>, int);

    void setCantAsiste(int);
    int getCantAsiste();

    ~Teorico();
};

#endif
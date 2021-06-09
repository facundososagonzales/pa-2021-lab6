#ifndef ASISTEENVIVO
#define ASISTEENVIVO

#include "../dataType/DtHora.h"
#include "../class/Estudiante.h"

class Estudiante;

class AsisteEnVivo{
private:
    DtHora inicio;
    DtHora fin;
    Estudiante* estudiante;
public:
    AsisteEnVivo();
    AsisteEnVivo(DtHora, DtHora, Estudiante*);

    void setInicio(DtHora);
    DtHora getInicio();

    void setFin(DtHora);
    DtHora getFin();

    void setEstudiante(Estudiante*);
    Estudiante* getEstudiante();

    ~AsisteEnVivo();
};

#endif
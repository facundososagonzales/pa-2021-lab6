#ifndef MONITOREO  
#define MONITOREO

#include "../class/Clase.h"
#include "../class/Estudiante.h"

class Estudiante;

class Monitoreo : public Clase{
private:
    list <Estudiante*> estudiantes;
public:
    Monitoreo();
    Monitoreo(int, string, DtHora, DtHora, string, list<Docente*>, list<Estudiante*>);

    void addEstudiante(Estudiante*);
    list <Estudiante*> getEstudiantes();

    ~Monitoreo();
};

#endif
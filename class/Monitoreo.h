#ifndef MONITOREO  
#define MONITOREO

#include "../class/Clase.h"
#include "../class/Estudiante.h"

class Estudiante;

namespace cm{
    class Monitoreo : public Clase{
    private:
        list <Estudiante*> estudiantes;
    public:
        Monitoreo();
        Monitoreo(int, string, DtHora, list<Docente*>, list<Estudiante*>);

        void addEstudiante(Estudiante*);
        list <Estudiante*> getEstudiantes();
        list<string> getEmailEstudiantes();

        ~Monitoreo();
    };
}

#endif
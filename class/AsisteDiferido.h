#ifndef ASISTEDIFERIDO
#define ASISTEDIFERIDO

#include<list>
#include "../dataType/Log.h"
#include "../class/Estudiante.h"

class Estudiante;

class AsisteDiferido{
private:
    list<Log> logs;
    Estudiante* estudiante;
public:
    AsisteDiferido();
    AsisteDiferido(Estudiante*);

    void addLog(Log);
    list<Log> getLogs();

    void setEstudiante(Estudiante*);
    Estudiante* getEstudiante();

    ~AsisteDiferido();
};

#endif
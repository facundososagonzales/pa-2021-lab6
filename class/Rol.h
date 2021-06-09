#ifndef ROL
#define ROL

#include "../dataType/TipoRol.h"
#include "../class/Asignatura.h"

class Asignatura;

class Rol{
private:
    TipoRol rol;
    Asignatura* asignatura;
public:
    Rol();
    Rol(TipoRol, Asignatura*);

    void setRol(TipoRol);
    TipoRol getRol();

    void setAsignatura(Asignatura*);
    Asignatura* getAsignatura();

    ~Rol();
};

#endif
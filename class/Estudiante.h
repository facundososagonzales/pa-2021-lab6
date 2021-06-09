#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "../class/usuario.h"
#include "../class/Asignatura.h"
#include<list>

class Asignatura;

class Estudiante : public Usuario{
private:
    string documento;
    list <Asignatura*> asignaturas;
public:
    Estudiante();
    Estudiante(string, string, string, string, string);

    void setDocumento(string);
    string getDocumento();

    void addAsignatura(Asignatura*);
    list<Asignatura*> getAsignaturas();

    ~Estudiante();
};

#endif
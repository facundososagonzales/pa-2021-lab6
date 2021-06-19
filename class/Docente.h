#ifndef DOCENTE
#define DOCENTE

#include<list>
#include "../class/Usuario.h"
#include "../class/Rol.h"

class Rol; class Asignatura;

class Docente : public Usuario{
private:
    string instituto;
    list <Rol*> roles;
public:
    Docente();
    Docente(string, string, string, string, string);

    void setInstituto(string);
    string getInstituto();

    void addRol(Rol*);
    list<Rol*> getRoles();

    void setRoles(list<Rol*>);

    void eliminarRol(Asignatura*);

    ~Docente();
};

#endif
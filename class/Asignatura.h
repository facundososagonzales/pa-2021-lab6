#ifndef ASIGNATURA
#define ASIGNATURA

#include<iostream>
#include<list>
#include "../class/Clase.h"

using namespace std;

class Clase;

class Asignatura{
private:
    string codigo;
    string nombre;
    list <Clase*> clases;
public:
    Asignatura();
    Asignatura(string, string);

    void setCodigo(string);
    string getCodigo();

    void setNombre(string);
    string getNombre();

    void addClase(Clase*);
    list<Clase*> getClases();

    ~Asignatura();
};

#endif
#ifndef ASIGNATURA
#define ASIGNATURA

#include<iostream>
#include<list>
#include "../class/Clase.h"
#include "../dataType/DtInstanciaClase.h"
#include "../dataType/DtInfoTeorico.h"
#include "../dataType/DtInfoMonitoreo.h"

using namespace std;

class Clase;

class Asignatura{
private:
    string codigo;
    string nombre;
    DtInstanciaClase* dtIC;
    list <Clase*> clases;
public:
    Asignatura();
    Asignatura(string, string);

    void setCodigo(string);
    string getCodigo();

    void setNombre(string);
    string getNombre();

    void setInstanciaClase(DtInstanciaClase*);
    DtInstanciaClase* getInstanciaClase();

    void addClase(Clase*);
    list<Clase*> getClases();

    list<int> getClasesOnline();
    list<DtInfoClase*> getInfoClases();



    ~Asignatura();
};

#endif
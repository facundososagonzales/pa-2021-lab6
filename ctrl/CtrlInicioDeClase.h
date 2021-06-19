#ifndef CTRLINICIODECLASE_H
#define CTRLINICIODECLASE_H

#include <iostream>
#include <list>
#include "../interface/ICtrlInicioDeClase.h"
#include "../class/Estudiante.h"
#include "../dataType/TipoRol.h"

using namespace std;

class CtrlInicioDeClase: public ICtrlInicioDeClase{
private:
    DtIniciarClase dtic;
    list<Estudiante*> habilitados;
    int random;
    TipoRol logRol;
public:
    CtrlInicioDeClase();
    list<string> asignaturasAsignadas();
    bool seleccionarAsignatura(DtIniciarClase inicioClase);
    list<string> inscriptosAsignatura();
    void habilitarEstudiante(string);
    DtIniciarClaseFull* datosIngresados();
    void iniciarClase();
    void cargarClases();
    ~CtrlInicioDeClase();
};

#endif
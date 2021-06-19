#ifndef ICTRLINICIODECLASE_H
#define ICTRLINICIODECLASE_H

#include <iostream>
#include <list>
#include "../dataType/DtIniciarMonitoreo.h"

using namespace std;

class ICtrlInicioDeClase{
public:  
    virtual list<string> asignaturasAsignadas()=0;
    virtual bool seleccionarAsignatura(DtIniciarClase inicioClase)=0;
    virtual list<string> inscriptosAsignatura()=0;
    virtual void habilitarEstudiante(string)=0;
    virtual DtIniciarClaseFull* datosIngresados()=0;
    virtual void iniciarClase()=0;
    virtual void cargarClases()=0;

};


#endif
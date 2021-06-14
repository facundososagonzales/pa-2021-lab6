#ifndef ICTRLINSCRIPCIONASIGNATURA_H
#define ICTRLINSCRIPCIONASIGNATURA_H

#include <iostream>
#include <list>

using namespace std;

class ICtrlInscripcionAsignatura{
public:  
    virtual list<string> asignaturaNoInscripto()=0;
    virtual void seleccionarAsignatura(string)=0;
    virtual void darDeAltaInscripcion()=0;
};


#endif
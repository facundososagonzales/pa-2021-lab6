#ifndef CTRLELIMINARASIGNATURA_H
#define CTRLELIMINARASIGNATURA_H

#include <iostream>
#include "../interface/ICtrlEliminarAsignatura.h"
using namespace std;

class CtrlEliminarAsignatura : public ICtrlEliminarAsignatura {
private:
    string codigo;
public:
    CtrlEliminarAsignatura();
    list<string> listarAsignaturas();
    void seleccionarAsignatura(string);
    void eliminarAsignatura();
    ~CtrlEliminarAsignatura();
};

#endif
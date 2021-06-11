#include "CtrlAltaAsignatura.h"
#include "../handler/HandlerAsignatura.h"

CtrlAltaAsignatura::CtrlAltaAsignatura(){}

void CtrlAltaAsignatura::ingresar(DtAsignatura datosAsignatura){
    this->datosAsignatura = datosAsignatura;
}

void CtrlAltaAsignatura::altaAsignatura(){
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Asignatura* existe =hA->buscarAsignatura(this->datosAsignatura.getCodigo());
    if(existe!=NULL){
        cout << "\nYa existe una asignatura con el codigo ingresado" << endl;
    }else{
        Asignatura* asig = new Asignatura(this->datosAsignatura.getCodigo(), this->datosAsignatura.getNombre());
        asig->setInstanciaClase(this->datosAsignatura.getInstanciaClase());
        hA->addAsignatura(asig);
        cout << hA->buscarAsignatura(asig->getCodigo())->getInstanciaClase()->getMonitoreo() << endl;
    }
}

CtrlAltaAsignatura::~CtrlAltaAsignatura(){}
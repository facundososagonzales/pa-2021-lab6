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
    }
}

void CtrlAltaAsignatura::cargarAsignaturas(){
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();

    DtInstanciaClase* dtIC1 = new DtInstanciaClase(true, false, true);
    DtInstanciaClase* dtIC2 = new DtInstanciaClase(false, true, true);
    DtInstanciaClase* dtIC3 = new DtInstanciaClase(true, true, false);

    Asignatura* a1 = new Asignatura("PP-1","Principios de programacion"); a1->setInstanciaClase(dtIC1);
    Asignatura* a2 = new Asignatura("PP-2","Principios de programacion"); a2->setInstanciaClase(dtIC1);
    Asignatura* a3 = new Asignatura("php-1","Taller de programacion php"); a3->setInstanciaClase(dtIC2);
    Asignatura* a4 = new Asignatura("php-2","Taller de programacion php"); a4->setInstanciaClase(dtIC2);
    Asignatura* a5 = new Asignatura("PA-1","Programacion Avanzada"); a5->setInstanciaClase(dtIC3);
    Asignatura* a6 = new Asignatura("PA-2","Programacion Avanzada"); a6->setInstanciaClase(dtIC3);

    hA->addAsignatura(a1);  hA->addAsignatura(a2);  hA->addAsignatura(a3);
    hA->addAsignatura(a4);  hA->addAsignatura(a5);  hA->addAsignatura(a6);

}

CtrlAltaAsignatura::~CtrlAltaAsignatura(){}
#include "../ctrl/CtrlInicioDeClase.h"
#include "../handler/HandlerUsuario.h"
#include "../handler/HandlerClase.h"
#include "../class/Sesion.h"
#include "../class/Teorico.h"
#include "../class/Monitoreo.h"
#include "../class/Practico.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

CtrlInicioDeClase::CtrlInicioDeClase(){}

list<string> CtrlInicioDeClase::asignaturasAsignadas(){
    list<string> asignaturasAsignadas;                     //Verificar si esta vacia en el main
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    
    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        if(!docente->getRoles().empty()){
            for(Rol* r: docente->getRoles()){
                asignaturasAsignadas.push_back(r->getAsignatura()->getCodigo());
            }
        }
    }
    return asignaturasAsignadas;
}

bool CtrlInicioDeClase::seleccionarAsignatura(DtIniciarClase inicioClase){
    this->dtic=inicioClase;
    bool monitoreo=false;
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();

    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        for(Rol* r: docente->getRoles()){
            if(r->getAsignatura()->getCodigo()==inicioClase.getCodigo()){
                monitoreo = (r->getRol()==2);
                this->logRol = r->getRol();
            }
        }
    }
    return monitoreo;
}

list<string> CtrlInicioDeClase::inscriptosAsignatura(){
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    list<Usuario*> usuarios = hU->getUsuarios();
    list<string> inscriptos;

    for (Usuario* u: usuarios){
        Estudiante* est = dynamic_cast<Estudiante*>(u);
        if(est!=NULL){
            list<Asignatura*> asignaturasInscripto = est->getAsignaturas();
            for(Asignatura* a: asignaturasInscripto){
                if(a->getCodigo()==this->dtic.getCodigo()){
                    bool estaHabilitado=false;
                    for(Estudiante* e: this->habilitados){
                        if(e->getemail()==est->getemail()){
                            estaHabilitado=true;
                        }
                    }
                    if(!estaHabilitado){
                        inscriptos.push_back(est->getemail());
                    }
                }
            }
        }
    }
    return inscriptos;
}

void CtrlInicioDeClase::habilitarEstudiante(string email){
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    Usuario* usuario = hU->buscarUsuario(email);
    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
    if(estudiante!=NULL)
        this->habilitados.push_back(estudiante);
}

DtIniciarClaseFull CtrlInicioDeClase::datosIngresados(){
    HandlerClase* hU = HandlerClase::getInstancia();
    bool existe=true;
    int id;
    srand((unsigned) time(0));

    do{
        id = 1 + rand();
        if(!hU->existeClase(id)){
            existe=false;
            this->random=id;
        }
    }while(existe);

    DtIniciarClaseFull dticf = DtIniciarClaseFull(dtic.getCodigo(),dtic.getNombre(),dtic.getFechaHora(),this->random);
    return dticf;
}

void CtrlInicioDeClase::iniciarClase(){ ///El tipo de la clase se saca del rol del docente
    HandlerClase* hC = HandlerClase::getInstancia();
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();

    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        list<Docente*> docentes; docentes.push_back(docente);
        if(this->logRol==0){
            ct::Teorico* claseTeorico = new ct::Teorico(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes);
            for(Rol* r: docente->getRoles()){
                if(r->getAsignatura()->getCodigo()==dtic.getCodigo()){
                    r->getAsignatura()->addClase(claseTeorico);
                }
            }
        }else if(this->logRol==1){
            cp::Practico* clasePractica = new cp::Practico(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes);
            for(Rol* r: docente->getRoles()){
                if(r->getAsignatura()->getCodigo()==dtic.getCodigo()){
                    r->getAsignatura()->addClase(clasePractica);
                }
            }
        }else if(this->logRol==2){
            cm::Monitoreo* claseMonitoreo = new cm::Monitoreo(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes,this->habilitados);
        }
    }
}

void CtrlInicioDeClase::cargarClases(){
    
}

CtrlInicioDeClase::~CtrlInicioDeClase(){}
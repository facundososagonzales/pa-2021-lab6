#include "../ctrl/CtrlInicioDeClase.h"
#include "../handler/HandlerUsuario.h"
#include "../handler/HandlerClase.h"
#include "../handler/HandlerAsignatura.h"
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
    list<string> asignaturasAsignadas;                 
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    
    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        asignaturasAsignadas = docente->getAsignaturasAsignadas();  
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

DtIniciarClaseFull* CtrlInicioDeClase::datosIngresados(){
    HandlerClase* hU = HandlerClase::getInstancia();
    bool existe=true;
    int id;
    srand(time(NULL));
    do{
        id =(rand() % 5000) + 1;
        if(!hU->existeClase(id)){
            existe=false;
            this->random=id;
        }
    }while(existe);

    if(this->habilitados.empty()){
        DtIniciarClaseFull* dticf = new DtIniciarClaseFull(dtic.getCodigo(),dtic.getNombre(),dtic.getFechaHora(),this->random);
        return dticf;
    }else{
        list<string> estudiantes;
        for(Estudiante* e: this->habilitados){
            estudiantes.push_back(e->getemail());
        }
        DtIniciarMonitoreo* dtim = new DtIniciarMonitoreo(dtic.getCodigo(),dtic.getNombre(),dtic.getFechaHora(),this->random, estudiantes);
        return dtim;
    }
}

void CtrlInicioDeClase::iniciarClase(){
    HandlerClase* hC = HandlerClase::getInstancia();
    Sesion* sesion = Sesion::getInstancia();
    HandlerUsuario* hU = HandlerUsuario::getInstancia();

    Usuario* usuarioLog = hU->buscarUsuario(sesion->getUsuario());
    Docente* docente = dynamic_cast<Docente*>(usuarioLog);
    if(docente!=NULL){
        for(Rol* r: docente->getRoles()){
            if(r->getAsignatura()->getCodigo()==dtic.getCodigo()){
                list<Docente*> docentes; docentes.push_back(docente);
                if(this->logRol==0){
                    ct::Teorico* claseTeorico = new ct::Teorico(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes);
                    claseTeorico->setRutaVideo("PENDIENTE");
                    claseTeorico->setCantAsiste(0);
                    r->getAsignatura()->addClase(claseTeorico);
                    hC->addClase(claseTeorico);
                }else if(this->logRol==1){
                    cp::Practico* clasePractica = new cp::Practico(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes);
                    clasePractica->setRutaVideo("PENDIENTE");
                    r->getAsignatura()->addClase(clasePractica);
                    hC->addClase(clasePractica);
                }else if(this->logRol==2){
                    cm::Monitoreo* claseMonitoreo = new cm::Monitoreo(this->random,dtic.getNombre(),dtic.getFechaHora(),docentes,this->habilitados);
                    claseMonitoreo->setRutaVideo("PENDIENTE");                     
                    r->getAsignatura()->addClase(claseMonitoreo);
                    hC->addClase(claseMonitoreo);
                }
                cout << "La clase " + this->dtic.getNombre() + " fue creada con exito" << endl;
            }
        }
    }
}

void CtrlInicioDeClase::cargarClases(){
    time_t fecha = time(0); tm* now = localtime(&fecha);
    DtFecha dtf = DtFecha(now->tm_mday,now->tm_mon+1,now->tm_year+1900);
    DtHora dth = DtHora(dtf,now->tm_hour,now->tm_min,now->tm_sec);

    time_t fecha1 = time(0); tm* now1 = localtime(&fecha);
    DtFecha* dtf1 = new DtFecha(now1->tm_mday,now1->tm_mon+1,now1->tm_year+1900);
    DtHora* dth1 = new DtHora(dtf,now1->tm_hour,now1->tm_min,now1->tm_sec);

    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    HandlerClase* hC = HandlerClase::getInstancia();
    Asignatura* pp1 = hA->buscarAsignatura("PP-1");
    Usuario* test = hU->buscarUsuario("test");
    Usuario* estudiante = hU->buscarUsuario("est");
    Docente* doc = dynamic_cast<Docente*>(test);
    Estudiante* est = dynamic_cast<Estudiante*>(estudiante);
    list<Docente*> docentes; docentes.push_back(doc);

    for(Rol* r: doc->getRoles()){
        if(r->getAsignatura()->getCodigo()==pp1->getCodigo()){   
            ct::Teorico* claseTeorico = new ct::Teorico(500,"ClaseT1",dth,docentes);
            claseTeorico->setRutaVideo("PENDIENTE");
            claseTeorico->setCantAsiste(0);
            AsisteEnVivo* asiste = new AsisteEnVivo(dth1,dth1,est);
            claseTeorico->addAsisteEnVivo(asiste);
            Participacion* mensaje = new Participacion(5001,dth,"Hola"); mensaje->setRespuestaA(NULL);
            Participacion* mensaje1 = new Participacion(5002,dth,"Holaa"); mensaje1->setRespuestaA(mensaje);
            claseTeorico->addParticipacion(mensaje); claseTeorico->addParticipacion(mensaje1);
            r->getAsignatura()->addClase(claseTeorico);
            hC->addClase(claseTeorico);
        }
    }
}

CtrlInicioDeClase::~CtrlInicioDeClase(){}
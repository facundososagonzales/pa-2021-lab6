#include "../ctrl/CtrlAsignacionDocAsignatura.h"
#include "../handler/HandlerAsignatura.h"
#include "../handler/HandlerUsuario.h"
#include "../dataType/DtDocente.h"
 
CtrlAsignacionDocAsignatura::CtrlAsignacionDocAsignatura(){}

list<string> CtrlAsignacionDocAsignatura::listarAsignaturas(){
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    list<Asignatura*> asignaturas = hA->getAsignaturas();
    list<string> codAsignatura;

    for(Asignatura* a: asignaturas){
        codAsignatura.push_back(a->getCodigo());
    }

    return codAsignatura;
}

list<string> CtrlAsignacionDocAsignatura::docentesSinAsignar(string asignatura){
    this->asignatura=asignatura;
    bool asignado;
    HandlerUsuario* hU = HandlerUsuario::getInstancia();

    list<Usuario*> docentes = hU->getUsuarios();
    list<string> docentesAsignados;

    for(Usuario* u: docentes){
        Docente* doc = dynamic_cast<Docente*>(u);
        if(doc!=NULL){
            asignado=false;
            for(Rol* rol: doc->getRoles()){
                if(rol->getAsignatura()->getCodigo()==this->asignatura){
                    asignado=true;
                }
            }
            if(!asignado){
                docentesAsignados.push_back(doc->getemail());
            }
        }
    }
    return docentesAsignados;
}

void CtrlAsignacionDocAsignatura::seleccionarDocente(string docente, TipoRol rol){
    this->docente=docente;
    this->rol=rol;
}

void CtrlAsignacionDocAsignatura::asignarDocente(){
    HandlerUsuario* hU = HandlerUsuario::getInstancia();
    HandlerAsignatura* hA = HandlerAsignatura::getInstancia();
    Usuario* usuario = hU->buscarUsuario(this->docente);
    Asignatura* asignatura = hA->buscarAsignatura(this->asignatura);
    Docente* doc = dynamic_cast<Docente*>(usuario);
    string roles[3] = {"Teorico","Practico","Monitoreo"};

    if(doc!=NULL){

        if((rol==0 && asignatura->getInstanciaClase()->getTeorico()) || 
        (rol==1 && asignatura->getInstanciaClase()->getPractico())  || 
        (rol==2 && asignatura->getInstanciaClase()->getMonitoreo())){

            Rol* rol = new Rol(this->rol,asignatura);
            doc->addRol(rol);
            cout << "El docente se agrego correctamente a la asignatura" << endl;

        }else if(rol==0 && !(asignatura->getInstanciaClase()->getTeorico())){
            cout << "La asignatura no tiene instancias de teorico" <<endl;
        }else if (rol==1 && !(asignatura->getInstanciaClase()->getPractico())){
            cout << "La asignatura no tiene instancias de practico" <<endl;
        }else if (rol==2 && !(asignatura->getInstanciaClase()->getMonitoreo())){
            cout << "La asignatura no tiene instancias de monitoreo" <<endl;
        }
    }
}

CtrlAsignacionDocAsignatura::~CtrlAsignacionDocAsignatura(){}
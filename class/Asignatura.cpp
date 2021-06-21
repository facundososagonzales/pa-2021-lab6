#include "../class/Asignatura.h"
#include "../class/Teorico.h"
#include "../class/Monitoreo.h"
#include "../class/Practico.h"

Asignatura::Asignatura(){}

Asignatura::Asignatura(string codigo, string nombre){
    this->codigo=codigo;
    this->nombre=nombre;
}

string Asignatura::getCodigo() {
    return this->codigo;
}

void Asignatura::setCodigo(string codigo) {
    this->codigo=codigo;
}

string Asignatura::getNombre() {
    return this->nombre;
}

void Asignatura::setNombre(string nombre) {
    this->nombre=nombre;
}

void Asignatura::setInstanciaClase(DtInstanciaClase* dtIC){
    this->dtIC=dtIC;
}

DtInstanciaClase* Asignatura::getInstanciaClase(){
    return this->dtIC;
}

list<Clase*> Asignatura::getClases() {
    return this->clases;
}

void Asignatura::addClase(Clase* clase) {
    this->clases.push_back (clase);
}

list<int> Asignatura::getClasesOnline(){
    list<int> idClases;
    for(Clase* c : this->clases){
        if(c->getRutaVideo()=="PENDIENTE"){
            idClases.push_back(c->getId());
        } 
    }
    return idClases;
}

list<DtInfoClase*> Asignatura::getInfoClases(){
    list<DtInfoClase*> dtInfoClases;
    for(Clase* c : this->clases){
        ct::Teorico* claseTeorico = dynamic_cast<ct::Teorico*>(c);
        if(claseTeorico!=NULL){
            DtInfoTeorico* dtInfoTeorico = new DtInfoTeorico(claseTeorico->getId(), 
            claseTeorico->getNombre(), claseTeorico->getEmailDocentes(), 
            claseTeorico->getCantAsiste());
            dtInfoClases.push_back(dtInfoTeorico);
        }else{
            cm::Monitoreo* claseMonitoreo = dynamic_cast<cm::Monitoreo*>(c);
            if(claseMonitoreo!=NULL){
                DtInfoMonitoreo* dtInfoMonitoreo = new DtInfoMonitoreo(claseMonitoreo->getId(), 
                claseMonitoreo->getNombre(), claseMonitoreo->getEmailDocentes(),claseMonitoreo->getEmailEstudiantes());
                dtInfoClases.push_back(dtInfoMonitoreo);
            }else{
                cp::Practico* clasePractico = dynamic_cast<cp::Practico*>(c);
                if(clasePractico!=NULL){
                    DtInfoClase* dtInfoClase = new DtInfoClase(clasePractico->getId(), 
                    clasePractico->getNombre(), clasePractico->getEmailDocentes());
                    dtInfoClases.push_back(dtInfoClase);
                }
            }
        }
    }
    return dtInfoClases;
}

Asignatura::~Asignatura() {}
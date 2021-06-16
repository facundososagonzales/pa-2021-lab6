#include "../class/Clase.h"

Clase::Clase(){}

Clase::Clase(int id, string nombre, DtHora inicio, list<Docente*> docente){
    this->id=id;
    this->nombre=nombre;
    this->inicio=inicio;
    this->docentes=docente; 
}

Clase::Clase(int id, string nombre, DtHora inicio, DtHora fin, string rutaVideo, list<Docente*> docente){
    this->id=id;
    this->nombre=nombre;
    this->inicio=inicio;
    this->fin=fin;
    this->rutaVideo=rutaVideo;
    this->docentes=docente;
}

    void Clase::setId(int id){
        this->id=id;
    }

    int Clase::getId(){
        return this->id;
    }

    void Clase::setNombre(string nombre){
        this->nombre=nombre;
    }

    string Clase::getNombre(){
        return this->nombre;
    }

    void Clase::setInicio(DtHora inicio){
        this->inicio=inicio;
    }

    DtHora Clase::getInicio(){
        return this->inicio;
    }

    void Clase::setFin(DtHora fin){
        this->fin=fin;
    }

    DtHora Clase::getFin(){
        return this->fin;
    }

    void Clase::setRutaVideo(string rutaVideo){
        this->rutaVideo=rutaVideo;
    }

    string Clase::getRutaVideo(){
        return this->rutaVideo;
    }

    void Clase::addDocente(Docente* docente){
        this->docentes.push_back(docente);
    }

    list<Docente*> Clase::getDocentes(){
        return this->docentes;
    }


    void Clase::addParticipacion(Participacion* participacion){
        this->participaciones.push_back(participacion);
    }

    list<Participacion*> Clase::getParticipaciones(){
        return this->participaciones;
    }


    void Clase::addAsisteEnVivo(AsisteEnVivo* asisteEnVivo){
        this->asistenciasEnvivo.push_back(asisteEnVivo);
    }

    list<AsisteEnVivo*> Clase::getAsistenciasEnVivo(){
        return this->asistenciasEnvivo;
    }


    void Clase::addAsisteDiferido(AsisteDiferido* asisteDiferido){
        this->asistenciasDiferidos.push_back(asisteDiferido);
    }

    list<AsisteDiferido*> Clase::getAsistenciasDiferido(){
        return this->asistenciasDiferidos;
    }

    Clase::~Clase(){};

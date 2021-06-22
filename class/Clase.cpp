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

    bool Clase::existeEstudianteEnClase(string email){
        bool flag=false;
        for(AsisteEnVivo* a : this->getAsistenciasEnVivo()){
            if(a->getEstudiante()->getemail()==email){
                flag=true;
            }
        }
    return flag;
    }

    bool Clase::existeDocenteEnClase(string email){
        bool flag=false;
        for(Docente* d : this->docentes){
            if(d->getemail()==email){
                flag=true;
            }
        }
    return flag;
    }

    list<DtParticipacion*> Clase::getDtParticipaciones(){
        list<DtParticipacion*> dtPs;
        for(Participacion* p : this->participaciones){            
            DtParticipacion* dtPart = p->getDtParticipacionPuntero();
            dtPs.push_back(dtPart);
        }
        return dtPs;
    }

    Participacion* Clase::buscarParticipacion(int idP){
        Participacion* part = NULL;
        for(Participacion* p : this->participaciones){
            if(p->getId()==idP){
                part = p;
            }
        }
        return part;
    }

    void Clase::agregarAsistenciaOnline(Estudiante* estudianteLog){
        time_t fecha = time(0); tm* now = localtime(&fecha);
        DtFecha dtf = DtFecha(now->tm_mday,now->tm_mon+1,now->tm_year+1900);
        DtHora* dth = new DtHora(dtf,now->tm_hour,now->tm_min,now->tm_sec);

        AsisteEnVivo* asisteEnVivo = new AsisteEnVivo(dth, NULL, estudianteLog);
        this->asistenciasEnvivo.push_back(asisteEnVivo);
    }

    list<string> Clase::getEmailDocentes(){
        list<string> emailDocentes;
        for(Docente* d : this->docentes){
            emailDocentes.push_back(d->getemail());
        }
        return emailDocentes;
    }

    list<string> Clase::getEmailEstudiantes(){
        list<string> emailEstudiantes;
        for(AsisteEnVivo* a : this->asistenciasEnvivo){            
            emailEstudiantes.push_back(a->getEstudiante()->getemail());
        }
        return emailEstudiantes;
    }

    bool Clase::existeMensaje(int idM){
        bool existe=false;
        for(Participacion* p : this->participaciones){
            if(p->getId()==idM){
                existe=true;
            }
        }
        return existe;
    }

    Clase::~Clase(){};

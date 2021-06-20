#include "CtrlEnvioMensaje.h"
#include "../handler/HandlerClase.h"
#include "../handler/HandlerUsuario.h"
#include "../class/Sesion.h"
#include <time.h>

CtrlEnvioMensaje::CtrlEnvioMensaje(){}

    list<int> CtrlEnvioMensaje::claseOnlineAsistiendo(){
        Sesion* sesion = Sesion::getInstancia();
        string usuarioName = sesion->getUsuario();
        HandlerUsuario* hU = HandlerUsuario::getInstancia();
        Usuario* usuario = hU->buscarUsuario(usuarioName);
        HandlerClase* hC = HandlerClase::getInstancia();
        list<Clase*> clases = hC->getClases();
        Docente* docente = dynamic_cast<Docente*>(usuario);
        bool flag=false;
        list<int> idsClase;
        if(docente!=NULL){   
            for(Clase* c: clases){
                flag = c->existeDocenteEnClase(docente->getemail());
                if (flag){
                    idsClase.push_back(c->getId());
                }
            }
        }else{
            Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
            if(estudiante!=NULL){
                for(Clase* c: clases){
                    flag = c->existeEstudianteEnClase(estudiante->getemail());
                    if(flag){
                        idsClase.push_back(c->getId());
                    }
                }
            }
        }
        return idsClase;
    }

    list<DtParticipacion*> CtrlEnvioMensaje::seleccionarClase(int idClase){
        this->id = idClase;
        HandlerClase* hC = HandlerClase::getInstancia();
        Clase* clase = hC->buscarClase(this->id);
        list<DtParticipacion*> dtParticipaciones = clase->getDtParticipaciones();
        return dtParticipaciones;
    }

    void CtrlEnvioMensaje::responder(int respuestaA){
        this->idp = respuestaA;
    }

    void CtrlEnvioMensaje::ingresarTexto(string texto){
        this->texto = texto;
    }

    void CtrlEnvioMensaje::enviarMensaje(){
        HandlerClase* hC = HandlerClase::getInstancia();
        Clase* clase = hC->buscarClase(this->id);
        Participacion* p = clase->buscarParticipacion(this->idp);
        
        time_t fecha = time(0); tm* now = localtime(&fecha);
		DtFecha dtf = DtFecha(now->tm_mday,now->tm_mon+1,now->tm_year+1900);
		DtHora dth = DtHora(dtf,now->tm_hour,now->tm_min,now->tm_sec);
        
        Participacion* part = new Participacion(this->id, dth, this->texto);
        part->setRespuestaA(p);
    }

    CtrlEnvioMensaje::~CtrlEnvioMensaje(){}

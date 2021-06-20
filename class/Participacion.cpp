#include "../class/Participacion.h"

Participacion::Participacion(){}

Participacion::Participacion(int id, DtHora hora, string mensaje){
    this->id=id;
    this->hora=hora;
    this->mensaje=mensaje;   
}

int Participacion::getId() {
    return this->id;
}

void Participacion::setId(int id) {
    this->id=id;
}

DtHora Participacion::getHora() {
    return this->hora;
}

void Participacion::setHora(DtHora hora) {
    this->hora=hora;
}

string Participacion::getMensaje() {
    return this->mensaje;
}

void Participacion::setMensaje(string mensaje) {
    this->mensaje=mensaje;
}

Participacion* Participacion::getRespuestaA() {
    return this->respuestaA;
}

void Participacion::setRespuestaA(Participacion* respuestaA) {
    this->respuestaA=respuestaA;
}

DtParticipacion* Participacion::getDtParticipacionPuntero(){
    DtParticipacion* dtP;
    if(this->respuestaA==NULL){
        dtP = new DtParticipacion(this->id,this->hora,this->mensaje,NULL);
    }else{
        dtP = new DtParticipacion(this->id,this->hora,this->mensaje,this->respuestaA->getDtParticipacionPuntero());
    }
    return dtP;
}

Participacion::~Participacion(){}
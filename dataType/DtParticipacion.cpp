#include "DtParticipacion.h"

DtParticipacion::DtParticipacion(){}

DtParticipacion::DtParticipacion(int id,DtHora fecha,string mensaje,DtParticipacion* responde){
	this->id=id;
    this->fecha=fecha;
	this->mensaje=mensaje;	
	this->responde=responde;
}

int DtParticipacion::getId(){
    return id;
}
DtHora DtParticipacion::getFecha(){
    return fecha;
}
string DtParticipacion::getMensaje(){
    return mensaje;
}
DtParticipacion* DtParticipacion::getResponde(){
    return responde;
}
DtParticipacion::~DtParticipacion(){}
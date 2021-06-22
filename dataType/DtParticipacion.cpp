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

void DtParticipacion::imprimirParticipacion(){
    if(this->responde==NULL){
        cout << "|->Id: " << this->id << " - Mensaje: " << this->mensaje << endl;
    }else{        
        cout << "|<-Id: " << id << " - IdR: " <<this->responde->id <<" - Mensaje: " << mensaje << endl;
        //imprimirParticipacion(this->responde,this->id);
    }
}

void DtParticipacion::imprimirParticipacion(DtParticipacion* participacion, int id){
    if(participacion->responde==NULL){
        cout << "|<-Id: " << id << " - IdR: " << participacion->id <<" - Mensaje: " << mensaje << endl;
    }
}

DtParticipacion::~DtParticipacion(){}
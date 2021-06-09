#include "Log.h"

Log::Log(){}
Log::Log(DtHora inicio, DtHora fin){
	this->inicio=inicio;
	this->fin=fin;
}
DtHora Log::getInicio(){
    return inicio;
}
DtHora Log::getFin(){
    return fin;
}
Log::~Log(){}
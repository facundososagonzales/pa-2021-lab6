#include "../class/Practico.h"

cp::Practico::Practico(){}

cp::Practico::Practico(int id, string nombre, DtHora inicio, list<Docente*> docente)
:Clase(id, nombre, inicio, docente){}

cp::Practico::~Practico(){}
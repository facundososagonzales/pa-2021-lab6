#include "../class/Practico.h"

Practico::Practico(){}

Practico::Practico(int id, string nombre, DtHora inicio, DtHora fin, string rutaVideo, list<Docente*> docente)
:Clase(id, nombre, inicio, fin, rutaVideo, docente){}

Practico::~Practico(){}
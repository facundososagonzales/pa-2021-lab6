#include "../class/Teorico.h"

ct::Teorico::Teorico(){}

ct::Teorico::Teorico(int id, string nombre, DtHora inicio, list<Docente*> docente)
:Clase(id, nombre, inicio, docente){}

void ct::Teorico::setCantAsiste(int cantAsiste) {
    this->cantAsiste=cantAsiste;
}

int ct::Teorico::getCantAsiste() {
    return this->cantAsiste;
}

ct::Teorico::~Teorico(){}
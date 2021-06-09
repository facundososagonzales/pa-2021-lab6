#include "../class/Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int id, string nombre, DtHora inicio, DtHora fin, string rutaVideo, list<Docente*> docente, int cantAsiste)
:Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->cantAsiste=cantAsiste;
}

void Teorico::setCantAsiste(int cantAsiste) {
    this->cantAsiste=cantAsiste;
}

int Teorico::getCantAsiste() {
    return this->cantAsiste;
}

Teorico::~Teorico(){}
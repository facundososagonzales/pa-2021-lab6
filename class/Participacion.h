#ifndef PARTICIPACION
#define PARTICIPACION

#include "../dataType/DtHora.h"
#include "../class/Usuario.h"

class Participacion{
private:
    int id;
    DtHora hora;
    string mensaje;
    Participacion* respuestaA;
public:
    Participacion();
    Participacion(int, DtHora, string);

    void setId(int);
    int getId();

    void setHora(DtHora hora);
    DtHora getHora();

    void setMensaje(string);
    string getMensaje();

    void setRespuestaA(Participacion*);
    Participacion* getRespuestaA();

    ~Participacion();
};

#endif
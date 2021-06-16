#ifndef CLASE
#define CLASE

#include<list>
#include "../class/Docente.h"
#include "../class/Participacion.h"
#include "../class/AsisteDiferido.h"
#include "../class/AsisteEnVivo.h"

class Docente;
class Participacion;
class AsisteEnVivo;
class AsisteDiferido;

class Clase{
private:
    int id;
    string nombre;
    DtHora inicio;
    DtHora fin;
    string rutaVideo;
    list<Docente*> docentes;
    list<Participacion*> participaciones;
    list<AsisteEnVivo*> asistenciasEnvivo;
    list<AsisteDiferido*> asistenciasDiferidos;
public:
    Clase();
    Clase(int, string, DtHora, list<Docente*>);
    Clase(int, string, DtHora, DtHora, string, list<Docente*>);

    void setId(int);
    int getId();

    void setNombre(string);
    string getNombre();

    void setInicio(DtHora);
    DtHora getInicio();

    void setFin(DtHora);
    DtHora getFin();

    void setRutaVideo(string);
    string getRutaVideo();

    void addDocente(Docente*);
    list<Docente*> getDocentes();

    void addParticipacion(Participacion*);
    list<Participacion*> getParticipaciones();

    void addAsisteEnVivo(AsisteEnVivo*);
    list<AsisteEnVivo*> getAsistenciasEnVivo();

    void addAsisteDiferido(AsisteDiferido*);
    list<AsisteDiferido*> getAsistenciasDiferido();

    ~Clase();
};

#endif
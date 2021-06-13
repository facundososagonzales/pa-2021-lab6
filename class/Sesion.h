#ifndef SESION
#define SESION

#include <string>
#include "../class/Usuario.h"
#include "../dataType/TipoSesion.h"

using namespace std;

class Sesion{
  private:
    Sesion();
    static bool iniciada;
    static Sesion* instancia;
    SesionType::TipoSesion tipo;
    Usuario* usuario;
  public:
    static Sesion* getInstancia();
    static bool checkIniciada();
    static void setLogin();
    static void setLogout();
    void setUsuario(Usuario*);
    void setTipo(SesionType::TipoSesion);
    string getUsuario();
    string getNombre();
    SesionType::TipoSesion getTipo();
    ~Sesion();
};

#endif
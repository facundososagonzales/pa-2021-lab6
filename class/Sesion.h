#ifndef SESION
#define SESION

#include <string>
#include "../dataType/TipoSesion.h"

using namespace std;

class Sesion{
  private:
    Sesion();
    static bool iniciada;
    TipoSesion tipoSesion;
    static Sesion* instancia;
  public:
    static Sesion* getInstancia();
    static bool checkIniciada();
    static void setLogin(TipoSesion);
    static void setLogout();
    ~Sesion();
};

#endif
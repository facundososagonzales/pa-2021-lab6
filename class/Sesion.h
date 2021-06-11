#ifndef SESION
#define SESION

#include <string>
#include "../class/Usuario.h"

using namespace std;

class Sesion{
  private:
    Sesion();
    static bool iniciada;
    static Sesion* instancia;
    Usuario* usuario;
  public:
    static Sesion* getInstancia();
    static bool checkIniciada();
    static void setLogin();
    static void setLogout();
    void setUsuario(Usuario*);
    string getUsuario();
    string getNombre();
    ~Sesion();
};

#endif
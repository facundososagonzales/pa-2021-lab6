#ifndef USUARIO
#define USUARIO

#include<iostream>

using namespace std;

class Usuario{
    private:
        string nombre;
        string imagenUrl;
        string email;
        string password;
    public:
        Usuario();
        Usuario(string, string, string, string);

        string getnombre();
        void setnombre(string);

        string getimagenUrl();
        void setimagenUrl(string);

        string getemail();
        void setemail(string);

        string getpassword();
        void setpassword(string);

        virtual ~Usuario();
};

#endif
#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include<iostream>

using namespace std;

class DtUsuario{
    private:
        string nombre;
        string url;
        string email;
        string pass;
    public:
        DtUsuario();
        DtUsuario(string,string,string,string);
        string getnombre();
        string geturl();
        string getemail();
        string getpass();

        virtual ~DtUsuario();

        friend ostream& operator << (ostream&, const DtUsuario&);

};

#endif
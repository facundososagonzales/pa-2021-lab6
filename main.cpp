#include <iostream>
#include <ctime>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include "Fabrica.h"
#include "interface/ICtrlAltaUsuario.h"
#include "dataType/DtDocente.h"
#include "dataType/DtEstudiante.h"

using namespace std;

void iniciarSesion();

void altaUsuario();

void menu(){
		//system("clear");
		cout <<"____________________________________________"<<endl;
		cout <<"_________________Bienvenido_________________"<<endl;
		cout <<"________________Elija opcion:_______________"<<endl;
		cout <<"____________________________________________"<<endl;
		Fabrica* fab = Fabrica::getInstancia();
		ICtrlAltaUsuario* icau = fab->getICtrlAltaUsuario();
		if(!icau->isLogged()){
			cout <<"__________1. Iniciar Sesion_________________"<<endl;
		}else{
			cout <<"__________1. Cerrar Sesion__________________"<<endl;
		}
		
		cout <<"__________2. Alta Usuario___________________"<<endl;
		cout <<"__________3. Listar Puertos_________________"<<endl;
		cout <<"__________4. Agregar Arribo_________________"<<endl;
		cout <<"__________5. Obtener info de arribos________"<<endl;
		cout <<"__________6. Eliminar Arribos_______________"<<endl;
		cout <<"__________7. Listar Barcos__________________"<<endl;
		cout <<"__________8. Salir__________________________"<<endl;
		cout <<"____________________________________________"<<endl;
		cout <<"OPCION: ";
}

int main(){
	int opcion;
	menu();
	cin >> opcion;
	while(opcion != 8){
		switch(opcion){
			case 1:
				iniciarSesion();
			break;
			case 2:
				altaUsuario();
			break;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		menu();
		cin >> opcion;
	}
	DtUsuario us = DtUsuario();
	cout << "SALIENDO..." << endl;
}


////////////////////////////////////////////> Operaciones A <//////////////////////////////////////////////////

void altaUsuario(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_______________ Alta Usuario________________"<< endl;
	cout <<"_____________________________________________" <<endl;
	string nombre, url, email, pass;
	int opcion;
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAltaUsuario* icau = fab->getICtrlAltaUsuario();
	cout << "Ingresar nombre del Usuario: ";
	cin >> nombre;
	cout << "Ingresar url de la imagen del Usuario: ";
	cin >> url;	
	cout << "Ingresar email del Usuario: ";
	cin >> email;
	cout << "Ingresar password del Usuario: ";
	cin >> pass;
	cout << "Ingresar 1 si el Usuario es Docente o 2 si es Estudiante: ";
	cin >> opcion;	
	if(opcion==1){		
		string instituto;
		cout << "Ingresar instituto del Docente: ";
		cin >> instituto;
		DtDocente dtD = DtDocente(nombre,url,email,pass,instituto);
		icau->ingresarDatosPerfil(dtD);
		icau->ingresarDocente(instituto);
		cout << dtD << endl;
		icau->altaUsuario(dtD);
	}else if(opcion==2){
		string doc;
		cout << "Ingresar ci del Estudiante: ";
		cin >> doc;
		DtEstudiante dtE = DtEstudiante(nombre,url,email,pass,doc);		
		icau->ingresarDatosPerfil(dtE);
		icau->ingresarEstudiante(doc);
		icau->altaUsuario(dtE);
	}else{
		cout << "Opcion incorrecta." << endl;
	}
}

void iniciarSesion(){
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAltaUsuario* icau = fab->getICtrlAltaUsuario();
	if(icau->isLogged()){
		icau->cerrarSesion();
	}else{
		string email,pass;
		cout << "Ingresar email: ";
		cin >> email;
		icau->ingresarEmail(email);
		cout << "Ingresar Password: ";
		cin >> pass;
		icau->ingresarPassword(pass);
		icau->iniciarSesion();

	}
}
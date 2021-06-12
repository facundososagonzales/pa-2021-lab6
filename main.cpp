#include <iostream>
#include <ctime>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include "Fabrica.h"
#include "interface/ICtrlAltaUsuario.h"
#include "interface/ICtrlAltaAsignatura.h"
#include "interface/ICtrlAsignacionDocAsignatura.h"
#include "dataType/DtDocente.h"
#include "dataType/DtEstudiante.h"
#include "dataType/DtAsignatura.h"

using namespace std;

void iniciarSesion();
void altaUsuario();
void altaAsignatura();
void asignacionDocenteAsignatura();

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
		cout <<"__________3. Alta Asignatura________________"<<endl;
		cout <<"__________4. Agregar Doc a asignatura_______"<<endl;
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
			case 1: iniciarSesion();  			   break;

			case 2: altaUsuario();    			   break;

			case 3: altaAsignatura();			   break;

			case 4: asignacionDocenteAsignatura(); break;

			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
}


////////////////////////////////////////////> Operaciones A <//////////////////////////////////////////////////

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

////////////////////////////////////////////> Operaciones B <//////////////////////////////////////////////////

void altaUsuario(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_______________ Alta Usuario_________________"<< endl;
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

////////////////////////////////////////////> Operaciones C <//////////////////////////////////////////////////

void altaAsignatura(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_______________ Alta Asignatura______________"<< endl;
	cout <<"_____________________________________________" <<endl;
	string nombre, codigo, confirmacion;
	string teorico, monitoreo, practico;
	bool isTeorico, isMonitoreo, isPractico, condicion;
	int opcion;
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAltaAsignatura* icaa = fab->getICtrlAltaAsignatura();
	
	cout << "\nIngrese el nombre de la Asignatura: ";
	cin >> nombre;
	cout << "Ingrese el codigo de la Asignatura: ";
	cin >> codigo;

	do{
		cout << "Tiene instancia de Teorico? (s/n): ";
		cin >> teorico;
		if(teorico=="s"){
			isTeorico=true;			
		}else if(teorico=="n"){
			isTeorico=false;
		}else{
			cout << "Opcion incorrecta." << endl;
		}
	}while(teorico!="s" && teorico!="n");

	do{
		cout << "Tiene instancia de Monitoreo? (s/n): ";
		cin >> monitoreo;
		if(monitoreo=="s"){
			isMonitoreo=true;			
		}else if(monitoreo=="n"){
			isMonitoreo=false;
		}else{
			cout << "Opcion incorrecta." << endl;
		}
	}while(monitoreo!="s" && monitoreo!="n");

	do{
		cout << "Tiene instancia de Practico? (s/n): ";
		cin >> practico;
		if(practico=="s"){
			isPractico=true;			
		}else if(practico=="n"){
			isPractico=false;
		}else{
			cout << "Opcion incorrecta." << endl;
		}
	}while(practico!="s" && practico!="n");

	DtInstanciaClase* dtic = new DtInstanciaClase(isTeorico, isMonitoreo, isPractico);
	DtAsignatura dta = DtAsignatura(nombre, codigo, dtic);
	cout << dta << endl;

	do{
		cout << "Quiere dar de alta la asignatura anterior? (s/n): ";
		cin >> confirmacion;
		if(confirmacion=="s"){
			condicion=true;			
		}else if(confirmacion=="n"){
			condicion=false;
		}else{
			cout << "Opcion incorrecta." << endl;
		}
	}while(practico!="s" && practico!="n");

	if(condicion){
		icaa->ingresar(dta);
		icaa->altaAsignatura();
	}
}

////////////////////////////////////////////> Operaciones D <//////////////////////////////////////////////////

void asignacionDocenteAsignatura(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______________Asignar Docente________________"<< endl;
	cout <<"_____________________________________________" <<endl;

	string codigo,email, confirmar;
	int seleccion;
	TipoRol rol;
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAsignacionDocAsignatura* icada = fab->getICtrlAsignacionDocAsignatura();

	for(string s: icada->listarAsignaturas()){
		cout << "Asignatura: " + s << endl;
	}
	cout << "Seleccionar asignatura para asignarle docente: ";
	cin >> codigo;

	do{
		
		for (string s: icada->docentesSinAsignar(codigo)){
			cout << "Docente email: " + s << endl;
		}
		cout << "Seleccionar docente: ";
		cin >> email;

		do{
			cout << "\nTeorico: 1	Practico: 2    Monitoreo: 3" << endl;
			cout << "Seleccionar rol: ";
			cin >> seleccion;
		}while(seleccion!=1 && seleccion!=2 && seleccion!=3);

		switch(seleccion){
			case 1: rol = Teorico; 		  break;
			case 2: rol = Practico; 	  break;
			case 3: rol = Monitoreo;	  break;
		}

		icada->seleccionarDocente(email,rol);

		do{
			cout << "\nDocente: " + email << endl ;
			cout << "Asignatura: " + codigo <<endl;
			cout << "Rol: " + rol <<endl;
			cout << "Desea agregar el docente a la asignatura? (s/n): ";
			cin >> confirmar;

			if(confirmar=="s"){
				icada->asignarDocente();
			}else if(confirmar!="n"){
				cout << "opcion incorrecta, intente de nuevo" << endl;
			}
		}while(confirmar!="s" && confirmar!="n");

		cout<< "Desea seguir agregando docentes? (s/n): ";
		cin >> confirmar;

	}while(confirmar!="n");

}
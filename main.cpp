#include <iostream>
#include <ctime>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include "Fabrica.h"
#include "interface/ICtrlAltaUsuario.h"


using namespace std;

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
		
		cout <<"__________2. Agregar Barco__________________"<<endl;
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
				cout << "main funciona" << endl;
			break;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
}


////////////////////////////////////////////> Operaciones A <//////////////////////////////////////////////////
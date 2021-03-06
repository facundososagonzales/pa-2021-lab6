#include <iostream>
#include <ctime>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Fabrica.h"
#include "dataType/DtDocente.h"
#include "dataType/DtEstudiante.h"
#include "dataType/DtAsignatura.h"
#include "dataType/DtParticipacion.h"
#include "dataType/DtInfoMonitoreo.h"
#include "dataType/DtInfoTeorico.h"

using namespace std;

void iniciarSesion();
void altaUsuario();
void altaAsignatura();
void asignacionDocenteAsignatura();
void inscripcionAsignatura();
void inicioDeClase();
void eliminarAsignatura();
void envioMensaje();
void asisteEnVivo();
void listadoDeClases();

void menu(){
		Fabrica* fab = Fabrica::getInstancia();
		ICtrlAltaUsuario* icau = fab->getICtrlAltaUsuario();
		//system("clear");
		cout <<"____________________________________________"<<endl;
		cout <<"_________________Bienvenido_________________"<<endl;
		cout <<"________________Elija opcion:_______________"<<endl;
		cout <<"____________________________________________"<<endl;
		if(!icau->isLogged()){
			cout <<"__________1. Iniciar Sesion_________________"<<endl;
		}else{
			cout <<"__________1. Cerrar Sesion__________________"<<endl;
		}		
		cout <<"__________2. Alta Usuario___________________"<<endl;
		cout <<"__________3. Alta Asignatura________________"<<endl;
		cout <<"__________4. Agregar Doc a asignatura_______"<<endl;
		if(icau->isLogged() && !icau->isDocente()){
			cout <<"__________5. Inscripcion a asignatura_______"<<endl;
		}else if(icau->isLogged() && icau->isDocente()){
			cout <<"__________5. Iniciar Clase__________________"<<endl;
		}
		if(icau->isLogged()){
			cout <<"__________6. Envio Mensaje_________________"<<endl;
		}		
		cout <<"__________7. Eliminar Asignatura____________"<<endl;
		if(icau->isLogged() && !icau->isDocente()){
			cout <<"__________8. Asiste en Vivo_________________"<<endl;
		}else if(icau->isLogged() && icau->isDocente()){
			cout <<"__________8. Listado de Clases______________"<<endl;
		}
		cout <<"__________9. Salir__________________________"<<endl;
		cout <<"____________________________________________"<<endl;
		cout <<"OPCION: ";
}

int main(){
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAltaAsignatura* icaa = fab->getICtrlAltaAsignatura();
	ICtrlAltaUsuario* icau = fab->getICtrlAltaUsuario();
	ICtrlInicioDeClase* icic = fab->getICtrlInicioDeClase();
	icaa->cargarAsignaturas();
	icau->cargarUsuarios();
	icic->cargarClases();
	int opcion;
	menu();
	cin >> opcion;
	while(opcion != 9){
		switch(opcion){
			case 1: iniciarSesion();  			   						  break;

			case 2: altaUsuario();    			   						  break;

			case 3: altaAsignatura();			   						  break;

			case 4: asignacionDocenteAsignatura(); 						  break;

			case 5: if(icau->isLogged() && !icau->isDocente()){inscripcionAsignatura();      
					}else if(icau->isLogged()){ inicioDeClase();}         break;

			case 6: if(icau->isLogged()){envioMensaje();}		   	  	  break;
			
			case 7: eliminarAsignatura(); 						          break;

			case 8: if(icau->isLogged() && !icau->isDocente()){asisteEnVivo();
					}else if(icau->isLogged()){ listadoDeClases();}       break;	
			
			default:
				cout << "OPCI??N INCORRECTA" << endl;
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
	cin.ignore(100,'\n');
	getline(cin,nombre);
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
		cin.ignore(100,'\n');
		getline(cin,instituto);
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
	cin.ignore(100,'\n');
	getline(cin,nombre);
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
	cout <<"_____________________________________________\n" <<endl;

	string codigo,email, confirmar;
	int seleccion;
	TipoRol rol;
	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAsignacionDocAsignatura* icada = fab->getICtrlAsignacionDocAsignatura();
	list<string> asignaturas = icada->listarAsignaturas();

	if(!asignaturas.empty()){
		bool existeEnLista=false;

		do{
			for(string s: asignaturas){
				cout << "Asignatura: " + s << endl;
			}
			cout << "\nSeleccionar asignatura para asignarle docente: ";
			cin >> codigo;
			cout << "\n";

			for(string s: asignaturas){
				if(s==codigo){
					existeEnLista=true;
				}
			}
			if(!existeEnLista){
				cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
			}

		}while(!existeEnLista);
		
		do{
			list<string> docentesSinAsignar = icada->docentesSinAsignar(codigo);
			if(!docentesSinAsignar.empty()){
				
				existeEnLista=false;

				do{
					for (string s: docentesSinAsignar){
						cout << "Email de docente: " + s << endl;
					}
					cout << "\nSeleccionar docente: ";
					cin >> email;

					for(string s: docentesSinAsignar){
						if(s==email){
							existeEnLista=true;
						}
					}

					if(!existeEnLista){
						cout << "Error al ingresar docente, intente de nuevo\n"<< endl;
					}

				}while(!existeEnLista);
				
				do{
					cout << "\nTeorico: 1	Practico: 2    Monitoreo: 3" << endl;
					cout << "\nSeleccionar rol: ";
					cin >> seleccion;
				}while(seleccion!=1 && seleccion!=2 && seleccion!=3);

				switch(seleccion){
					case 1: rol = Teorico; 		  break;
					case 2: rol = Practico; 	  break;
					case 3: rol = Monitoreo;	  break;
				}

				icada->seleccionarDocente(email,rol);

				do{
					string roles[3] = {"Teorico","Practico","Monitoreo"};
					cout << "\nDocente: " + email << endl ;
					cout << "Asignatura: " + codigo <<endl;
					cout << "Rol: " + roles[rol] <<endl;
					cout << "Desea agregar el docente a la asignatura? (s/n): ";
					cin >> confirmar;

					if(confirmar=="s"){
						icada->asignarDocente();
					}else if(confirmar!="n"){
						cout << "opcion incorrecta, intente de nuevo" << endl;
					}
				}while(confirmar!="s" && confirmar!="n");
			}else{
				cout<< "No hay docentes para asignar" << endl;
			}

			bool salir;
			do{
				salir=false;
				cout<< "\nDesea seguir agregando docentes? (s/n): ";
				cin >> confirmar;
				cout <<"\n";

				if(confirmar=="s" || confirmar=="n"){
					salir=true;
				}else{
					cout << "opcion incorrecta, intente de nuevo" << endl;
				}
			}while(!salir);

		}while(confirmar=="s");

	}else{
		cout << "\nNo hay asignaturas para agregarles docentes\n" << endl;
	}

}

////////////////////////////////////////////> Operaciones E <//////////////////////////////////////////////////

void inscripcionAsignatura(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"___________Inscripcion a asignatura__________"<< endl;
	cout <<"_____________________________________________\n" <<endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlInscripcionAsignatura* icia = fab->getICtrlInscripcionAsignatura();

	string confirmar, codigo;
	list<string> asignaturas = icia->asignaturaNoInscripto();
	if(!asignaturas.empty()){
		do{
			
			asignaturas = icia->asignaturaNoInscripto();			
			if(!asignaturas.empty()){
				bool existeEnLista=false;

				do{
					for(string s: asignaturas){
						cout << "Asignatura: " + s << endl;
					}
					cout << "\nSeleccionar la asignatura a la que se desea inscribir: ";
					cin >> codigo;
					cout << "\n";

					for(string s: asignaturas){
						if(s==codigo){
							existeEnLista=true;
						}
					}
					if(!existeEnLista){
						cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
					}

				}while(!existeEnLista);

				icia->seleccionarAsignatura(codigo);

				do{
					cout << "Confria la inscripcion a la asignatura " + codigo +"? (s/n): ";
					cin >> confirmar;

					if(confirmar=="s"){
						icia->darDeAltaInscripcion();
					}else if(confirmar!="n"){
						cout << "opcion incorrecta, intente de nuevo" << endl;
					}
				}while(confirmar!="s" && confirmar!="n");

				bool salir;
				do{
					salir=false;
					cout<< "\nDesea seguir inscribiendose a asignaturas? (s/n): ";
					cin >> confirmar;
					cout <<"\n";

					if(confirmar=="s" || confirmar=="n"){
						salir=true;
					}else{
						cout << "opcion incorrecta, intente de nuevo" << endl;
					}
				}while(!salir);

			}else{
				confirmar="n";
				cout << "No hay asignaturas disponibles para inscribirse" << endl;
			}
		}while(confirmar!="n");
	}else{
		cout << "No hay asignaturas disponibles para inscribirse" << endl;
	}
}

////////////////////////////////////////////> Operaciones F <//////////////////////////////////////////////////


void inicioDeClase(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"________________Iniciar Clase________________"<< endl;
	cout <<"_____________________________________________\n" <<endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlInicioDeClase* icidc = fab->getICtrlInicioDeClase();
	list<string> asignaturas = icidc->asignaturasAsignadas();
	string codigo, nombre, email,confirmar;
	bool salir;
		
	if(!asignaturas.empty()){
		bool existeEnLista=false;

		do{
			for(string s: asignaturas){
				cout << "Asignatura: " + s << endl;
			}
			cout << "\nSeleccionar la asignatura de la cual quiere iniciar clase: ";
			cin >> codigo;
			cout << "\n";

			for(string s: asignaturas){
				if(s==codigo){
					existeEnLista=true;
				}
			}
			if(!existeEnLista){
				cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
			}

		}while(!existeEnLista);

		cout << "Ingrese el nombre de la clase: ";		
		cin.ignore(100,'\n');
		getline(cin,nombre);
		cout << "\n";
		time_t fecha = time(0); tm* now = localtime(&fecha);
		DtFecha dtf = DtFecha(now->tm_mday,now->tm_mon+1,now->tm_year+1900);
		DtHora dth = DtHora(dtf,now->tm_hour,now->tm_min,now->tm_sec);
		DtIniciarClase dtic = DtIniciarClase(codigo,nombre,dth);
		
		bool monitoreo = icidc->seleccionarAsignatura(dtic);
		int habilitados=0;
		if(monitoreo){
			list<string> inscriptos = icidc->inscriptosAsignatura();
			list<string> inscriptos2 = icidc->inscriptosAsignatura();
			if(!inscriptos.empty()){
				do{				
					bool existeEnLista=false;
					if(!inscriptos2.empty()){
						do{
							inscriptos = icidc->inscriptosAsignatura();
							cout << "Estudiantes que puede habilitar: \n" << endl;
							for(string s: inscriptos){
								cout << "	Estudiante: " + s << endl;
							}
							cout << "\nSeleccionar el estudiante que desea habilitar: ";
							cin >> email;
							cout << "\n";

							for(string s: inscriptos){
								if(s==email){
									existeEnLista=true;
								}
							}
							if(!existeEnLista){
								cout << "Error al ingresar el estudiante, intente de nuevo\n" << endl;
							}
						}while(!existeEnLista);
						icidc->habilitarEstudiante(email);
						habilitados++;

						do{
							salir=false;
							cout<< "Desea seguir habilitando estudiantes? (s/n): ";
							cin >> confirmar;
							cout <<"\n";

							if(confirmar=="s" || confirmar=="n"){
								salir=true;
							}else{
								cout << "opcion incorrecta, intente de nuevo" << endl;
							}						
						}while(!salir);
					inscriptos2 = icidc->inscriptosAsignatura();
					}else{
						confirmar="n";
					}

				}while(habilitados<15 && confirmar!="n");

				if(habilitados==15){
					cout << "Ha habilitado el maximo de 15 estudiantes" << endl;
				}
			}
		}
		if(habilitados!=0 || !monitoreo){
			list<string> inscriptos = icidc->inscriptosAsignatura();
			if(inscriptos.empty()){
				cout << "No hay mas estudiantes para habilitar\n" << endl;
			}
			DtIniciarClaseFull* dticf = icidc->datosIngresados(); // preguntar por cuales datos hay que mostrar y si la fecha es la del sistema
			cout << "id: " << dticf->getId() << endl;
			cout << "nombre: " + dticf->getNombre() << endl;
			cout << "Fecha de inicio: " << dticf->getFechaHora().getFecha() <<  " - " << dticf->getFechaHora().getHora() << ":"
				<< dticf->getFechaHora().getMinuto() << ":" << dticf->getFechaHora().getSegundo() << endl;
			DtIniciarMonitoreo* dtim = dynamic_cast<DtIniciarMonitoreo*>(dticf);
			if(dtim!=NULL){
				cout << "Habilitados: \n";
				for(string s: dtim->getHabilitados()){
					cout << "	Estudiante: " + s << endl;
				}
			}

			do{
				salir=false;
				cout<< "\nDesea iniciar la clase? (s/n): ";
				cin >> confirmar;
				cout <<"\n";

				if(confirmar=="s" || confirmar=="n"){
					salir=true;
				}else{
					cout << "opcion incorrecta, intente de nuevo" << endl;
				}
			}while(!salir);
			
			if(confirmar=="s"){
				icidc->iniciarClase();
			}
		}else{
			cout << "No hay estudiantes inscriptos en la asignatura" << endl;
		}
	}else{
		cout << "No se tiene ninguna asignatura asignada\n" << endl;
	}
}

////////////////////////////////////////////> Operaciones G <//////////////////////////////////////////////////

void eliminarAsignatura() {
	system("clear");
	cout << "_____________________________________________" << endl;
	cout << "_____________Eliminar Asignatura_____________" << endl;
	cout << "_____________________________________________\n" << endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlEliminarAsignatura* icea = fab->getICtrlEliminarAsignatura();
	list<string> asignaturas = icea->listarAsignaturas();
	
	string codigo;
	if (!asignaturas.empty()) {
		bool existeEnLista = false;
		do {
			for (string s : asignaturas) {
				cout << "Asignatura: " + s << endl;
			}
			cout << "\nSeleccionar la asignatura de la cual quiere eliminar: ";
			cin >> codigo;
			cout << "\n";

			for (string s : asignaturas) {
				if (s == codigo) {
					existeEnLista = true;
				}
			}
			if (!existeEnLista) {
				cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
			}

		} while (!existeEnLista);


		icea->seleccionarAsignatura(codigo);
		bool salir;
		string confirmar;
		do {
			salir = false;
			cout << "Desea eliminar la asignatura? (s/n): ";
			cin >> confirmar;
			cout << "\n";

			if (confirmar == "s" || confirmar == "n") {
				salir = true;
			}
			else {
				cout << "opcion incorrecta, intente de nuevo" << endl;
			}
		} while (!salir);

		if (confirmar == "s") {
			icea->eliminarAsignatura();
		}
	}
	else {
		cout << "\nNo existen asignaturas en el sistema" << endl;
	}
}

////////////////////////////////////////////> Operaciones H <//////////////////////////////////////////////////

void envioMensaje() {
	system("clear");
	cout << "_____________________________________________" << endl;
	cout << "_____________Envio Mensaje_____________" << endl;
	cout << "_____________________________________________\n" << endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlEnvioMensaje* icem = fab->getICtrlEnvioMensaje();
	list<int> clases = icem->claseOnlineAsistiendo();

	int id;
	if(!clases.empty()){
		bool existeEnLista=false;

		do{
			for(int c: clases){
				cout << "Clase: " << c << endl;
			}
			cout << "\nSeleccionar la clase a la cual esta participando y quiere mandar un mensaje: ";
			cin >> id;
			cout << "\n";

			for(int c: clases){
				if(c==id){
					existeEnLista=true;
				}
			}
			if(!existeEnLista){
				cout << "Error al ingresar clase, intente de nuevo.\n" << endl;
			}

		}while(!existeEnLista);

		list<DtParticipacion*> dtPs = icem->seleccionarClase(id);
		for(DtParticipacion* dtP : dtPs){
			dtP->imprimirParticipacion();		
		}
		
		bool salir;
		string confirmar;
		do {
			salir = false;
			cout << "\nEl mensaje enviado es respuesta de otro mensaje? (s/n): " ;
			cin >> confirmar;

			if (confirmar == "s" || confirmar == "n") {
				salir = true;
			}
			else {
				cout << "opcion incorrecta, intente de nuevo" << endl;
			}
		} while (!salir);

		if (confirmar == "s") {
			if(!dtPs.empty()){
				int idR;
				bool existeEnLista=false;
				cout << "\nIngrese el id del mensaje a responder: " ;
				cin >> idR;
				for(DtParticipacion* dtP : dtPs){
					if(idR==dtP->getId())
						existeEnLista=true;		
				}
				if(existeEnLista){
					icem->responder(idR);
				}
			}
		}

		if((confirmar=="s" && existeEnLista) || confirmar=="n"){
			string texto;
			cout << "\nIngrese el texto del mensaje: " ;
			cin.ignore(100,'\n');
			getline(cin,texto);
			icem->ingresarTexto(texto);

			do {
				salir = false;
				cout << "\nDesea enviar el mensaje? (s/n): " ;
				cin >> confirmar;

				if (confirmar == "s" || confirmar == "n") {
					salir = true;
				}
				else {
					cout << "opcion incorrecta, intente de nuevo" << endl;
				}
			} while (!salir);

			if (confirmar == "s") {
				icem->enviarMensaje();
				cout << "El mensaje se envio con exito" << endl;
			}
		}else{
			if(dtPs.empty()){
				cout << "No hay mensajes los cuales responder" << endl;
			}else{
				cout << "El id ingresado no pertece a ningun mensaje" << endl;
			}
		}
	}else{
		cout << "No se encuentra participando en ninguna clase en vivo.\n" << endl;
	}
}

////////////////////////////////////////////> Operaciones I <//////////////////////////////////////////////////

void asisteEnVivo(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"________________Asiste en Vivo_______________"<< endl;
	cout <<"_____________________________________________\n" <<endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlAsisteEnVivo* icav = fab->getICtrlAsisteEnVivo();

	list<string> asignaturas = icav->asignaturasInscripto();
	
	string codigo;
	if (!asignaturas.empty()) {
		bool existeEnLista = false;
		do {
			for (string s : asignaturas) {
				cout << "Asignatura: " + s << endl;
			}
			cout << "\nSeleccionar la asignatura de la que desea ver las clases en vivo: ";
			cin >> codigo;
			cout << "\n";

			for (string s : asignaturas) {
				if (s == codigo) {
					existeEnLista = true;
				}
			}
			if (!existeEnLista) {
				cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
			}

		}while (!existeEnLista);

		list<int> clases = icav->clasesOnlineDisponibles(codigo);
		int id;
		existeEnLista = false;
		
		do{
			for (int c : clases) {
				cout << "Clase: " << c << endl;
			}
			cout << "\nSeleccionar la Clase a la cual desea asistir: ";
			cin >> id;

			for (int c : clases) {
				if (c == id) {
					existeEnLista = true;
				}
			}
			if (!existeEnLista) {
				cout << "Error al ingresar clase, intente de nuevo\n" << endl;
			}

		}while (!existeEnLista);

		DtAsistir dtAsistir = icav->selectClase(id);
		
		bool salir;
		string confirmar;
		do {
			salir = false;

			cout << "\nCodigo Asignatura: " << dtAsistir.getCodigo() << endl;
			cout << "Id Clase: " << dtAsistir.getId() << endl;

			cout << "\nDesea asistir a la clase en vivo? (s/n): " ;
			cin >> confirmar;
			cout << "\n";

			if (confirmar == "s" || confirmar == "n") {
				salir = true;
			}
			else {
				cout << "opcion incorrecta, intente de nuevo" << endl;
			}
		} while (!salir);

		if (confirmar == "s") {
			icav->asistirClaseEnVivo();
			cout << "Estas asistiendo a la clase " << id << endl;
		}
	}else{
		cout << "\nNo existen asignaturas a las cuales este inscripto" << endl;
	}
}

////////////////////////////////////////////> Operaciones J <//////////////////////////////////////////////////

void listadoDeClases(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"________________Listado de Clases____________"<< endl;
	cout <<"_____________________________________________\n" <<endl;

	Fabrica* fab = Fabrica::getInstancia();
	ICtrlListadoDeClases* iclc = fab->getICtrlListadoDeClases();
	list<string> asignaturas = iclc->asignaturasAsignadas();
	string codigo;
	bool salir;
		
	if(!asignaturas.empty()){
		bool existeEnLista=false;

		do{
			for(string s: asignaturas){
				cout << "Asignatura: " + s << endl;
			}
			cout << "\nSeleccionar la asignatura de la cual quiere listar las clases: ";
			cin >> codigo;
			cout << "\n";

			for(string s: asignaturas){
				if(s==codigo){
					existeEnLista=true;
				}
			}
			if(!existeEnLista){
				cout << "Error al ingresar asignatura, intente de nuevo\n" << endl;
			}

		}while(!existeEnLista);

		list<DtInfoClase*> dtInfoClases = iclc->seleccionarAsignatura(codigo);
		for(DtInfoClase* dti : dtInfoClases){
			cout << "Id: " << dti->getId() << " - Nombre: " << dti->getNombre() << endl;
			cout << "Docentes: ";
			int size = 1;
			for(string s : dti->getDocentes()){
				if(dti->getDocentes().size()!=size){
					cout << s << ", ";
					size++;
				}else{
					cout << s << endl;
				}
			}
			DtInfoMonitoreo* dtm = dynamic_cast<DtInfoMonitoreo*>(dti);
			if(dtm!=NULL){
				cout << "Estudiantes habilitados: ";
				size = 1;
				for(string e : dtm->getEstudiantes()){
					if(dtm->getEstudiantes().size()!=size){
						cout << e << ", ";
						size++;
					}else{
						cout << e << endl;
					}				
				}
			}else{
				DtInfoTeorico* dtt = dynamic_cast<DtInfoTeorico*>(dti);
				if (dtt!=NULL){
					cout << "Cantidad de asistencia: " << dtt->getCantAsisten() << endl;
				}
			}
		}
		cout << "\n";
	}else{
		cout << "No se tiene ninguna asignatura asignada\n" << endl;
	}
}
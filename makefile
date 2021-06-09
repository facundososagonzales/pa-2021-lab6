OTH=main.o Fabrica.o
CLASS=class/Asignatura.o class/AsisteDiferido.o class/AsisteEnVivo.o class/Clase.o class/Docente.o class/Estudiante.o class/Monitoreo.o class/Participacion.o class/Practico.o class/Rol.o class/Sesion.o class/Teorico.o class/Usuario.o
DATATYPE=dataType/DtIniciarClase.o dataType/DtAsignatura.o dataType/DtAsistir.o dataType/DtClaseAsistencia.o dataType/DtDictadoAsignatura.o dataType/DtUsuario.o dataType/DtDocente.o dataType/DtEstudiante.o dataType/DtFecha.o dataType/DtHora.o dataType/DtIniciarClaseFull.o dataType/DtIniciarMonitoreo.o dataType/DtInstanciaClase.o dataType/DtParticipacion.o dataType/DtTime.o dataType/Log.o
CTRL=ctrl/CtrlAltaUsuario.o ctrl/CtrlAltaAsignatura.o
HANDLER=handler/HandlerUsuario.o
EXEC=exe
OBJ=$(OTH) $(CLASS) $(DATATYPE) $(CTRL) $(HANDLER)

main: $(OBJ) 
	g++ $(OBJ) -o $(EXEC)
	find . -name '*.o' -delete
	./$(EXEC)

class/Asignatura.o: class/Asignatura.cpp
class/AsisteDiferido.o: class/AsisteDiferido.cpp
class/AsisteEnVivo.o: class/AsisteEnVivo.cpp
class/Clase.o: class/Clase.cpp
class/Docente.o: class/Docente.cpp
class/Estudiante.o: class/Estudiante.cpp
class/Monitoreo.o: class/Monitoreo.cpp
class/Participacion.o: class/Participacion.cpp
class/Practico.o: class/Practico.cpp
class/Rol.o: class/Rol.cpp
class/Sesion.o: class/Sesion.cpp
class/Teorico.o: class/Teorico.cpp
class/Usuario.o: class/Usuario.cpp
dataType/DtIniciarClase.o: dataType/DtIniciarClase.cpp
dataType/DtAsignatura.o: dataType/DtAsignatura.cpp
dataType/DtAsistir.o: dataType/DtAsistir.cpp
dataType/DtClaseAsistencia.o: dataType/DtClaseAsistencia.cpp
dataType/DtDictadoAsignatura.o: dataType/DtDictadoAsignatura.cpp
dataType/DtUsuario.o: dataType/DtUsuario.cpp
dataType/DtDocente.o: dataType/DtDocente.cpp
dataType/DtEstudiante.o: dataType/DtEstudiante.cpp 
dataType/DtFecha.o: dataType/DtFecha.cpp
dataType/DtHora.o: dataType/DtHora.cpp
dataType/DtIniciarClaseFull.o: dataType/DtIniciarClaseFull.cpp
dataType/DtIniciarMonitoreo.o: dataType/DtIniciarMonitoreo.cpp 
dataType/DtInstanciaClase.o: dataType/DtInstanciaClase.cpp
dataType/DtParticipacion.o: dataType/DtParticipacion.cpp
dataType/DtTime.o: dataType/DtTime.cpp
dataType/Log.o: dataType/Log.cpp
ctrl/CtrlAltaUsuario.o: ctrl/CtrlAltaUsuario.cpp
ctrl/CtrlAltaAsignatura.o: ctrl/CtrlAltaAsignatura.cpp
handler/HandlerUsuario.o: handler/HandlerUsuario.cpp

Fabrica.o: Fabrica.cpp

main.o: main.cpp

clean:
	rm -rf $(EXEC)
	find . -name '*.o' -delete
	clear
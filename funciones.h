#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "operador.h"
#include "obraSocial.h"
#include "especialidades.h"
#include "Medico.h"
#include "pacientes.h"
#include "HistoriaClinica.h"
#include "horarios.h"
#include "turnos.h"



class Funciones
{
  public:


  void MostrarFecha();
  void borrarPantalla();
  void gotoxy(short ,short );
  void textcolor(short, short);
  bool soloLetras(char *);
  char Mayusculas(char *);
  char Minusculas(char *);

  ///Especialidades///

  void MostrarEsp(Especialidad);
  bool MostrarEspXid();
  bool MEsp();
  void ModificarEsp();
  int BuscarEspPos(char *);
  int BuscarEspPosInt(int);
  int BuscarLineaPos(int);
  bool ListarEsp();

///OPERADORES///

    bool ListarRecepcionistas();
    void MostrarRecepcionista(Recepcionista);
    bool MostrarRecepcionistaXDNI();
    bool MNombreR();
    bool MApellidoR();
    bool MTurnoR();
    void ModificarRecepcionista();
    int BuscarDNI(int);
    int BuscarRecepcionistaPos(char *);
    int BuscarRecepcionistaPosInt(int);

    ///MEDICOS///
    bool ListarMedicos();
    void MostrarMedico(Medico);
    bool MostrarMedicoXDNI();
    bool BorrarMedico();
    bool MNombreM();
    bool MApellidoM();
    bool MCostoM();
    bool MDuracionM();
    void ModificarMedico();
    int BuscarMedicoPos(char *);
    int BuscarMedicoPosInt(int);
    void ListarTodasEspecialidades();
    void ListarMedicosconEsp(int);
    bool MostrarMedicoXEsp();
    int ListarHorariosMedicos(int);
    int buscardia(int);



    ///PACIENTES///
    bool ListarPAC();
    void MostrarPAC(Paciente);
    bool MostrarPACXDNI();
    bool BorrarPAC();
    bool MNombreP();
    bool MApellidoP();
    bool MCostoP();
    bool MDuracionP();
    void ModificarPAC();
    int BuscarPacientePos(char *);
    int BuscarPacientePosInt(int);
    void ListarTodasOS();
    bool MostrarPACXOS();
    void ListarNombrePAC(int);
    int BuscarDNIPAC(int);


    ///OBRA SOCIAL///

  void MostrarOS(ObraSocial);
  bool MostrarOSXid();
  bool MOS();
  void ModificarOS();
  int BuscarOSPos(char *);
  int BuscarOSPosInt(int);
  bool ListarOS();


     ///HISTORIA CLINICA///

  void MostrarHC(HistoriaClinica);
  bool MostrarHCXDNI();
  bool MHC();
  void ModificarHC();
  int BuscarHCPos(char *);
  int BuscarHCPosInt(int);
  bool ListarHC();

  ///HORARIO///

  void MostrarHO(Horario);
  bool MostrarHOXDNI();
  bool MHO();
  void ModificarHO();
  int BuscarHOPos(char *);
  int BuscarHOPosInt(int);
  bool ListarHO();
int BuscarHo(int , int);


  ///TURNO///

  void MostrarTurnos(Turnos);
  bool MostrarTurnosXDNI();
  bool MTurnos();
  void ModificarTurnos();
  int BuscarTurnosPos(char *);
  int BuscarTurnosPosInt(int);
  bool ListarTurnos();
  void MostrarDiasMes();
  int CalculaDia();
  void MostrarHDisp(int, int);
  bool Existe (int, int, int);

  //private:
Fecha fechahoy;


};


#endif // FUNCIONES_H_INCLUDED

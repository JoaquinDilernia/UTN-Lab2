#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#include "fecha.h"

class Turnos
{
  public:
    Turnos();

    ///Sets y Gets

    int GetIdTurno() { return idTurno; }
    void SetIdTurno(int val) { idTurno = val;}
    int GetIdMedico() { return idMedico; }
    void SetIdMedico(int val) { idMedico = val;}
    int GetHorario() { return Hora; }
    void SetHorario(int val) { Hora = val;}
    int GetDni() { return dni; }
    void SetDni(int val) { dni = val;}


    bool GetEstado() { return estado; }
    void SetEstado(int val) { estado = val;}


    bool AgregarTurno();
    int NuevoIdTurno();
    int GuardarTurno(int);
    bool CargarTurno();
    bool LeerTurno(int);
    bool BorrarLogicoTurno();
    Fecha fechaTurno;


  protected:

  private:

    int idTurno;
    int idMedico;
    int dni;
    int Hora;
    bool estado;


};




#endif // TURNOS_H_INCLUDED

#ifndef HISTORIACLINICA_H_INCLUDED
#define HISTORIACLINICA_H_INCLUDED
#include "fecha.h"

class HistoriaClinica
{
  public:
    HistoriaClinica();

    ///Sets y Gets

    int GetIdHistoriaClinica() { return idHC; }
    void SetIdHistoriaClinica(int val) { idHC = val;}
        int GetIdMedico() { return idMedico; }
    void SetIdMedico(int val) { idMedico = val;}
    int GetDni() { return DNI; }
    void SetDni(int val) { DNI = val;}
    char * GetObservacion() { return Observacion; }
    void SetObservacion(char * val) { strcpy (Observacion, val); }
    bool GetEstado() { return estado; }
    void SetEstado(int val) { estado = val;}


    bool AgregarHC();
    int NuevoIdHC();
    int GuardarHC(int);
    bool CargarHC();
    bool LeerHC(int);
    bool BorrarLogicoHC();
    Fecha fechaConsulta;


  protected:

  private:

    int idHC;
    int DNI;
    int idMedico;
    char Observacion[50];
    bool estado;

};




#endif // HISTORIACLINICA_H_INCLUDED

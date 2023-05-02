#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED


class Paciente
{
  public:
    Paciente();

    ///Sets y Gets

    int GetIdObraSocial() { return IdObraSocial; }
    void SetIdObraSocial(int val) { IdObraSocial = val;}
    char * GetNombre() { return nombre; }
    void SetNombre(char * val) { strcpy (nombre, val); }
    char * GetApellido() { return apellido; }
    void SetApellido (char * val) { strcpy (apellido,val); }
    int GetDNI() { return DNI; }
    void SetDNI(int val) { DNI= val; }
    int  GetEstado() { return Estado; }
    void SetEstado(int val) { Estado = val; }


    bool AgregarPAC();
    int GuardarPAC(int);
    bool CargarPAC();
    int Existe(int);
   bool LeerPAC(int);
    bool BorrarLogicoPAC();


  protected:

  private:

    int DNI;
    char nombre [30];
    char apellido [30];
    int IdObraSocial;
    bool Estado;
};


#endif // PACIENTES_H_INCLUDED

#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED
class Medico
{
  public:
    Medico();

    ///Sets y Gets

    int GetIdMedico() { return idMedico; }
    void SetIdMedico(int val) { idMedico = val;}
    char * GetNombre() { return nombre; }
    void SetNombre(char * val) { strcpy (nombre, val); }
    char * GetApellido() { return apellido; }
    void SetApellido (char * val) { strcpy (apellido,val); }
    int  GetEstado() { return estado; }
    void SetEstado(int val) { estado = val; }
    char  GetGenero() { return genero; }
    void SetGenero(char val) { genero = val; }
     int  GetCosto() { return costo; }
    void SetCosto(int val) { costo = val; }
         int  GetDuracion() { return duracion; }
    void SetDuracion(int val) { duracion = val; }


    bool AgregarMedico();
    int LeerMedico();
    int NuevoIdMed();
    bool ListarMedico();
    void MostrarMedico();
    int BorrarLogicoMedico();
    int GuardarMedico(int);
    bool CargarMedico();
    bool MostrarMedicoXid();
    bool MNombreM();
    bool MApellidoM();
    bool MTurnoR();
    void ModificarMedico();

  protected:

  private:

    int idMedico;
    char nombre [30];
    char apellido [30];
    int idEsp;
    char genero;
    int costo;
    int duracion;
    int estado;

};


#endif // MEDICOS_H_INCLUDED

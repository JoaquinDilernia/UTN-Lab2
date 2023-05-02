#ifndef MEDICO_H_INCLUDED
#define MEDICO_H_INCLUDED


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

    char GetGenero() { return genero; }
    void SetGenero(int val) { genero = val; }
    int GetIdEsp() { return idEsp; }
    void SetIdEsp(int val) { idEsp = val; }


    bool AgregarMedico();
    int NuevoIdMed();

    int GuardarMedico(int);
    bool CargarMedico();

    bool LeerMedico(int);
    bool BorrarLogicoMedico();
    int Existe(int);


  protected:

  private:

    int idMedico;
    char nombre [30];
    char apellido [30];
    char genero;
    int idEsp;
    int estado;
};



#endif // MEDICO_H_INCLUDED

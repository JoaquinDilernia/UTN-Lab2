#ifndef ESPECIALIDADES_H_INCLUDED
#define ESPECIALIDADES_H_INCLUDED

class Especialidad
{
  public:
    Especialidad();

    ///Sets y Gets

    int GetIdEspecialidad() { return idEspecialidad; }
    void SetIdEspecialidad(int val) { idEspecialidad = val;}
    char * GetEspecialidad() { return especialidad; }
    void SetEspecialidad(char * val) { strcpy (especialidad, val); }
    int  GetEstado() { return estado; }
    void SetEstado(int val) { estado = val; }


    bool AgregarEsp();
    int NuevoIdEsp();
    int GuardarEsp(int);
    bool CargarEsp();
    bool BorrarEsp();
    void LeerEsp(int);
    bool BorrarLogicoEsp();
    void LeerEspecialidad(int);
    int Existe(int);

  protected:

  private:

    int idEspecialidad;
    char especialidad [30];
    bool estado;

};

#endif // ESPECIALIDADES_H_INCLUDED

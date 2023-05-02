#ifndef OBRASOCIAL_H_INCLUDED
#define OBRASOCIAL_H_INCLUDED


class ObraSocial
{
  public:
    ObraSocial();

    ///Sets y Gets

    int GetIdOS() { return idOS; }
    void SetIdOS(int val) { idOS = val;}
    char * GetNombre() { return Nombre; }
    void SetNombre(char * val) { strcpy (Nombre, val); }
    int  GetEstado() { return estado; }
    void SetEstado(int val) { estado = val; }


    bool AgregarOS();
    int NuevoIdOS();
    int GuardarOS(int);
    bool CargarOS();
    bool BorrarOS();
    bool LeerOS(int);
    bool BorrarLogicoOS();
    bool LeerObraSocial(int);
    int ExisteOS(int);

  protected:

  private:

    int idOS;
    char Nombre [30];
    bool estado;

};



#endif // OBRASOCIAL_H_INCLUDED

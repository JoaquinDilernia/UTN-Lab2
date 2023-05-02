#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED

class Recepcionista
{
  public:
    Recepcionista();

    ///Sets y Gets

    int GetIdRecep() { return idRecep; }
    void SetIdRecep(int val) { idRecep = val;}
    char * GetNombre() { return nombre; }
    void SetNombre(char * val) { strcpy (nombre, val); }
    char * GetApellido() { return apellido; }
    void SetApellido (char * val) { strcpy (apellido,val); }
    int GetTurno() { return turno; }
    void SetTurno(int val) { turno = val; }
    int  GetEstado() { return estado; }
    void SetEstado(int val) { estado = val; }
    int  GetDoc() { return doc; }
    void SetDoc(int val) { doc = val; }

    bool AgregarRecepcionista();
    int LeerRecepc();
    int NuevoIdRec();
    int GuardarRecepcionista(int);
    bool CargarRecepcionista();
    bool BorrarRecepcionista();
    bool  LeerRecepcionista(int);
      bool BorrarLogicoRecepcionista();



  protected:

  private:

    int idRecep;
    char nombre [30];
    char apellido [30];
    int turno;
    int estado;
    int doc;
};

#endif // OPERADOR_H_INCLUDED

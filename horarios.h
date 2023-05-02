#ifndef HORARIOS_H_INCLUDED
#define HORARIOS_H_INCLUDED

class Horario
{
  public:
    Horario();

    ///Sets y Gets

    int GetIdHO() { return idHO; }
    void SetIdHO(int val) { idHO = val;}
    int GetIdMedico() { return idMedico; }
    void SetIdMedico(int val) { idMedico = val;}
    int GetHOI() { return HOI; }
    void SetHOI(int val) { HOI = val;}
    int GetDia() { return dia; }
    void SetDia(int val) { dia = val;}
    int GetHOF() { return HOF; }
    void SetHOF(int val) {HOF = val; }
    bool GetEstado() { return estado; }
    void SetEstado(int val) { estado = val;}


    bool AgregarHO();
    int NuevoIdHO();
    int GuardarHO(int);
    bool CargarHO();
    bool LeerHO(int);
    bool BorrarLogicoHO();
    bool Existe(int,int);



  protected:

  private:

    int idHO;
    int idMedico;
    int dia;
    int HOI;
    int HOF;
    bool estado;

};



#endif // HORARIOS_H_INCLUDED

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>

class Fecha
{
private:

    int Dia, Mes, Anio;

public:

     ///Constuctor inicializa la fecha a 0
     Fecha()

    {
      Dia= 0;
      Mes=0;
      Anio=0;
    }

    int validarFecha(int dia, int mes, int anio);

    void setDiaS(int d)
    {
          Dia=d;
    }

    void setMesS(int m)
    {
          Mes=m;
    }

    void setAnioS(int a)
    {
          Anio=a;
    }

    int getDia()
    {
        return Dia;
    }
    int getMes()
    {
        return Mes;
    }
    int getAnio()
    {
        return Anio;
    }

    void MostrarFecha();
    int cmpFechas(Fecha fecha2);
    void MostrarDiaTexto(int);

};


#endif // FECHA_H_INCLUDED

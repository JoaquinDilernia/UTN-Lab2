
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "fecha.h"


extern Fecha GfechaSistema;
void Fecha::MostrarFecha()
{
   cout<<Dia<<"/"<<Mes<<"/"<<Anio<<endl;
}



int cmpFechas(struct Fecha fecha1, struct Fecha fecha2);

int Fecha::validarFecha(int dia, int mes, int anio)
{
    if (anio%4==0)
        if (mes==2 && dia<30)
        {
            Anio=anio;
            Mes =mes;
            Dia=dia;
            return 1;
        }
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia<32)
        {
            Anio=anio;
            Mes =mes;
            Dia=dia;
            return 1;
        }
        break;
    case 2:
        if (dia<29)
        {
            Anio=anio;
            Mes =mes;
            Dia=dia;
            return 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia<31)
        {
            Anio=anio;
            Mes =mes;
            Dia=dia;
            return 1;
        }
        break;
    };
    return 0;


}

int Fecha::cmpFechas(Fecha fecha2)
{
    if(fecha2.Anio > Anio)
    {
        return 1;
    }
    else if (fecha2.Anio < Anio)
    {
        return -1;
    }
    else
    {
        if (fecha2.Mes > Mes)
            return 1;
        else if (fecha2.Mes < Mes)
            return -1;
        else
        {
            if(fecha2.Dia > Dia)
                return 1;
            else if(fecha2.Dia < Dia)
                return -1;
            else
                return 0;

        }
    }
}

void Fecha::MostrarDiaTexto(int d)
{



  char mdia[6][10];
  strcpy(mdia[1],"Lunes");
  strcpy(mdia[2],"Martes");
  strcpy(mdia[3],"Miercoles");
  strcpy(mdia[4],"Jueves");
  strcpy(mdia[5],"Viernes");
  strcpy(mdia[6],"Sábado");

  cout<<mdia[d];



  }





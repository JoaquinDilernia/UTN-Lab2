#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "turnos.h"
#include "funciones.h"
#include "menu.h"


Turnos::Turnos()
{
  //ctor
}


bool Turnos::CargarTurno()
{
    Funciones fun;
    Fecha fec;
    Menu aux;
    Medico med;
    Paciente rec;
Funciones fechahoy;
    Horario esp;

    int bdia;
    int nroDia = 0;
    int cantd=0;
    int dif = 0;
    int mes = 0;
    int v= 0;
    int dia = 0;
    int opc ;
    int idEsp;
    int id;
   int hora;
   int costo;
    int doc;
    int d, m, a;
    int ex;
    int ex1;
    fun.MostrarFecha();
    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(40,3);
    cout << "____________________________ " << endl;
    id=NuevoIdTurno();
    SetIdTurno(id);

    do{

       cout << "INGRESE EL DNI DEL PACIENTE "<< endl;
       cin >> doc;
       ex1 = rec.Existe(doc);
    }while(ex1 == -1);
    fun.ListarNombrePAC(doc);
     SetDni(doc);
    cout << "INGRESE LA ESPECIALIDAD DEL MEDICO: " << endl;
    fun.ListarTodasEspecialidades();
    cin >> idEsp;
    fun.ListarMedicosconEsp(idEsp);

    do{
       cout << "INGRESE EL ID DEL MEDICO "<< endl;
       cin >> id;
       ex = med.Existe(id);
    }while(ex == -1);

    SetIdMedico(id);

do {
    system("cls");

    fun.MostrarFecha();
cout << endl;
cout << endl;

cantd = fun.ListarHorariosMedicos(id);
cout << endl;
cout << "INGRESE OPCION : "<< endl;
cin >> opc;
}while(opc < 1 or opc > 4);
switch(opc)
{

case 1:


 nroDia=fun.CalculaDia();
 bdia = fun.buscardia(id);
 dif = nroDia - bdia;

if(dif > 0)
    {

    v = 7 - dif;
    dia += fun.fechahoy.getDia();
    dia += v;


    }
    else
    {
    dif = dif * -1;
    dia += fun.fechahoy.getDia();

    dia += dif;
    }


     if(cantd == 3)
    {
                            if(dia > 28)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 29 + 7;
                            }
                        }

                        if(cantd == 1)
                        {
                            if(dia > 31)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 31 + 7;
                            }
                        }

                        if(cantd == 2)
                        {
                            if(dia > 30)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 30 + 7;
                            }
                        }



    break;

case 2:
dia = dia + 7;
 nroDia=fun.CalculaDia();
 bdia = fun.buscardia(id);
 dif = nroDia - bdia;

if(dif > 0)
    {

    v = 7 - dif;
    dia += fun.fechahoy.getDia();
    dia += v;


    }
    else
    {
    dif = dif * -1;
    dia += fun.fechahoy.getDia();

    dia += dif;
    }


     if(cantd == 3)
    {
                            if(dia > 28)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 29 + 7;
                            }
                        }

                        if(cantd == 1)
                        {
                            if(dia > 31)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 31 + 7;
                            }
                        }

                        if(cantd == 2)
                        {
                            if(dia > 30)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 30 + 7;
                            }
                        }


    break;

case 3:

     dia = dia + 14;
 nroDia=fun.CalculaDia();
 bdia = fun.buscardia(id);
 dif = nroDia - bdia;

if(dif > 0)
    {

    v = 7 - dif;
    dia += fun.fechahoy.getDia();
    dia += v;


    }
    else
    {
    dif = dif * -1;
    dia += fun.fechahoy.getDia();

    dia += dif;
    }


     if(cantd == 3)
    {
                            if(dia > 28)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 29 + 7;
                            }
                        }

                        if(cantd == 1)
                        {
                            if(dia > 31)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 31 + 7;
                            }
                        }

                        if(cantd == 2)
                        {
                            if(dia > 30)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 30 + 7;
                            }
                        }


    break;

case 4:


     dia = dia + 21;
 nroDia=fun.CalculaDia();
 bdia = fun.buscardia(id);
 dif = nroDia - bdia;

if(dif > 0)
    {

    v = 7 - dif;
    dia += fun.fechahoy.getDia();
    dia += v;


    }
    else
    {
    dif = dif * -1;
    dia += fun.fechahoy.getDia();

    dia += dif;
    }


     if(cantd == 3)
    {
                            if(dia > 28)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 29 + 7;
                            }
                        }

                        if(cantd == 1)
                        {
                            if(dia > 31)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 31 + 7;
                            }
                        }

                        if(cantd == 2)
                        {
                            if(dia > 30)
                            {
                                  mes =1;
                                dia = dia-7;
                                dia = dia - 30 + 7;
                            }
                        }



    break;


}

fechaTurno.setDiaS(dia);
fechaTurno.setMesS(fun.fechahoy.getMes()+mes);
fechaTurno.setAnioS(fun.fechahoy.getAnio());

fun.MostrarHDisp(dia , id);
    cout << endl;
    cout << "HORA: " << endl;
    cin>> hora;
    SetHorario(hora);



    SetEstado(1);
   bool leyo= AgregarTurno();

    return true ;
}

bool Turnos::AgregarTurno()
{
    FILE *p;
    p = fopen("Turnos.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return true;

    }
}


int Turnos::NuevoIdTurno()
{

    FILE *p;
    p = fopen("Turnos.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);
        fread(this, sizeof *this, 1, p);
        fclose(p);
        return  idTurno+1;
    }
}



int Turnos::GuardarTurno(int pos)
{

    FILE *p;
    //pos =fun.BuscarTurnoPosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("Turnos.dat", "rb+");
        fseek(p, pos*sizeof(Turnos),0);
    }

    else
    {
        p = fopen("Turnos.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Turnos), 1, p);
        fclose(p);
        return true;

    }
}


bool Turnos::LeerTurno(int pos)
{
    FILE *p;
    Turnos aux;
    p = fopen("Turnos.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Turnos),0);
   bool leyo=  fread(this,sizeof(Turnos), 1, p);
    fclose(p);
    return leyo;
}


bool Turnos::BorrarLogicoTurno()
{
    int id;
    int pos;
    char opc;
    Funciones fun;

    fun.borrarPantalla();
    cout << "INGRESE ID DEL TURNO: ";
    cin >>  id;

    pos = fun.BuscarTurnosPosInt(id);

    if(pos >= 0)
    {

        LeerTurno(pos);
        fun.borrarPantalla();

        do
        {
            cout << "DESEA ELIMINAR ESTE REGISTRO (S/N): ";
            cin >> opc;
            opc = toupper(opc);
        }
        while(opc != 'S' && opc != 'N');
        if (opc == 'S')
        {
            SetEstado(0);

          GuardarTurno(pos);
            return true;
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


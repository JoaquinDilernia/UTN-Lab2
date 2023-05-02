#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "horarios.h"
#include "funciones.h"
#include "menu.h"
#include "fecha.h"


Horario::Horario()
{
  //ctor
}

bool Horario::CargarHO()
{
    Funciones fun;
    Menu aux;
    Medico med;



    int id,idM,d,opc,HI,HF,idM1;
    bool ex;
      int v = -5;

    fun.borrarPantalla();
    fun.gotoxy(30,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "____________________________ " << endl;

    id=NuevoIdHO();
    SetIdHO(id);

    fun.ListarMedicosconEsp(0);

    do{
       cout << "INGRESE EL ID DEL MEDICO "<< endl;
       cin >> idM;
        idM1=idM;
        ex = med.Existe(idM);
    }while(ex == -1);

    SetIdMedico(idM);

    cout << "INGRESE NUMERO DE DIA: "<< endl;
do{
        cout << endl;
        cout << "1 -Lunes- " << endl;
        cout << "2 -Martes- " << endl;
        cout << "3 -Miercoles- " << endl;
        cout << "4 -Jueves- " << endl;
        cout << "5 -Viernes- " << endl;
        cout << "6 -Sabado- " << endl;
        cout << endl;

        cin >> d;

      ex = Existe(d, idM);
}while( d<0 or d>6);

        if(ex==false)
        {
            cout << "EL MEDICO SELECCIONADO YA TIENE SUS HORARIOS ASIGNADOS";
            cout << endl;
            system("pause");
            aux.menuHO();
                 }
     SetDia(d);
     id=NuevoIdHO();
     SetIdHO(id);
     SetIdMedico(idM1);
     SetDia(d);
     do{

     cout << endl;
     cout << "__________________________________________________________";
     cout << endl;
     cout << "EL MAXIMO DE HORAS TRABAJADA NO PUEDE EXCEDER LAS 5 HORAS";
     cout << endl;
     cout << "__________________________________________________________";
     cout << endl;
     cout << "INGRESE EL HORARIO DE INICIO (A PARTIR DE LAS 8): "<< endl;
    cin >> HI;



        cout << "INGRESE EL HORARIO DE FIN (HASTA LAS 20): "<< endl;
       cin >> HF;

       }while(HI >= HF or HI < 8 or HI > 20  or HF < 8 or HF > 20 or HI - HF != v);
       SetHOF(HF);
       SetHOI(HI);

    SetEstado(1);


    bool leyo=AgregarHO();
    return leyo;
}



bool Horario::AgregarHO()
{
    FILE *p;
    p = fopen("Horarios.dat", "ab");
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


int Horario::NuevoIdHO()
{

    FILE *p;
    p = fopen("Horarios.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);
        fread(this, sizeof *this, 1, p);
        fclose(p);
        return  idHO+1;
    }
}



int Horario::GuardarHO(int pos)
{

    FILE *p;
    //pos =fun.BuscarHorarioPosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("Horarios.dat", "rb+");
        fseek(p, pos*sizeof(Horario),0);
    }

    else
    {
        p = fopen("Horarios.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Horario), 1, p);
        fclose(p);
        return true;

    }
}


bool Horario::LeerHO(int pos)
{
    FILE *p;
    Horario aux;
    p = fopen("Horarios.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Horario),0);
   bool leyo=  fread(this,sizeof(Horario), 1, p);
    fclose(p);
    return leyo;
}


bool Horario::BorrarLogicoHO()
{
    int id;
    int pos;
    char opc;
    Funciones fun;

    fun.borrarPantalla();
    cout << "INGRESE ID DEL HORARIO: ";
    cin >>  id;

    pos = fun.BuscarHOPosInt(id);

    if(pos >= 0)
    {

        LeerHO(pos);
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

          GuardarHO(pos);
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

bool Horario::Existe(int dia, int id)
{
    char res;
    FILE *p;
    p = fopen("Horarios.dat", "rb");
    if (p==NULL)
    {

    }
    while(fread(this, sizeof *this, 1, p))
    {
        if(GetIdMedico() == id and GetEstado()== 1 )
        {

           fclose(p);
           return false;
        }

    }

    fclose(p);
    return true;
}



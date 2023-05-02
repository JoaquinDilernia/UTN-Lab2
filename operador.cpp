#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "operador.h"
#include "funciones.h"
#include "menu.h"


Recepcionista::Recepcionista()
{
  //ctor
}


bool Recepcionista::CargarRecepcionista()
{
    Funciones fun;

    Menu aux;


    int id;
    char nombre[30];
    char apellido[30];
    int turno;
    int opc;
    int dni;

    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "____________________________ " << endl;
    id=NuevoIdRec();
    SetIdRecep(id);
    //cout << rec.GetIdRecep() << endl;
    cout << "NOMBRE: " << endl;
    cin.ignore();
    cin.getline(nombre,30);
    fun.Mayusculas(nombre);
    SetNombre(nombre);
    cout << "APELLIDO: " << endl;
    cin.getline(apellido,30);
    fun.Mayusculas(apellido);
    SetApellido(apellido);


    cout << "DNI: " << endl;
    cin >> dni;
    int cant =fun.BuscarDNI(dni);
    if (cant >= 0 )

            {
                cout << endl << "EL DNI YA EXISTE " << endl;
                system ("pause");
                aux.menuRecepcionista();
            }

    SetDoc(dni);
    cout << "SELECCIONE EL TURNO " << endl;
    cout << "___________________ " << endl;
    cout << endl;
    cout << "1) MAÑANA " << endl;
    cout << "2) TARDE " << endl;
    cin >> opc;

    switch(opc)
    {

    case 1:

        SetTurno(1);
        break;

    case 2:

        SetTurno(2);

        break;


    }
    SetEstado(1);
    AgregarRecepcionista();
    return true ;
}


int Recepcionista::LeerRecepc()
{
  FILE *p;
  p=fopen("recepcionistas.dat","rb");
  if (p==NULL)
  {
    return false;
  }
  int id;
  id=idRecep;
  do
  {
    if (fread(this, sizeof *this, 1, p ) < 1)
    {
        idRecep=id;
        fclose(p);
        return false;
    }
  }
  while(id!=idRecep);
  fclose(p);
  return true;

}



bool Recepcionista::AgregarRecepcionista()
{
    FILE *p;
    p = fopen("recepcionistas.dat", "ab");
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


int Recepcionista ::  NuevoIdRec()
{

    FILE *p;
    p = fopen("recepcionistas.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);///que significa esto
        fread(this, sizeof *this, 1, p);
        fclose(p);
        return  idRecep+1;
    }
}


int Recepcionista :: GuardarRecepcionista(int pos)
{
    Funciones fun;

    FILE *p;
    //pos =fun.BuscarRecepcionistaPosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("recepcionistas.dat", "rb+");
        fseek(p, pos*sizeof(Recepcionista),0);
    }

    else
    {
        p = fopen("recepcionistas.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Recepcionista), 1, p);
        fclose(p);
        return true;

    }
}

 bool Recepcionista::LeerRecepcionista(int pos)
{
    FILE *p;

    p = fopen("recepcionistas.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Recepcionista),0);
  bool leyo=  fread(this,sizeof(Recepcionista), 1, p);
    fclose(p);
    return leyo;
}

bool Recepcionista::BorrarRecepcionista()
{
    int pos;

    pos=BorrarLogicoRecepcionista();
    if (pos==1)
    {
        cout << "EL RECEPCIONISTA HA SIDO ELIMINADO " << endl;
        system("pause");
    }
    else
    {
        cout << "EL RECEPCIONISTA NO HA SIDO ELIMINADO " << endl;
        system("pause");

    }

}
bool Recepcionista::BorrarLogicoRecepcionista()
{
    int dni;
    int pos;
    char opc;
    Funciones fun;

    fun.borrarPantalla();
    cout << "INGRESE DNI DEL RECEPCIONISTA : ";
    cin >> dni;

    pos = fun.BuscarRecepcionistaPosInt(dni);

    if(pos >= 0)
    {

        LeerRecepcionista(pos);
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

         GuardarRecepcionista(pos);
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



#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "operador.h"
#include "funciones.h"
#include "menu.h"


Medico::Medico ()
{
  //ctor
}


bool Medico::CargarMedico()
{
    Funciones fun;
    Medico  rec;
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
    id=rec.NuevoIdRec();
    rec.SetIdRecep(id);
    //cout << rec.GetIdRecep() << endl;
    cout << "NOMBRE: " << endl;
    cin.ignore();
    cin.getline(nombre,30);
    fun.Mayusculas(nombre);
    rec.SetNombre(nombre);
    cout << "APELLIDO: " << endl;
    cin.getline(apellido,30);
    fun.Mayusculas(apellido);
    rec.SetApellido(apellido);


    cout << "DNI: " << endl;
    cin >> dni;
int cant =fun.BuscarDNI(dni);
    if (cant >= 0 )

            {
                cout << endl << "EL DNI YA EXISTE " << endl;
                system ("pause");
                aux.menuMedico ();
            }

    rec.SetDoc(dni);
    cout << "SELECCIONE EL TURNO " << endl;
    cout << "___________________ " << endl;
    cout << endl;
    cout << "1) MAÑANA " << endl;
    cout << "2) TARDE " << endl;
    cin >> opc;

    switch(opc)
    {

    case 1:

        rec.SetTurno(1);
        break;

    case 2:

        rec.SetTurno(2);

        break;


    }
    rec.SetEstado(1);
    rec.AgregarMedico ();
    return true ;
}

bool Medico ::MostrarMedico XDNI()
{
    Funciones fun;
    Medico  rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE Medico  POR  DNI " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE DNI: " ;
    fun.gotoxy(20,6);
    cin>>dni;

    pos = fun.BuscarMedico PosInt(dni);

    if(pos>=0)
    {
        rec = fun.LeerMedico (pos);
        if (rec.GetEstado()==1)
        {
            fun.borrarPantalla();
            rec.MostrarMedico ();
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

bool Medico ::BorrarMedico ()
{
    int pos;
    Medico  aux;
    pos=aux.BorrarLogicoMedico ();
    if (pos==1)
    {
        cout << "EL Medico  HA SIDO ELIMINADO " << endl;
        system("pause");
    }
    else
    {
        cout << "EL Medico  NO HA SIDO ELIMINADO " << endl;
        system("pause");

    }

}


int Medico ::LeerRecepc()
{
  FILE *p;
  p=fopen("Medico s.dat","rb");
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



bool Medico ::AgregarMedico ()
{
    FILE *p;
    p = fopen("Medico s.dat", "ab");
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


int Medico  ::  NuevoIdRec()
{

    FILE *p;
    p = fopen("Medico s.dat", "rb");
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

bool Medico ::ListarMedico s() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("Medico s.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }

    else
    {
        while(fread(this, sizeof*this, 1, p)==1)
        {
            if(estado == 1 )
            {
                MostrarMedico ();

            }
        }

        return true;
        fclose(p);
    }
}

  void Medico ::MostrarMedico ()
  {
  Funciones fun;

  if (estado==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE Medico S " ;
    fun.gotoxy(50,3);
    cout << "__________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << idRecep;
    fun.gotoxy(1,8);
    cout << "APELLIDO: " ;
    fun.gotoxy(20,8);
    cout << apellido ;
    fun.gotoxy(1,10);
    cout << "NOMBRE : " ;
    fun.gotoxy(20,10);
    cout << nombre ;
    fun.gotoxy(1,12);
    cout << "TURNO: " ;
    fun.gotoxy(20,12);
    cout << turno ;
    fun.gotoxy(1,16);
    cout << "DNI: " ;
    fun.gotoxy(20,14);
    cout << doc ;
    fun.gotoxy(1,18);
    system ("pause");

    }

}

int Medico ::BorrarLogicoMedico ()
{
    char apellido[30];
    int pos;
    char opc;
    Funciones fun;
    Medico  aux;
    fun.borrarPantalla();
    cout << "INGRESE RAZON SOCIAL: ";
    cin.ignore();
    cin.getline(apellido,30);
    ///fun.Mayusculas();

    pos = fun.BuscarMedico Pos(apellido);
        if(pos >= 0)
    {

        aux=fun.LeerMedico (pos);
        aux.MostrarMedico ();
        system("pause");
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
            aux.SetEstado(0);

            aux.GuardarMedico (pos);
            return 1;
        }
        else
        {
            return 0;
        }
    }
}



int Medico  :: GuardarMedico (int pos)
{
    Funciones fun;

    FILE *p;
    //pos =fun.BuscarMedico PosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("Medico s.dat", "rb+");
        fseek(p, pos*sizeof(Medico ),0);
    }

    else
    {
        p = fopen("Medico s.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Medico ), 1, p);
        fclose(p);
        return true;

    }
}

void Medico  :: ModificarMedico ()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR Medico  " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) NOMBRE ";
    aux.gotoxy(1,7);
    cout << "2) APELLIDO  ";
    aux.gotoxy(1,9);
    cout <<"3) TURNO  ";
    aux.gotoxy(1,11);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,13);
    cout << "0) VOLVER AL MENU Medico   " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MNombreR();
        menu.menuMedico ();

        break;

    case 2:


        MApellidoR();

        break;
            case 3:


        MTurnoR();

        break;

    case '0':
        menu.menuMedico ();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Medico :: MNombreR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;

     cout << "INGRESE EL DNI DEL Medico : ";
    cin >> dni;
    pos =fun.BuscarMedico PosInt(dni);
    if(pos >= 0)
    {

        Medico  aux;

        aux = fun.LeerMedico (pos);

        if (aux.GetEstado() == 1)
        {
            aux.MostrarMedico ();

            do
            {
                cout << endl << endl;
                cout << "DESEA MODIFICAR ESTE REGISTRO (S/N): ";
                cout << endl << endl;
                cin >> opc;
                opc = toupper(opc);
                fun.borrarPantalla();
            }
            while(opc != 'S' && opc != 'N');
            if (opc == 'S')
            {

        fun.borrarPantalla();

    char nombre [30];
    cin.ignore();
    cout<< "INGRESE EL NUEVO NOMBRE: "<<endl;
    cin.getline(nombre,30);
    aux.SetNombre(nombre);

    if(aux.GuardarMedico (pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        aux.MostrarMedico ();
        system("pause");
        fun.borrarPantalla();
        return true;
    }
    else
    {
        cout << "ERROR AL MODIFICAR " << endl;
        system ("pause");
        return false;
    }
            }

        }

    }}





    bool Medico :: MApellidoR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;

     cout << "INGRESE EL DNI DEL Medico : ";
    cin >> dni;
    pos =fun.BuscarMedico PosInt(dni);
    if(pos >= 0)
    {

        Medico  aux;

        aux = fun.LeerMedico (pos);

        if (aux.GetEstado() == 1)
        {
            aux.MostrarMedico ();

            do
            {
                cout << endl << endl;
                cout << "DESEA MODIFICAR ESTE REGISTRO (S/N): ";
                cout << endl << endl;
                cin >> opc;
                opc = toupper(opc);
                fun.borrarPantalla();
            }
            while(opc != 'S' && opc != 'N');
            if (opc == 'S')
            {

        fun.borrarPantalla();

    char apellido [30];
    cin.ignore();
    cout<< "INGRESE EL NUEVO APELLIDO: "<<endl;
    cin.getline(apellido,30);
    aux.SetApellido(apellido);

    if(aux.GuardarMedico (pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        aux.MostrarMedico ();
        system("pause");
        fun.borrarPantalla();
        return true;
    }
    else
    {
        cout << "ERROR AL MODIFICAR " << endl;
        system ("pause");
        return false;
    }
            }

        }

    }}




    bool Medico :: MTurnoR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;

     cout << "INGRESE EL DNI DEL Medico : ";
    cin >> dni;
    pos =fun.BuscarMedico PosInt(dni);
    if(pos >= 0)
    {

        Medico  aux;

        aux = fun.LeerMedico (pos);

        if (aux.GetEstado() == 1)
        {
            aux.MostrarMedico ();

            do
            {
                cout << endl << endl;
                cout << "DESEA MODIFICAR ESTE REGISTRO (S/N): ";
                cout << endl << endl;
                cin >> opc;
                opc = toupper(opc);
                fun.borrarPantalla();
            }
            while(opc != 'S' && opc != 'N');
            if (opc == 'S')
            {

        fun.borrarPantalla();
        int turno;
    cout << "SELECCIONE EL TURNO " << endl;
    cout << "___________________ " << endl;
    cout << endl;
    cout << "1) MAÑANA " << endl;
    cout << "2) TARDE " << endl;
    cin >> turno;

    switch(turno)
    {

    case 1:

        aux.SetTurno(1);
        break;

    case 2:

        aux.SetTurno(2);

        break;
    }
        if(aux.GuardarMedico (pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        aux.MostrarMedico ();
        system("pause");
        fun.borrarPantalla();
        return true;
    }
    else
    {
        cout << "ERROR AL MODIFICAR " << endl;
        system ("pause");
        return false;
    }

            }

        }

    }}

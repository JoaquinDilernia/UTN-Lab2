#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "obraSocial.h"
#include "funciones.h"
#include "menu.h"

//
//
ObraSocial::ObraSocial()
{
  //ctor
}

bool ObraSocial::CargarOS()
{
    Funciones fun;

    int id;
    char esp[30];


    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "____________________________ " << endl;
    id = NuevoIdOS();
    SetIdOS(id);
    cout << GetIdOS() << endl;
    cout << "OBRA SOCIAL: " << endl;
    cin.ignore();
    cin.getline(esp,30);
    fun.Mayusculas(esp);
    SetNombre(esp);
    SetEstado(1);
    bool cargo = AgregarOS();
    return cargo;
   }


int ObraSocial::NuevoIdOS()
{
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);///que significa esto
        fread(this, sizeof*this, 1, p);
        fclose(p);
        return  idOS+1;
    }
}



bool ObraSocial::AgregarOS()
{
    FILE *p;
    p = fopen("ObraSocial.dat", "ab");
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



int ObraSocial:: GuardarOS(int pos)
{
    Funciones fun;

    FILE *p;
    pos =fun.BuscarOSPosInt(idOS);
    if(pos>=0)
    {
        p = fopen("ObraSocial.dat", "rb+");
        fseek(p, pos*sizeof(ObraSocial),0);
    }

    else
    {
        p = fopen("ObraSocial.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(ObraSocial), 1, p);
        fclose(p);
        return true;

    }
}


bool ObraSocial::LeerOS(int pos)
{
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(ObraSocial),0);
    bool leyo = fread(this,sizeof(ObraSocial), 1, p);
    fclose(p);
    return leyo;
}

bool ObraSocial::LeerObraSocial(int id)
{
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    bool leyo;
    while(fread(this, sizeof(ObraSocial), 1, p))
    {
        if(GetIdOS() == id && GetEstado()== 1)
        {
            fclose(p);
            return leyo;
        }

    }

    SetNombre("Obra Social Eliminada");
    fclose(p);
    return leyo;
}



int ObraSocial::ExisteOS(int id)
{
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    while(fread(this, sizeof(ObraSocial), 1, p))
    {
        if(GetIdOS() == id && GetEstado()== 1)
        {
            fclose(p);
            return 1;
        }

    }

    SetNombre("Obra Social Eliminada");
    fclose(p);
    return -1;
}










bool ObraSocial::BorrarLogicoOS()
{
    int dni;
    int pos;
    char opc;
    Funciones fun;
    fun.borrarPantalla();
    cout << "INGRESE ID DE LA OBRA SOCIAL : ";
    cin >> dni;

    pos = fun.BuscarOSPosInt(dni);

    if(pos >= 0)
    {

        LeerOS(pos);
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

            GuardarOS(pos);
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

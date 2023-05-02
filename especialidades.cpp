#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "especialidades.h"
#include "funciones.h"
#include "menu.h"



Especialidad::Especialidad()
{
  //ctor
}


bool Especialidad::CargarEsp()
{
    Funciones fun;


    int id;
    char esp[30];


    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "____________________________ " << endl;
    id = NuevoIdEsp();
    SetIdEspecialidad(id);
    cout << "ESPECIALIDAD: " << endl;
    cin.ignore();
    cin.getline(esp,30);
    fun.Mayusculas(esp);
    SetEspecialidad(esp);
    SetEstado(1);
    bool  cargo = AgregarEsp();
    return cargo;


    }


int Especialidad::NuevoIdEsp()
{
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);///que significa esto
        fread(this, sizeof*this, 1, p);
        fclose(p);
        return  idEspecialidad+1;
    }
}



bool Especialidad::AgregarEsp()
{
    FILE *p;
    p = fopen("Especialidad.dat", "ab");
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



int Especialidad :: GuardarEsp(int pos)
{


    FILE *p;
    if(pos>=0)
    {
        p = fopen("Especialidad.dat", "rb+");
        fseek(p, pos*sizeof(Especialidad),0);
    }

    else
    {
        p = fopen("Especialidad.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Especialidad), 1, p);
        fclose(p);
        return true;

    }
}

void Especialidad::LeerEsp(int pos)
{
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Especialidad),0);
    bool leyo = fread(this,sizeof(Especialidad), 1, p);
    fclose(p);
    return ;
}

void Especialidad::LeerEspecialidad(int id)
{
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    bool leyo;
    while(fread(this, sizeof(Especialidad), 1, p))
    {
        if(GetIdEspecialidad() == id && GetEstado()== 1)
        {
            fclose(p);
            return ;
        }

    }

    //SetEspecialidad("Especialidad Eliminada");
    fclose(p);
    return ;
}



int Especialidad::Existe(int id)
{
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    while(fread(this, sizeof(Especialidad), 1, p))
    {
        if(GetIdEspecialidad() == id && GetEstado()== 1)
        {
            fclose(p);
            return 1;
        }

    }

    //SetEspecialidad("Especialidad Eliminada");
    fclose(p);
    return -1;
}










bool Especialidad::BorrarLogicoEsp()
{
    int dni;
    int pos;
    char opc;
    Funciones fun;
    fun.borrarPantalla();
    cout << "INGRESE ID DE LA ESPECIALIDAD : ";
    cin >> dni;

    pos = fun.BuscarEspPosInt(dni);

    if(pos >= 0)
    {

        LeerEsp(pos);
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

            GuardarEsp(pos);
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

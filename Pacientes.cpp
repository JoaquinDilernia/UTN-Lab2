#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "Pacientes.h"
#include "funciones.h"
#include "menu.h"


Paciente::Paciente()
{
  //ctor
}


bool Paciente::CargarPAC()
{
    //Paciente rec;
   Funciones fun;
   ObraSocial OS;
    Menu aux;
    int ex;


    int doc;
    char nombre[30];
    char apellido[30];
    int idOS;
    int ex1=0;


    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "_____________________________ " << endl;




    cout << "NOMBRE: " << endl;
    cin.ignore();
    cin.getline(nombre,30);
    fun.Mayusculas(nombre);
    SetNombre(nombre);
    cout << "APELLIDO: " << endl;
    cin.getline(apellido,30);
    fun.Mayusculas(apellido);
    SetApellido(apellido);

    do{
    cout<<"DNI: "<<endl;
    cin>>doc;
    ex1=fun.BuscarDNIPAC(doc);
    }while(ex1 != -1);
    SetDNI(doc);





cout << "OBRA SOCIAL: " << endl;
fun.ListarTodasOS();

do{



   cout << "INGRESE EL ID DE LA OBRA SOCIAL" << endl;
    cin >> idOS;

    ex = OS.ExisteOS(idOS);
}while(ex == -1);
    SetIdObraSocial(idOS);




    SetEstado(1);
    AgregarPAC();
    return true ;
}


bool Paciente::AgregarPAC()
{
    FILE *p;
    p = fopen("Pacientes.dat", "ab");
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




int Paciente :: GuardarPAC(int pos)
{
    Funciones fun;

    FILE *p;
    if(pos>=0)
    {
        p = fopen("Pacientes.dat", "rb+");
        fseek(p, pos*sizeof(Paciente),0);
    }

    else
    {
        p = fopen("Pacientes.dat", "ab");
        Estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Paciente), 1, p);
        fclose(p);
        return true;

    }
}



bool Paciente::LeerPAC(int pos)
{
    FILE *p;

    p = fopen("Pacientes.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Paciente),0);
    bool leyo=fread(this,sizeof(Paciente), 1, p);
    fclose(p);
    return leyo;
}


bool Paciente::BorrarLogicoPAC()
{
    int dni;
    int pos;
    char opc;
    Funciones fun;
    fun.borrarPantalla();
    cout << "INGRESE DNI DEL PACIENTE : ";
    cin >> dni;

    pos = fun.BuscarPacientePosInt(dni);

    if(pos >= 0)
    {

        LeerPAC(pos);
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

           GuardarPAC(pos);
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


int Paciente::Existe(int doc)
{
    FILE *p;
    p = fopen("Pacientes.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    while(fread(this, sizeof(Paciente), 1, p))
    {
        if(GetDNI() == doc && GetEstado()== 1)
        {
            fclose(p);
            return 1;
        }

    }

    //SetEspecialidad("Especialidad Eliminada");
    fclose(p);
    return -1;
}


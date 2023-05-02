#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "Medico.h"
#include "funciones.h"
#include "menu.h"


Medico::Medico()
{
  //ctor
}


bool Medico::CargarMedico()
{
    Funciones fun;
    Especialidad esp;

    Menu aux;


    int id;
    char nombre[30];
    char apellido[30];

    int opc;
    int idesp;
    int ex;

    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(39,3);
    cout << "____________________________ " << endl;
    id=NuevoIdMed();
    SetIdMedico(id);
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

do{
    cout << "GENERO: " << endl;
   cin >> genero;
 genero = toupper(genero);
   }while(genero != 'F'  && genero != 'M');
    SetGenero(genero);
    cout << "ESPECIALIDAD: " << endl;
    fun.ListarTodasEspecialidades();

do{



   cout << "INGRESE EL ID DE LA ESPECIALIDAD" << endl;
    cin >> idesp;
    ex = esp.Existe(idesp);
}while(ex == -1);
    SetIdEsp(idesp);



    SetEstado(1);
    AgregarMedico();
    return true ;
}


bool Medico::AgregarMedico()
{
    FILE *p;
    p = fopen("Medicos.dat", "ab");
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


int Medico ::  NuevoIdMed()
{

    FILE *p;
    p = fopen("Medicos.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);///que significa esto
        fread(this, sizeof *this, 1, p);
        fclose(p);
        return  idMedico+1;
    }
}



int Medico :: GuardarMedico(int pos)
{

    FILE *p;
    //pos =fun.BuscarMedicoPosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("Medicos.dat", "rb+");
        fseek(p, pos*sizeof(Medico),0);
    }

    else
    {
        p = fopen("Medicos.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(Medico), 1, p);
        fclose(p);
        return true;

    }
}


bool Medico::LeerMedico(int pos)
{
    FILE *p;
    Medico aux;
    p = fopen("Medicos.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(Medico),0);
   bool leyo=  fread(this,sizeof(Medico), 1, p);
    fclose(p);
    return leyo;
}


bool Medico::BorrarLogicoMedico()
{
    int dni;
    int pos;
    char opc;
    Funciones fun;

    fun.borrarPantalla();
    cout << "INGRESE ID DEL MEDICO : ";
    cin >> dni;

    pos = fun.BuscarMedicoPosInt(dni);

    if(pos >= 0)
    {

        LeerMedico(pos);
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

          GuardarMedico(pos);
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

int Medico::Existe(int id)
{
    FILE *p;
    p = fopen("Medicos.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    while(fread(this, sizeof(Medico), 1, p))
    {
        if(GetIdMedico() == id && GetEstado()== 1)
        {
            fclose(p);
            return 1;
        }

    }

    //SetEspecialidad("Especialidad Eliminada");
    fclose(p);
    return -1;
}



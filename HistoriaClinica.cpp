#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "HistoriaClinica.h"
#include "funciones.h"
#include "menu.h"


HistoriaClinica::HistoriaClinica()
{
  //ctor
}


bool HistoriaClinica::CargarHC()
{
    Funciones fun;
    Fecha fec;
    Menu aux;
    Medico med;
    Paciente rec;


    int id;
    char nombre[50];
    int doc;
    int d, m, a;
    int ex;
    int ex1;
    fun.borrarPantalla();
    fun.gotoxy(40,2);
    cout << "INGRESE LOS SIGUIENTES DATOS " << endl;
    fun.gotoxy(40,3);
    cout << "____________________________ " << endl;
    id=NuevoIdHC();
    SetIdHistoriaClinica(id);

    do{
       cout << "INGRESE EL DNI DEL PACIENTE "<< endl;
       cin >> doc;
        ex1 = rec.Existe(doc);
    }while(ex1 == -1);
SetDni(doc);


    fun.ListarMedicosconEsp(0);

    do{
       cout << "INGRESE EL ID DEL MEDICO "<< endl;
       cin >> id;
        ex = med.Existe(id);
    }while(ex == -1);

    SetIdMedico(id);

        cout << "FECHA CONSULTA " << endl;
        cout << "________________ " << endl;
        cout << "INGRESE DIA: " << endl;
        cin >> d;
        cout << "INGRESE MES: " << endl;
        cin >> m;
        cout << "INGRESE AÑO: " << endl;
        cin >> a;

    while(fechaConsulta.validarFecha(d, m, a) == 0)
        {
        cout << endl;
        cout <<"FECHA INVALIDA " << endl;
        system("pause");
        fun.borrarPantalla();
        cout << "FECHA CONSULTA " << endl;
        cout << "________________ " << endl;
        cout << "INGRESE DIA: " << endl;
        cin >> d;
        cout << "INGRESE MES: " << endl;
        cin >> m;
        cout << "INGRESE AÑO: " << endl;
        cin >> a;

        }


    fechaConsulta.setDiaS(d);
    fechaConsulta.setMesS(m);
    fechaConsulta.setAnioS(a);

    cout << "OBSERVACION: " << endl;
    cin.ignore();
    cin.getline(nombre,50);
    fun.Mayusculas(nombre);
    SetObservacion(nombre);

    SetEstado(1);
   bool leyo= AgregarHC();

    return true ;
}


bool HistoriaClinica::AgregarHC()
{
    FILE *p;
    p = fopen("HistoriaClinicas.dat", "ab");
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


int HistoriaClinica ::  NuevoIdHC()
{

    FILE *p;
    p = fopen("HistoriaClinicas.dat", "rb");
    if (p == NULL)
    {
        return 1;

    }
    else
    {
        fseek(p, sizeof *this *-1 , 2);
        fread(this, sizeof *this, 1, p);
        fclose(p);
        return  idHC+1;
    }
}



int HistoriaClinica :: GuardarHC(int pos)
{

    FILE *p;
    //pos =fun.BuscarHistoriaClinicaPosInt(idRecep);
    if(pos>=0)
    {
        p = fopen("HistoriaClinicas.dat", "rb+");
        fseek(p, pos*sizeof(HistoriaClinica),0);
    }

    else
    {
        p = fopen("HistoriaClinicas.dat", "ab");
        estado = 1;

    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        fwrite(this, sizeof(HistoriaClinica), 1, p);
        fclose(p);
        return true;

    }
}


bool HistoriaClinica::LeerHC(int pos)
{
    FILE *p;
    HistoriaClinica aux;
    p = fopen("HistoriaClinicas.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");
    }
    fseek(p,pos*sizeof(HistoriaClinica),0);
   bool leyo=  fread(this,sizeof(HistoriaClinica), 1, p);
    fclose(p);
    return leyo;
}


bool HistoriaClinica::BorrarLogicoHC()
{
    int id;
    int pos;
    char opc;
    Funciones fun;

    fun.borrarPantalla();
    cout << "INGRESE ID DEL HISTORIA CLINICA: ";
    cin >>  id;

    pos = fun.BuscarHCPosInt(id);

    if(pos >= 0)
    {

        LeerHC(pos);
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

          GuardarHC(pos);
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


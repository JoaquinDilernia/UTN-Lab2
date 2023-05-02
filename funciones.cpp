#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <ctime>


#include "funciones.h"
#include "operador.h"
#include "especialidades.h"
#include "menu.h"
#include "Pacientes.h"


///FUNCIONES GLOBALES.

void Funciones::MostrarFecha()
{

  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;


  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  printf("%d/%d/%d %d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);

fechahoy.setDiaS(tmPtr->tm_mday);
fechahoy.setMesS(tmPtr->tm_mon+1);
fechahoy.setAnioS(1900+tmPtr->tm_year);



  return;
}





void Funciones::gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void Funciones::borrarPantalla()
{
    system("cls");
}

enum Color
{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};

void Funciones::textcolor(short colorTexto=15, short colorFondo=0)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

bool Funciones::soloLetras(char *cadena)
{

    int i=0;
    while(cadena[i]!='\0')///recorre la cadena mientras no sea un null
    {
        if(!(toupper(cadena[i])>= 'A' && toupper(cadena[i]) <= 'Z'))
        {
            return false;
        }
        i++;
    }


    return true;
}

char Funciones::Mayusculas(char *cadena)///convierte los carecteres a mayusculas
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i]=toupper(cadena[i]);
        i++;
    }

    return (*cadena);
}

char Funciones :: Minusculas(char *cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i]=tolower(cadena[i]);
        i++;
    }

    return (*cadena);
}


///FUNCIONES ESPECIALIDADES://///////////////

bool Funciones::MostrarEspXid()
{
    Funciones fun;
    Especialidad rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE ESPECIALIDAD POR  ID " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE ID: " ;
    fun.gotoxy(20,6);
    cin>>dni;

    pos = fun.BuscarEspPosInt(dni);

    if(pos>=0)
    {
        rec.LeerEsp(pos);
        if (rec.GetEstado()==1)
        {
            fun.borrarPantalla();
           fun.MostrarEsp(rec);
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

bool Funciones::ListarEsp() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    int c = 0;
    Especialidad rec;

    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(Especialidad), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarEsp(rec);
                c++;

            }
        }


    }
    if (c==0)
    {
        cout << "NO HAY REGISTROS" << endl;
        system("pause");
        return false;
         fclose(p);

    }
    else
    {
        return true;
        fclose(p);
    }

}

  void Funciones::MostrarEsp(Especialidad rec)
  {
  Funciones fun;

  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE ESPECIALIDADOS " ;
    fun.gotoxy(50,3);
    cout << "___________________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdEspecialidad();
    fun.gotoxy(1,8);
    cout << "ESPECIALIDAD: " ;
    fun.gotoxy(20,8);
    cout << rec.GetEspecialidad();
    fun.gotoxy(1,10);

system("pause");
    }



}

void Funciones :: ModificarEsp()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR ESPECIALIDAD " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) ESPECIALIDAD ";
    aux.gotoxy(1,8);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,10);
    cout << "0) VOLVER AL MENU ESPECIALIDAD  " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MEsp();
        menu.menuEsp();

        break;


    case '0':
        menu.menuEsp();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones::MEsp()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    Especialidad aux;

    cout << "INGRESE EL ID DEL ESPECIALIDAD: ";
    cin >> id;
    pos =fun.BuscarEspPosInt(id);
    if(pos >= 0)
    {


        aux.LeerEsp(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarEsp(aux);

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
    cout<< "INGRESE LA NUEVA ESPECIALIDAD: "<<endl;
    cin.getline(nombre,30);
    aux.SetEspecialidad(nombre);

    if(aux.GuardarEsp(pos) == true)
    {
        cout << "SE HA MODIFICADO LA ESPECIALIDAD CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarEsp(aux);
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



int Funciones::BuscarEspPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("Especialidad.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Especialidad aux;
    while(fread(&aux, sizeof(Especialidad), 1, p))
    {
        if(aux.GetIdEspecialidad()==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

///OPERADOR///

bool Funciones::MostrarRecepcionistaXDNI()
{
    Funciones fun;
    Recepcionista rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE RECEPCIONISTA POR  DNI " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE DNI: " ;
    fun.gotoxy(20,6);
    cin>>dni;

    pos = fun.BuscarRecepcionistaPosInt(dni);

    if(pos>=0)
    {
       rec.LeerRecepcionista(pos);
        if (rec.GetEstado()==1)
        {
            fun.borrarPantalla();
            fun.MostrarRecepcionista(rec);
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


bool Funciones::ListarRecepcionistas() ///Abre el archivo y llama a la funcion Mostrar
{
    Recepcionista rec;
    FILE *p;
    p = fopen("recepcionistas.dat", "rb");
    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }

    else
    {
        while(fread(&rec, sizeof(Recepcionista), 1, p)==1)
        {
            if(rec.GetEstado() == 1 )
            {
                MostrarRecepcionista(rec);

            }
        }

        return true;
        fclose(p);
    }
}

  void Funciones::MostrarRecepcionista(Recepcionista rec)
  {
  Funciones fun;


  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE RECEPCIONISTAS " ;
    fun.gotoxy(50,3);
    cout << "__________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdRecep();
    fun.gotoxy(1,8);
    cout << "APELLIDO: " ;
    fun.gotoxy(20,8);
    cout << rec.GetApellido() ;
    fun.gotoxy(1,10);
    cout << "NOMBRE : " ;
    fun.gotoxy(20,10);
    cout << rec.GetNombre() ;
    fun.gotoxy(1,12);
    cout << "TURNO: " ;
    fun.gotoxy(20,12);
    cout << rec.GetTurno() ;
    fun.gotoxy(1,16);
    cout << "DNI: " ;
    fun.gotoxy(20,14);
    cout << rec.GetDoc() ;
    fun.gotoxy(1,18);
    system ("pause");

    }

}

void Funciones:: ModificarRecepcionista()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR RECEPCIONISTA " << endl;
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
    cout << "0) VOLVER AL MENU RECEPCIONISTA  " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MNombreR();
        menu.menuRecepcionista();

        break;

    case 2:


        MApellidoR();

        break;
            case 3:


        MTurnoR();

        break;

    case '0':
        menu.menuRecepcionista();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones:: MNombreR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;
    Recepcionista aux;

     cout << "INGRESE EL DNI DEL RECEPCIONISTA: ";
    cin >> dni;
    pos =fun.BuscarRecepcionistaPosInt(dni);
    if(pos >= 0)
    {


         aux.LeerRecepcionista(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarRecepcionista(aux);

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

    if(aux.GuardarRecepcionista(pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarRecepcionista(aux);
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





    bool Funciones:: MApellidoR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;
    Recepcionista aux;

     cout << "INGRESE EL cout << endl;DNI DEL RECEPCIONISTA: ";
    cin >> dni;
    pos = fun.BuscarRecepcionistaPosInt(dni);
    if(pos >= 0)
    {


        aux.LeerRecepcionista(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarRecepcionista(aux);

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

    if(aux.GuardarRecepcionista(pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarRecepcionista(aux);
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




    bool Funciones:: MTurnoR()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;
    Recepcionista aux;

     cout << "INGRESE EL DNI DEL RECEPCIONISTA: ";
    cin >> dni;
    pos = fun.BuscarRecepcionistaPosInt(dni);
    if(pos >= 0)
    {



        aux.LeerRecepcionista(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarRecepcionista(aux);

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
        if(aux.GuardarRecepcionista(pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarRecepcionista(aux);
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

    int Funciones::BuscarDNI(int dni)
{

    FILE *p;
    int i = 0;
    p = fopen("recepcionistas.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Recepcionista aux ;
    while(fread(&aux, sizeof(Recepcionista), 1, p))
    {
        if(aux.GetDoc() == dni)
        {
            fclose(p);
            return i;
        }
    i++;
    }
    fclose(p);
    return -1;
}


 int Funciones::BuscarDNIPAC(int dni)
{

    FILE *p;
    int i = 0;
    p = fopen("Pacientes.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Paciente aux;
    while(fread(&aux, sizeof(Paciente), 1, p))
    {
        if(aux.GetDNI() == dni && aux.GetEstado() == 1)
        {
            fclose(p);
            return i;
        }
    i++;
    }
    fclose(p);
    return -1;
}

 int Funciones::BuscarRecepcionistaPos(char *apellido)
{
    int i=0;
    FILE *p;
    p = fopen("recepcionistas.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Recepcionista aux;
    while(fread(&aux, sizeof(Recepcionista), 1, p))
    {
        if(strcmp(aux.GetApellido(),apellido)==0)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int Funciones::BuscarRecepcionistaPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("recepcionistas.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Recepcionista aux;
    while(fread(&aux, sizeof(Recepcionista), 1, p))
    {
        if(aux.GetDoc()==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

///Medicos///

bool Funciones::ListarMedicos() ///Abre el archivo y llama a la funcion Mostrar
{
    Medico rec;
    FILE *p;
    p = fopen("Medicos.dat", "rb");
    int c = 0;
    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }

    else
    {
        while(fread(&rec, sizeof(Medico), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarMedico(rec);
                c++;

            }
        }


    }
    if (c==0)
    {
        cout << "NO HAY REGISTROS" << endl;
        system("pause");
        return false;
         fclose(p);

    }
    else
    {
        return true;
        fclose(p);
    }

}

void Funciones::ListarMedicosconEsp(int id)
{

    Medico rec;
    Especialidad esp;
    FILE *p;
    p = fopen("Medicos.dat", "rb");
    FILE *r;
    r = fopen("Especialidad.dat", "rb");

    if (p==NULL or r==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return;
    }


    else
    {
        while(fread(&rec, sizeof(Medico), 1, p)==1)
        {

            while(fread(&esp, sizeof(Especialidad), 1, r)==1)
            {

                if(rec.GetEstado() == 1 && esp.GetEstado()==1)
                {

                    if(rec.GetIdEsp() == esp.GetIdEspecialidad())
                    {
                        if(esp.GetIdEspecialidad() == id or id == 0)
                    {

                        cout << endl;
                        cout << "______________________________________________" << endl;
                        cout << "ID MEDICO: " << rec.GetIdMedico() << endl;
                        cout << "NOMBRE: " << rec.GetNombre() << endl;
                        cout << "APELLIDO: " << rec.GetApellido() << endl;
                        cout << "ESPECIALIDAD: " << esp.GetEspecialidad() << endl;
                        cout << "______________________________________________" << endl;
                        cout << endl;
                    }
                    }
                    }
                }
            int resultado = fseek(r, 0, SEEK_SET );
        }

    }
        fclose(p);
        fclose(r);
        return;

    }


int Funciones::ListarHorariosMedicos(int id)
{
    int opc = 0;
    int cantd = 0;
    int dif = 0;
    int v= 0;
    int dia = 0;
    int c = 0;
    Medico rec;
    Horario esp;
    Menu men;
    Fecha fec;
    FILE *p;
    p = fopen("Medicos.dat", "rb");
    FILE *r;
    r = fopen("Horarios.dat", "rb");

    if (p==NULL or r==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return 0 ;
    }


    else
    {
        while(fread(&rec, sizeof(Medico), 1, p)==1)
        {
            if (rec.GetIdMedico() == id && rec.GetEstado() == 1)
            {

             while(fread(&esp, sizeof(Horario), 1, r)==1)
            {

                if( esp.GetEstado()==1)
                {

                    if(esp.GetIdMedico() == id)
                    {

                        fec.MostrarDiaTexto(esp.GetDia());




                        if(fechahoy.getMes() == 1 or fechahoy.getMes() == 3 or fechahoy.getMes() == 5 or fechahoy.getMes() == 7 or fechahoy.getMes() == 8 or fechahoy.getMes() == 10 or fechahoy.getMes() == 12)
                        {
                            cantd = 1;
                        }

                            if(fechahoy.getMes() == 4 or fechahoy.getMes() == 6 or fechahoy.getMes() == 9 or fechahoy.getMes() == 11)
                            {
                                cantd = 2;
                            }

                                if(fechahoy.getMes()==2)
                                {
                                    cantd = 3;
                                }



                            int nroDia=CalculaDia();


                             dif = nroDia - esp.GetDia();

                            if(dif > 0)
                            {

                                 v = 7 - dif;
                                 dia = fechahoy.getDia();
                                 dia += v;


                            }
                            else
                            {
                                dif = dif * -1;
                                 dia = fechahoy.getDia();

                                 dia += dif;
                            }







                        for(int i = 0; i <4; i++)
                        {

                        opc ++;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << "OPCION  " << opc;
                        cout << endl;
                        cout << "______________________________________________" << endl;
                        cout << endl;
                        cout <<dia;
                        cout << endl;
                        cout << endl;
                        cout << "DESDE: " << esp.GetHOI() << endl;
                        cout << "HASTA: " << esp.GetHOF() << endl;
                        cout << "______________________________________________" << endl;
                        cout << endl;
                        dia += 7;
                        if(cantd == 3)
                        {
                            if(dia > 29)
                            {
                                dia = dia-7;
                                dia = dia - 29 + 7;
                            }
                        }

                        if(cantd == 1)
                        {
                            if(dia > 31)
                            {
                                dia = dia-7;
                                dia = dia - 31 + 7;
                            }
                        }

                        if(cantd == 2)
                        {
                            if(dia > 30)
                            {
                                dia = dia-7;
                                dia = dia - 30 + 7;
                            }
                        }


                        }
                         fclose(p);
                        fclose(r);
                        return cantd;


                    }


                }
            }

        }
        }
    }
        fclose(p);
        fclose(r);
//        if (c==0)
//        {
//            cout << "El Medico seleccionado no tiene Horarios Disponibles " << endl;
//            system("pause");
//            men.menuTurnos();
//        }
        return cantd;

    }



    int Funciones::buscardia(int id)
    {

    Medico rec;
    Fecha fec;
    Horario esp;
int d= 0;

    FILE *p;
    p = fopen("Medicos.dat", "rb");
    FILE *r;
    r = fopen("Horarios.dat", "rb");

    if (p==NULL or r==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return 0 ;
    }

           while(fread(&rec, sizeof(Medico), 1, p)==1)
        {
            if (rec.GetIdMedico() == id && rec.GetEstado() == 1)
            {

             while(fread(&esp, sizeof(Horario), 1, r)==1)
            {

                if( esp.GetEstado()==1)
                {

                    if(esp.GetIdMedico() == id)
                    {

                        //fec.MostrarDiaTexto(esp.GetDia());

 d = esp.GetDia();


    }
    }
    }}}

    fclose(p);
    fclose(r);
    return d;
    }

  int Funciones::CalculaDia()
  {

      int d  = fechahoy.getDia();
      int m = 0;
      switch(fechahoy.getMes())
      {
  case 1:
    m = 0;

    break;

      case 2:
    m = 3;

    break;

          case 3:
    m = 3;

    break;
        case 4:
    m = 6;

    break;
          case 5:
    m = 1;

    break;
            case 6:
    m = 4;

    break;

          case 7:
    m = 6;

    break;
          case 8:
    m = 2;

    break;
          case 9:
    m = 5;

    break;
          case 10:
    m = 0;

    break;
          case 11:
    m = 3;

    break;

          case 12:
    m = 5;

    break;

      }


      int nroDia = ( d + m + 20 + 4 + 6) % 7;
      nroDia = nroDia+1;
      return nroDia ;
  }
  void Funciones::MostrarMedico(Medico rec)  {

  Funciones fun;
  Especialidad esp;

  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE MEDICOS " ;
    fun.gotoxy(50,3);
    cout << "__________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdMedico();
    fun.gotoxy(1,8);
    cout << "APELLIDO: " ;
    fun.gotoxy(20,8);
    cout << rec.GetApellido() ;
    fun.gotoxy(1,10);
    cout << "NOMBRE : " ;
    fun.gotoxy(20,10);
    cout << rec.GetNombre() ;
    fun.gotoxy(1,12);
    cout << "GENERO: " ;
    fun.gotoxy(20,12);
    cout << rec.GetGenero() ;
    esp.LeerEspecialidad(rec.GetIdEsp());
    fun.gotoxy(1,14);
    cout << " ESPECIALIDAD: " ;
    fun.gotoxy(30,14);
    cout << esp.GetEspecialidad();
    fun.gotoxy(1,16);
    system ("pause");

    }

}
void Funciones :: ModificarMedico()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR MEDICO " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) NOMBRE ";
    aux.gotoxy(1,7);
    cout << "2) APELLIDO  ";
    aux.gotoxy(1,10);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,12);
    cout << "0) VOLVER AL MENU MEDICO  " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MNombreM();
        menu.menuMedico();

        break;

    case 2:


        MApellidoM();



    case '0':
        menu.menuMedico();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones:: MNombreM()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    Medico aux;

    cout << "INGRESE EL ID DEL MEDICO: ";
    cin >> id;
    pos =fun.BuscarMedicoPosInt(id);
    if(pos >= 0)
    {


        aux.LeerMedico(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarMedico(aux);

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

    if(aux.GuardarMedico(pos) == true)
    {
        cout << "SE HA MODIFICADO EL NOMBRE CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarMedico(aux);
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





    bool Funciones:: MApellidoM()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;
    Medico aux;

     cout << "INGRESE EL ID DEL MEDICO: ";
    cin >> dni;
    pos = fun.BuscarMedicoPosInt(dni);
    if(pos >= 0)
    {


    aux.LeerMedico(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarMedico(aux);

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

    if(aux.GuardarMedico(pos) == true)
    {
        cout << "SE HA MODIFICADO EL APELLIDO CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarMedico(aux);
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





int Funciones::BuscarMedicoPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("Medicos.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Medico aux;
    while(fread(&aux, sizeof(Medico), 1, p))
    {
        if(aux.GetIdMedico()==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

void Funciones::ListarTodasEspecialidades()
{
    Especialidad aux;
    FILE *p;
    p=fopen("Especialidad.dat","rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");

    }

    while(fread(&aux,sizeof (Especialidad),1,p))
    {
        if(aux.GetEstado()==1){
        cout << "________________________________________"<< endl;
        cout << "ID: " << aux.GetIdEspecialidad()<<endl;
        cout << "ESPECIALIDAD: " << aux.GetEspecialidad()<<endl;
        cout << "________________________________________"<< endl;
    }
    }

}

bool Funciones::MostrarMedicoXEsp()
{
    Funciones fun;
    Medico rec;
    Especialidad esp;
    int id;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE MEDICOS POR ESPECIALIDAD " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(50,5);
    fun.ListarTodasEspecialidades();
    fun.gotoxy(10,40);
    cout << "INGRESE ID ESPECIALIDAD: " ;
    fun.gotoxy(35,40);
    cin>>id;

    pos = fun.BuscarEspPosInt(id);

    if(pos>=0)
    {
        esp.LeerEsp(pos);

        Medico rec;
        FILE *p;
        p = fopen("Medicos.dat", "rb");
        int c = 0;
        if (p==NULL)
        {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
        }

        else
        {

        while(fread(&rec, sizeof(Medico), 1, p)==1)
        {
            if(rec.GetEstado()== 1 && esp.GetEstado()== 1)
            {


                if(rec.GetIdEsp() == esp.GetIdEspecialidad())
                {
                    MostrarMedico(rec);

                    c++;
                }
            }
        }


    }
    if (c==0)
    {
        cout << "NO HAY REGISTROS" << endl;
        system("pause");
        return false;
         fclose(p);

    }
    else
    {
        return true;
        fclose(p);
    }

}



    else
    {
        return false;
    }

}



///PACIENTES///


bool Funciones::ListarPAC() ///Abre el archivo y llama a la funcion Mostrar
{
    Paciente rec;
    FILE *p;
    p = fopen("Pacientes.dat", "rb");
    int c = 0;
    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }

    else
    {
        while(fread(&rec, sizeof(Paciente), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarPAC(rec);
                c++;

            }
        }


    }
    if (c==0)
    {
        cout << "NO HAY REGISTROS" << endl;
        system("pause");
        return false;
         fclose(p);

    }
    else
    {
        return true;
        fclose(p);
    }

}

  void Funciones::MostrarPAC(Paciente rec)
  {

  Funciones fun;
 ObraSocial esp;

  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE PACIENTES " ;
    fun.gotoxy(50,3);
    cout << "________________________" ;
    fun.gotoxy(1,6);
    cout << "DNI : " ;
    fun.gotoxy(20,6);
    cout << rec.GetDNI();
    fun.gotoxy(1,8);
    cout << "APELLIDO: " ;
    fun.gotoxy(20,8);
    cout << rec.GetApellido() ;
    fun.gotoxy(1,10);
    cout << "NOMBRE : " ;
    fun.gotoxy(20,10);
    cout << rec.GetNombre() ;

    esp.LeerObraSocial(rec.GetIdObraSocial());
    fun.gotoxy(1,18);
    cout << " OBRA SOCIAL: " ;
    fun.gotoxy(30,18);
    cout << esp.GetNombre();
    fun.gotoxy(1,20);
    system ("pause");

    }

}
void Funciones :: ModificarPAC()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR PACIENTE " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) NOMBRE ";
    aux.gotoxy(1,7);
    cout << "2) APELLIDO  ";
    aux.gotoxy(1,10);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,12);
    cout << "0) VOLVER AL MENU MEDICO  " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MNombreP();
        menu.menuPaciente();

        break;

    case 2:


        MApellidoP();

        break;


    case '0':
        menu.menuMedico();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones:: MNombreP()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    Paciente aux;

    cout << "INGRESE EL DNI DEL PACIENTE: ";
    cin >> id;
    pos =fun.BuscarPacientePosInt(id);
    if(pos >= 0)
    {


        aux.LeerPAC(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarPAC(aux);

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

    if(aux.GuardarPAC(pos) == true)
    {
        cout << "SE HA MODIFICADO EL NOMBRE CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarPAC(aux);
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





    bool Funciones:: MApellidoP()
{
    char opc;
    int pos;
    int dni;
    Funciones fun;
    Paciente aux;

     cout << "INGRESE EL DNI DEL PACIENTE: ";
    cin >> dni;
    pos = fun.BuscarPacientePosInt(dni);
    if(pos >= 0)
    {


       aux.LeerPAC(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarPAC(aux);

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

    if(aux.GuardarPAC(pos) == true)
    {
        cout << "SE HA MODIFICADO EL APELLIDO CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarPAC(aux);
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



void Funciones::ListarNombrePAC(int doc)
{
    int c = 0;
    Paciente rec;
    Menu men;
    Fecha fec;
    FILE *p;
    p = fopen("Pacientes.dat", "rb");


    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return;
    }


    else
    {
        while(fread(&rec, sizeof(Paciente), 1, p)==1)
        {
            if (rec.GetDNI() == doc && rec.GetEstado() == 1)
            {

                        cout << endl;
                        cout << "______________________________________________" << endl;
                        cout << endl;
                        cout << "NOMBRE: " << rec.GetNombre() << endl;
                        cout << "APELLIDO: " << rec.GetApellido() << endl;
                        cout << "______________________________________________" << endl;
                        cout << endl;

                    }


                }

    }
        fclose(p);


        return;

    }


int Funciones::BuscarPacientePosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("Pacientes.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Paciente aux;
    while(fread(&aux, sizeof(Paciente), 1, p))
    {
        if(aux.GetDNI()==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

void Funciones::ListarTodasOS()
{
    ObraSocial aux;
    FILE *p;
    p=fopen("ObraSocial.dat","rb");
    if (p==NULL)
    {
        cout << "ERROR DE ARCHIVO " << endl;
        system("pause");

    }

    while(fread(&aux,sizeof (ObraSocial),1,p))
    {
        if(aux.GetEstado()==1){
        cout << "________________________________________"<< endl;
        cout << "ID: " << aux.GetIdOS()<<endl;
        cout << "ESPECIALIDAD: " << aux.GetNombre()<<endl;
        cout << "________________________________________"<< endl;
    }
    }

}



bool Funciones::MostrarPACXDNI()
{
    Funciones fun;
    Paciente rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE PACIENTE POR  DNI " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE DNI: " ;
    fun.gotoxy(20,6);
    cin>>dni;

    pos = fun.BuscarPacientePosInt(dni);

    if(pos>=0)
    {
        rec.LeerPAC(pos);
        if (rec.GetEstado()==1)
        {
            fun.borrarPantalla();
           fun.MostrarPAC(rec);
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





///OBRA SOCIAL///


bool Funciones::MostrarOSXid()
{
    Funciones fun;
    ObraSocial rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE OBRA SOCIAL POR  ID " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE ID: " ;
    fun.gotoxy(20,6);
    cin>>dni;

    pos = fun.BuscarOSPosInt(dni);

    if(pos>=0)
    {
        rec.LeerOS(pos);
        if (rec.GetEstado()==1)
        {
            fun.borrarPantalla();
           fun.MostrarOS(rec);
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

bool Funciones::ListarOS() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    int c = 0;
    ObraSocial rec;

    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(ObraSocial), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarOS(rec);
                c++;

            }
        }


    }
    if (c==0)
    {
        cout << "NO HAY REGISTROS" << endl;
        system("pause");
        return false;
         fclose(p);

    }
    else
    {
        return true;
        fclose(p);
    }

}

  void Funciones::MostrarOS(ObraSocial rec)
  {
  Funciones fun;

  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE OBRA SOCIAL " ;
    fun.gotoxy(50,3);
    cout << "___________________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdOS();
    fun.gotoxy(1,8);
    cout << "OBRA SOCIAL: " ;
    fun.gotoxy(20,8);
    cout << rec.GetNombre();
    fun.gotoxy(1,10);
    system ("pause");

    }

}

void Funciones :: ModificarOS()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR OBRA SOCIAL " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) OBRA SOCIAL ";
    aux.gotoxy(1,8);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,10);
    cout << "0) VOLVER AL MENU PRINCIPAL   " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MOS();
        menu.menuOS();

        break;


    case '0':
        menu.menuOS();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones::MOS()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    ObraSocial aux;

    cout << "INGRESE EL ID DE LA OBRA SOCIAL: ";
    cin >> id;
    pos =fun.BuscarOSPosInt(id);
    if(pos >= 0)
    {


        aux.LeerOS(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarOS(aux);

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
    cout<< "INGRESE LA NUEVA ESPECIALIDAD: "<<endl;
    cin.getline(nombre,30);
    aux.SetNombre(nombre);

    if(aux.GuardarOS(pos) == true)
    {
        cout << "SE HA MODIFICADO LA ESPECIALIDAD CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarOS(aux);
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



int Funciones::BuscarOSPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("ObraSocial.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    ObraSocial aux;
    while(fread(&aux, sizeof(ObraSocial), 1, p))
    {
        if(aux.GetIdOS()==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}







///HISTORIA CLINICA///


bool Funciones::MostrarHCXDNI()
{

    FILE *p;
    p = fopen("HistoriaClinicas.dat", "rb");
    Funciones fun;
  HistoriaClinica rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE HISTORIA CLINICA  POR  DNI DEL PACIENTE " ;
    fun.gotoxy(50,4);
    cout << "________________________________________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE DNI DEL PACIENTE: " ;
    fun.gotoxy(30,6);
    cin>>dni;

      if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(HistoriaClinica), 1, p)==1)
        {

            if(rec.GetEstado() == 1 && dni == rec.GetDni())
            {
                MostrarHC(rec);


            }
        }


    }
       return true;
        fclose(p);
}

bool Funciones::ListarHC() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("HistoriaClinicas.dat", "rb");
    HistoriaClinica rec;

    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(HistoriaClinica), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarHC(rec);


            }
        }


    }
       return true;
        fclose(p);


}

  void Funciones::MostrarHC(HistoriaClinica rec)
  {
  Funciones fun;


  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE HISTORIA CLINICA  " ;
    fun.gotoxy(50,3);
    cout << "___________________________________" ;
    fun.gotoxy(1,6);
    cout << "ID : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdHistoriaClinica();
    fun.gotoxy(1,8);
    cout << "DNI PACIENTE : " ;
    fun.gotoxy(20,8);
    cout << rec.GetDni();
    fun.gotoxy(1,10);
    cout << "ID MEDICO : " ;
    fun.gotoxy(20,10);
    cout << rec.GetIdMedico();
     fun.gotoxy(1,12);
    cout << "FECHA : " ;
    fun.gotoxy(20,12);
    cout <<rec.fechaConsulta.getDia()<<" / "<<rec.fechaConsulta.getMes()<<" / "<<rec.fechaConsulta.getAnio();
    fun.gotoxy(1,14);
    cout << "OBSERVACION: ";
    fun.gotoxy(20,14);
    cout << rec.GetObservacion();
    fun.gotoxy(1,20);
    system ("pause");

    }

}

void Funciones :: ModificarHC()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR HISTORIA CLINICA " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) OBSERVACION DE LA CONSULTA ";
    aux.gotoxy(1,8);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,10);
    cout << "0) VOLVER AL MENU PRINCIPAL   " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



        MHC();
        menu.menuHC();

        break;


    case '0':
        menu.menuHC();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones::MHC()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    HistoriaClinica aux;

    cout << "INGRESE EL ID DE LA HISTORIA CLINICA: ";
    cin >> id;
    pos =fun.BuscarHCPosInt(id);
    if(pos >= 0)
    {


        aux.LeerHC(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarHC(aux);

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

    char nombre [50];
    cin.ignore();
    cout<< "INGRESE LA NUEVA OBSERVACION: "<<endl;
    cin.getline(nombre,50);
    aux.SetObservacion(nombre);

    if(aux.GuardarHC(pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarHC(aux);
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



//int Funciones::BuscarHCPosInt(int dni)
//{
//    int i=0;
//    FILE *p;
//    p = fopen("Horarios.dat", "rb");
//    if (p==NULL)
//    {
//        return -1;
//    }
//    Horario aux;
//    while(fread(&aux, sizeof(Horario), 1, p))
//    {
//        if(aux.GetDni()== dni)
//        {
//            fclose(p);
//            return i;
//        }
//        i++;
//    }
//    fclose(p);
//    return -1;
//}
//

int Funciones::BuscarHCPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("HistoriaClinicas.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
   HistoriaClinica aux;
    while(fread(&aux, sizeof(HistoriaClinica), 1, p))
    {
        if(aux.GetIdHistoriaClinica()== id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}










///HORARIOS///


bool Funciones::MostrarHOXDNI()
{

    FILE *p;
    p = fopen("Horarios.dat", "rb");
    Funciones fun;
    Horario rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE HISTORIA CLINICA  POR  ID DEL MEDICO " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE ID DEL MEDICO: " ;
    fun.gotoxy(30,6);
    cin>>dni;

      if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(Horario), 1, p)==1)
        {

            if(rec.GetEstado() == 1 && dni == rec.GetIdMedico())
            {
                MostrarHO(rec);


            }
        }


    }
       return true;
        fclose(p);
}

bool Funciones::ListarHO() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("Horarios.dat", "rb");
    Horario rec;

    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(Horario), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarHO(rec);


            }
        }


    }
       return true;
        fclose(p);


}

  void Funciones::MostrarHO(Horario rec)
  {
    Funciones fun;
    Fecha fec;

  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE HORARIOS  " ;
    fun.gotoxy(50,3);
    cout << "_____________________" ;
    fun.gotoxy(1,6);
    cout << "ID: " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdHO();
    fun.gotoxy(1,8);
    cout << "ID MEDICO: " ;
    fun.gotoxy(20,8);
    cout << rec.GetIdMedico();
    fun.gotoxy(1,10);
    cout << "DIA: " ;
    fun.gotoxy(20,10);
    fec.MostrarDiaTexto(rec.GetDia());
    fun.gotoxy(1,12);
    cout << "HORARIO: " ;
    fun.gotoxy(20,12);
    cout << "DESDE: " <<rec.GetHOI()<<" HS. HASTA: "<<rec.GetHOF() <<" HS.";
    fun.gotoxy(1,20);
    system ("pause");

    }

}



void Funciones :: ModificarHO()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR HORARIO " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) OBSERVACION DE LA CONSULTA ";
    aux.gotoxy(1,8);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,10);
    cout << "0) VOLVER AL MENU PRINCIPAL   " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



//        MHO();
        menu.menuHO();

        break;


    case '0':
        menu.menuHO();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}



bool Funciones::MHO()
{
    char opc;
    int pos;
    int id;
    Funciones fun;
    Horario aux;

    cout << "INGRESE EL ID DEL HORARIO: ";
    cin >> id;
    pos =fun.BuscarHOPosInt(id);
    if(pos >= 0)
    {


        aux.LeerHO(pos);

        if (aux.GetEstado() == 1)
        {
            fun.MostrarHO(aux);

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

  int HOI;
  int HOF;
    cin.ignore();
    cout<< "INGRESE EL NUEVO HORARIO DE INICIO : "<<endl;
    cin >> HOI;
    cout<< "INGRESE EL NUEVO HORARIO DE FIN: "<<endl;
    cin >> HOF;
    aux.SetHOI(HOI);
    aux.SetHOF(HOF);

    if(aux.GuardarHO(pos) == true)
    {
        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
        cout << endl;
        fun.MostrarHO(aux);
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



 int Funciones::BuscarHo(int dia , int id)
{

    FILE *p;
    int i = 0;
    p = fopen("Horarios.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Horario aux;
    while(fread(&aux, sizeof(Horario), 1, p))
    {
        if(aux.GetDia() == dia && aux.GetIdMedico() == id)
        {
            fclose(p);
            return 1;
        }

    }
    fclose(p);
    return -1;
}
//int Funciones::BuscarHCPosInt(int dni)
//{
//    int i=0;
//    FILE *p;
//    p = fopen("Horarios.dat", "rb");
//    if (p==NULL)
//    {
//        return -1;
//    }
//    Horario aux;
//    while(fread(&aux, sizeof(Horario), 1, p))
//    {
//        if(aux.GetDni()== dni)
//        {
//            fclose(p);
//            return i;
//        }
//        i++;
//    }
//    fclose(p);
//    return -1;
//}
//

int Funciones::BuscarHOPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("Horarios.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
    Horario aux;
    while(fread(&aux, sizeof(Horario), 1, p))
    {
        if(aux.GetIdHO()== id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}













///TURNOS///


bool Funciones::MostrarTurnosXDNI()
{

    FILE *p;
    p = fopen("Turnos.dat", "rb");
    Funciones fun;
Turnos rec;
    int dni;
    int pos;
    fun.borrarPantalla();
    fun.gotoxy(50,3);
    cout << "LISTADO DE TURNOS  POR  ID DE MEDICO " ;
    fun.gotoxy(50,4);
    cout << "_____________________________________________________" ;
    fun.gotoxy(1,6);
    cout << "INGRESE ID MEDICO: " ;
    fun.gotoxy(30,6);
    cin>>dni;

      if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(Turnos), 1, p)==1)
        {

            if(rec.GetEstado() == 1 && dni == rec.GetIdMedico())
            {
                MostrarTurnos(rec);


            }
        }


    }
       return true;
        fclose(p);
}

bool Funciones::ListarTurnos() ///Abre el archivo y llama a la funcion Mostrar
{
    FILE *p;
    p = fopen("Turnos.dat", "rb");
  Turnos rec;

    if (p==NULL)
    {
        cout << "ERROR EN EL ARCHIVO " << endl;
        system("pause");
        return false;
    }
    else
    {
        while(fread(&rec, sizeof(Turnos), 1, p)==1)
        {

            if(rec.GetEstado() == 1 )
            {
                MostrarTurnos(rec);


            }
        }


    }
       return true;
        fclose(p);


}

  void Funciones::MostrarTurnos(Turnos rec)
  {
  Funciones fun;


  if (rec.GetEstado()==1)
    {
    fun.borrarPantalla();
    fun.gotoxy(50,2);
    cout << "LISTADO DE TURNOS " ;
    fun.gotoxy(50,3);
    cout << "___________________________________" ;
    fun.gotoxy(1,6);
    cout << "ID TURNO : " ;
    fun.gotoxy(20,6);
    cout << rec.GetIdTurno();
    fun.gotoxy(1,8);
    cout << "DNI PACIENTE : " ;
    fun.gotoxy(20,8);
    cout << rec.GetDni();
    fun.gotoxy(1,10);
    cout << "ID MEDICO : " ;
    fun.gotoxy(20,10);
    cout << rec.GetIdMedico();
     fun.gotoxy(1,12);
    cout << "FECHA : " ;
    fun.gotoxy(20,12);
    cout <<rec.fechaTurno.getDia()<<" / "<<rec.fechaTurno.getMes()<<" / "<<rec.fechaTurno.getAnio();
    fun.gotoxy(1,14);
    cout << "HORARIO: ";
    fun.gotoxy(20,14);
    cout << rec.GetHorario();
    fun.gotoxy(1,20);
    system ("pause");

    }

}

void Funciones :: ModificarTurnos()
{
    Menu menu;
    Funciones aux;
    int opc;


    aux.borrarPantalla();

    aux.gotoxy(53,2);
    cout << "MENU MODIFICAR TURNOS " << endl;
    aux.gotoxy(1,3);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,5);
    cout << "1) HORARIO ";
    aux.gotoxy(1,8);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    aux.gotoxy(1,10);
    cout << "0) VOLVER AL MENU PRINCIPAL   " << endl << endl;
    aux.gotoxy(3,15);
    cout << "INGRESE LA OPCION DESEADA: ";
    cin >> opc;

    switch(opc)
    {
    case 1:



//        MTurnos();
        menu.menuTurnos();

        break;


    case '0':
        menu.menuTurnos();
        break;

    default:

        cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
        system ("pause");
        break;
    }
}

//
//
//bool Funciones::MTurnos()
//{
//    char opc;
//    int pos;
//    int id;
//    Funciones fun;
//    Turnos aux;
//
//    cout << "INGRESE EL ID DEL TURNO: ";
//    cin >> id;
//    pos =fun.BuscarTurnosPosInt(id);
//    if(pos >= 0)
//    {
//
//
//        aux.LeerTurnos(pos);
//
//        if (aux.GetEstado() == 1)
//        {
//            fun.MostrarTurnos(aux);
//
//            do
//            {
//                cout << endl << endl;
//                cout << "DESEA MODIFICAR ESTE REGISTRO (S/N): ";
//                cout << endl << endl;
//                cin >> opc;
//                opc = toupper(opc);
//                fun.borrarPantalla();
//            }
//            while(opc != 'S' && opc != 'N');
//            if (opc == 'S')
//            {
//
//        fun.borrarPantalla();
//
//    char nombre [50];
//    cin.ignore();
//    cout<< "INGRESE LA NUEVA OBSERVACION: "<<endl;
//    cin.getline(nombre,50);
//    aux.SetObservacion(nombre);
//
//    if(aux.GuardarTurno(pos) == true)
//    {
//        cout << "SE HA MODIFICADO LA OBSERVACION CORRECTAMENTE " << endl;
//        cout << endl;
//        fun.MostrarTurnos(aux);
//        system("pause");
//        fun.borrarPantalla();
//        return true;
//    }
//    else
//    {
//        cout << "ERROR AL MODIFICAR " << endl;
//        system ("pause");
//        return false;
//    }
//            }
//
//        }
//
//    }}
//
//
//
//int Funciones::BuscarHCPosInt(int dni)
//{
//    int i=0;
//    FILE *p;
//    p = fopen("Horarios.dat", "rb");
//    if (p==NULL)
//    {
//        return -1;
//    }
//    Horario aux;
//    while(fread(&aux, sizeof(Horario), 1, p))
//    {
//        if(aux.GetDni()== dni)
//        {
//            fclose(p);
//            return i;
//        }
//        i++;
//    }
//    fclose(p);
//    return -1;
//}


int Funciones::BuscarTurnosPosInt(int id)
{
    int i=0;
    FILE *p;
    p = fopen("Turnos.dat", "rb");
    if (p==NULL)
    {
        return -1;
    }
   Turnos aux;
    while(fread(&aux, sizeof(Turnos), 1, p))
    {
        if(aux.GetIdTurno()== id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}


void Funciones :: MostrarHDisp(int dia , int id)
{
   Turnos tur;
   Horario hor;
    FILE *p;
    p = fopen("Horarios.dat" ,"rb");
    FILE *r;
    r = fopen("Turnos.dat", "rb");



   while(fread(&tur, sizeof(Turnos), 1, r))
    {
    if(dia ==  tur.fechaTurno.getDia())
    {

  while(fread(&hor, sizeof(Horario), 1, p))
  {
      if(id == hor.GetIdMedico())
      {
        system("cls");
        cout << "-------------------------------------------------------------------------"<<endl;
        cout << "HORARIOS DISPONIBLES PARA EL PROFESIONAL SELECCIONADO: " << endl;
        cout << "-------------------------------------------------------------------------"<<endl;

            for(int i = hor.GetHOI(); i <= hor.GetHOF(); i++)
            {


                  if(Existe(dia,id,i))
                  {


                    cout<<endl;
                    cout<<endl;
                    cout << i << " hs." << endl;


                  }



          }


      }


  }

    }






          }


          while(fread(&hor, sizeof(Horario), 1, p))
  {
      if(id == hor.GetIdMedico())
      {
           system("cls");
           cout << "-------------------------------------------------------------------------"<<endl;
           cout << "HORARIOS DISPONIBLES PARA EL PROFESIONAL SELECCIONADO: " << endl;
           cout << "-------------------------------------------------------------------------"<<endl;

            for(int i = hor.GetHOI(); i <= hor.GetHOF(); i++)
            {

            cout<<endl;
            cout<<endl;
            cout << i << " hs." << endl;

            }






      }}

      fclose(p);
      fclose(r);
      }


bool Funciones :: Existe(int dia , int id, int i)
{

    FILE *p;
    p = fopen("Turnos.dat", "rb");
    Turnos tur;

    while(fread(&tur, sizeof(Turnos), 1, p))
    {
        if(tur.GetIdMedico() == id and tur.GetHorario()== i and tur.fechaTurno.getDia() == dia and tur.GetEstado() == 1)
        {
            fclose(p);
            return false;
        }
           fclose(p);
        return true;

    }

    return true;
    fclose(p);

}





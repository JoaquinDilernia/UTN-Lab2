#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "menu.h"
#include "funciones.h"
#include "fecha.h"
#include "operador.h"
#include "Medico.h"
#include "especialidades.h"
#include "Pacientes.h"
#include "obraSocial.h"
#include "horarios.h"




Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
Fecha GfechaSistema;



void Menu::PantallaPrincipal()
{
    Funciones fun;
    system("mode con: cols=120 lines=80");
    fun.borrarPantalla();
    fun.gotoxy(1, 10);
    cout << "-----------------------------------------------------------------------------------------------------------------------";
    fun.gotoxy(50, 25);
    cout << "****CENTRO MEDICO DELTA*****";
    fun.gotoxy(1, 40);
    cout << "----------------------------------------------------------------------------------------------------------------------";
fun.gotoxy(1, 70);
system("pause");

}

void Menu::MenuPrincipal()
{

    Funciones fun;

    int opc;

    while(true)
    {
        fun.borrarPantalla();
        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU PRINCIPAL ";
        fun.gotoxy(54,4);
        cout << "________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) MEDICOS ";
        fun.gotoxy(5,10);
        cout << "2) ESPECIALIDADES ";
        fun.gotoxy(5,12);
        cout << "3) PACIENTES " ;
        fun.gotoxy(5,14);
        cout << "4) OBRA SOCIAL " ;
        fun.gotoxy(5,16);
        cout << "5) TURNOS " ;
        fun.gotoxy(5,18);
        cout << "6) HISTORIA CLINICA " ;
        fun.gotoxy(5,20);
        cout << "7) HORARIOS " ;
        fun.gotoxy(1,22);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,24);
        cout << "0) SALIR DEL PROGRAMA ";
        fun.gotoxy(11,30);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:

           menuMedico();
            break;


        case 2:
            menuEsp();
            break;

        case 3:

            menuPaciente();
            break;

        case 4:

            menuOS();
            break;


        case 5:
            menuTurnos();


            break;



        case 6:

         menuHC();

         break;

        case 7:

         menuHO();

         break;




       case 0:
            exit(1) ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}




void Menu::menuRecepcionista()
{

    Funciones fun;
    Recepcionista rec;

    int opc;
    while(true)
    {
        fun.borrarPantalla();
        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU RECEPCIONISTA ";
        fun.gotoxy(54,4);
        cout << "___________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) NUEVO OPERADOR ";
        fun.gotoxy(5,10);
        cout << "2) LISTAR TODOS LOS OPERADORES ";
        fun.gotoxy(5,12);
        cout << "3) LISTAR POR DNI DE OPERADOR  " ;
        fun.gotoxy(5,14);
        cout << "4) MODIFICAR OPERADOR  " ;
        fun.gotoxy(5,16);
        cout << "5) ELIMINAR OPERADOR  " ;
        fun.gotoxy(1,18);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,20);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,22);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarRecepcionista()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarRecepcionistas()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuRecepcionista();
            fun.borrarPantalla();

            break;

        case 3:

            fun.borrarPantalla();
            if (fun.MostrarRecepcionistaXDNI()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuRecepcionista();
            fun.borrarPantalla();


            break;

        case 4:

            fun.ModificarRecepcionista();
            break;




        case 5:

             if (rec.BorrarLogicoRecepcionista()==true)
            {
                cout << "... HA SIDO ELIMINADO " << endl;
                system("pause");
                menuRecepcionista();
                break;
            }
            cout << "... NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuRecepcionista();
            break;



            break;


            case 6:

            break;


        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}
//



void Menu::menuTurnos()
{
    Funciones fun;
    Turnos rec;
    int opc;
    while(true)
    {

        fun.borrarPantalla();

        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(53,2);
        cout << "MENU TURNOS " << endl;
        fun.gotoxy(1,3);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(1,5);
        cout << "1) CARGAR NUEVO TURNO ";
        fun.gotoxy(1,7);
        cout << "2) MOSTRAR TODOS LOS TURNOS ";
        fun.gotoxy(1,9);
        cout << "3) MOSTRAR TURNOS POR ID MEDICO " ;
        fun.gotoxy(1,11);
        cout << "4) MODIFICAR TURNO " ;
        fun.gotoxy(1,13);
        cout << "5) CANCELAR TURNO " ;
        fun.gotoxy(1,15);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(1,17);
        cout << "0) VOLVER AL MENU PRINCIPAL " << endl << endl;
        fun.gotoxy(3,19);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;



        switch(opc)
        {
       case 1:



           if (rec.CargarTurno()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarTurnos()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuTurnos();
            fun.borrarPantalla();

            break;


        case 3:

           fun.borrarPantalla();
            if (fun.MostrarTurnosXDNI()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuTurnos();
            fun.borrarPantalla();
            break;

        case 4:

            fun.ModificarTurnos();
            break;


        case 5:

            if (rec.BorrarLogicoTurno()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuTurnos();
                break;
            }

            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuTurnos();
            break;



            break;



        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }



    system("pause>nul");
    return;

}

void Menu::menuMedico()
{

    Funciones fun;
    Medico rec;

    int opc;
    while(true)
    {
        fun.borrarPantalla();

        system("mode con: cols=120 lines=80");
        fun.gotoxy(90, 1);
        fun.MostrarFecha();

        fun.gotoxy(55,3);
        cout << "MENU MEDICO ";
        fun.gotoxy(54,4);
        cout << "_____________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) NUEVO MEDICO ";
        fun.gotoxy(5,10);
        cout << "2) LISTAR TODOS LOS MEDICOS ";
        fun.gotoxy(5,12);
        cout << "3) LISTAR POR ESPECIALIDAD DE MEDICO   " ;
        fun.gotoxy(5,14);
        cout << "4) MODIFICAR MEDICO  " ;
        fun.gotoxy(5,16);
        cout << "5) ELIMINAR MEDICO  " ;
        fun.gotoxy(1,18);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,20);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,22);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarMedico()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarMedicos()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuMedico();
            fun.borrarPantalla();

            break;

        case 3:

            fun.borrarPantalla();
            if (fun.MostrarMedicoXEsp()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuMedico();
            fun.borrarPantalla();


            break;

        case 4:

           fun.ModificarMedico();
            break;




        case 5:

             if (rec.BorrarLogicoMedico()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuMedico();
                break;
            }
            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuMedico();
            break;



            break;


            case 6:

            break;


        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}



void Menu::menuEsp()
{

    Funciones fun;
    Especialidad rec;

    int opc;
    while(true)
    {
        fun.borrarPantalla();
      //  fun.textcolor(2,11);
        system("mode con: cols=120 lines=80");

        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU ESPECIALIDADES ";
        fun.gotoxy(54,4);
        cout << "_____________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) AGREGAR ESPECIALIDAD ";
        fun.gotoxy(5,10);
        cout << "2) LISTAR TODAS LAS ESPECIALIDADES ";
        fun.gotoxy(5,12);
        cout << "3) LISTAR POR ID DE ESPECIALIDAD   " ;
        fun.gotoxy(5,14);
        cout << "4) MODIFICAR ESPECIALIDAD  " ;
        fun.gotoxy(5,16);
        cout << "5) ELIMINAR ESPECIALIDAD  " ;
        fun.gotoxy(1,18);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,20);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,22);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarEsp()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarEsp()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuEsp();
            fun.borrarPantalla();

            break;

        case 3:

            fun.borrarPantalla();
            if (fun.MostrarEspXid()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuEsp();
            fun.borrarPantalla();


            break;

        case 4:

          fun.ModificarEsp();
            break;




        case 5:

             if (rec.BorrarLogicoEsp()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuEsp();
                break;
            }
            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuEsp();
            break;



            break;


            case 6:

            break;


        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}


void Menu::menuPaciente()
{

    Funciones fun;
    Paciente rec;

    int opc;
    while(true)
    {

        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU PACIENTE ";
        fun.gotoxy(54,4);
        cout << "________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) NUEVO PACIENTE ";
        fun.gotoxy(5,10);
        cout << "2) LISTAR TODOS LOS PACIENTES ";
        fun.gotoxy(5,12);
        cout << "3) LISTAR POR DNI DE PACIENTE  " ;
        fun.gotoxy(5,14);
        cout << "4) MODIFICAR PACIENTE  " ;
        fun.gotoxy(5,16);
        cout << "5) ELIMINAR PACIENTE  " ;
        fun.gotoxy(1,18);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,20);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,22);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarPAC()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");

            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarPAC()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuPaciente();
            fun.borrarPantalla();

            break;

        case 3:

            fun.borrarPantalla();
            if (fun.MostrarPACXDNI()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuPaciente();
            fun.borrarPantalla();


            break;

        case 4:

           fun.ModificarPAC();
            break;




        case 5:

             if (rec.BorrarLogicoPAC()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuPaciente();
                break;
            }
            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuPaciente();
            break;



            break;


            case 6:

            break;


        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}




void Menu::menuOS()
{

    Funciones fun;
    ObraSocial rec;

    int opc;
    while(true)
    {

        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU OBRA SOCIAL ";
        fun.gotoxy(54,4);
        cout << "__________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) AGREGAR OBRA SOCIAL ";
        fun.gotoxy(5,10);
        cout << "2) LISTAR TODAS LAS OBRAS SOCIALES  ";
        fun.gotoxy(5,12);
        cout << "3) LISTAR POR ID DE OBRA SOCIAL   " ;
        fun.gotoxy(5,14);
        cout << "4) MODIFICAR OBRA SOCIAL  " ;
        fun.gotoxy(5,16);
        cout << "5) ELIMINAR OBRA SOCIAL  " ;
        fun.gotoxy(1,18);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,20);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,22);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:

           if (rec.CargarOS()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.ListarOS()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuOS();
            fun.borrarPantalla();

            break;

        case 3:

            fun.borrarPantalla();
            if (fun.MostrarOSXid()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuOS();
            fun.borrarPantalla();


            break;

        case 4:

          fun.ModificarOS();
            break;




        case 5:

             if (rec.BorrarLogicoOS()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuOS();
                break;
            }
            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuOS();
            break;





        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}






bool VerifFechaSistema()
{
    if (GfechaSistema.getAnio()==0)
    {
        return false;
    }
    return true;
}



void Menu::menuHC()
{

    Funciones fun;
    HistoriaClinica rec;

    int opc;
    while(true)
    {

        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU HISTORIA CLINICA ";
        fun.gotoxy(54,4);
        cout << "_________________________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) AGREGAR HISTORIA CLINICA ";
        fun.gotoxy(5,10);
        cout << "2) MOSTRAR HISTORIA CLINICA DE UN PACIENTE  ";
        fun.gotoxy(5,12);
        cout << "3) MODIFICAR HISTORIA CLINICA " ;
        fun.gotoxy(5,14);
        cout << "4) ELIMINAR HISTORIA CLINICA " ;
        fun.gotoxy(1,16);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,18);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,20);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarHC()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.MostrarHCXDNI()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuHC();
            fun.borrarPantalla();

            break;


        case 3:

          fun.ModificarHC();
            break;




        case 4:

            if (rec.BorrarLogicoHC()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuHC();
                break;
            }

            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuHC();
            break;



            break;



        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}



void Menu::menuHO()
{

    Funciones fun;
   Horario rec;

    int opc;
    while(true)
    {

        system("mode con: cols=120 lines=80");
        fun.borrarPantalla();
        fun.gotoxy(90, 1);
        fun.MostrarFecha();
        fun.gotoxy(55,3);
        cout << "MENU HORARIO ";
        fun.gotoxy(54,4);
        cout << "_______________";
        fun.gotoxy(1,6);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,8);
        cout << "1) AGREGAR HORARIO ";
        fun.gotoxy(5,10);
        cout << "2) MOSTRAR HORARIOS DE UN MEDICO  ";
        fun.gotoxy(5,12);
        cout << "3) MODIFICAR HORARIOS " ;
        fun.gotoxy(5,14);
        cout << "4) ELIMINAR HORARIOS" ;
        fun.gotoxy(1,16);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        fun.gotoxy(5,18);
        cout << "0) VOLVER AL MENU PRINCIPAL  ";
        fun.gotoxy(11,20);
        cout << "INGRESE LA OPCION DESEADA: ";
        cin >> opc;

        switch(opc)
        {
        case 1:



           if (rec.CargarHO()==true)
            {

                fun.borrarPantalla();

                cout << endl << "INGRESO CON EXITO " << endl;

                system("pause");
            }
            else
            {
                cout << endl << "NO SE PUDO REALIZAR EL INGRESO " << endl;
                system ("pause");
            }


            break;


        case 2:
            fun.borrarPantalla();
            if (fun.MostrarHOXDNI()==false)
            {


                cout << "ERROR AL LISTAR " << endl;
                system("pause");
                break;

            }
            menuHO();
            fun.borrarPantalla();

            break;


        case 3:

          fun.ModificarHO();
            break;




        case 4:

            if (rec.BorrarLogicoHO()==true)
            {
                cout << "EL REGISTRO HA SIDO ELIMINADO " << endl;
                system("pause");
                menuHO();
                break;
            }

            cout << "EL REGISTRO NO HA SIDO ELIMINADO " << endl;
            system("pause");
            menuHO();
            break;







        case 0:
           MenuPrincipal() ;
            break;


        default:

            cout << "OPCION INCORRECTA, INTENTE NUEVAMENTE" << endl;
            system ("pause");
            break;
        }
    }

}


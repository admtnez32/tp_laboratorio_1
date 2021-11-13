#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
#include "Funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
	LinkedList* listaEmpleados = ll_newLinkedList();
	int option;
	int flagEmpleados = 0;

    do{
    	option = -1;
    	MenuPrincipal();
    	PedirNumero(&option, "Ingrese opcion: ");
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados) == 0)
                {
                	flagEmpleados = 1;
                }
                break;

            case 2:
                if(controller_loadFromBinary("data.dat",listaEmpleados) == 0)
				{
					flagEmpleados = 1;
				}
                break;

            case 3:
            	if(controller_addEmployee(listaEmpleados))
            	{
					flagEmpleados = 1;
				}
            	break;

            case 4:
            	if(flagEmpleados)
				{
            		controller_editEmployee(listaEmpleados);
				}
            	else
				{
					printf("\n--- No hay empleados cargados ---\n\n");
				}

            	break;

            case 5:
            	if(flagEmpleados)
				{
					controller_removeEmployee(listaEmpleados);
				}
            	else
				{
					printf("\n--- No hay empleados cargados ---\n\n");
				}
            	break;

            case 6:
            	if(flagEmpleados)
				{
					controller_ListEmployee(listaEmpleados);
				}
            	else
            	{
            		printf("\n--- No hay empleados cargados ---\n\n");
            	}
            	break;

            case 7:
            	if(flagEmpleados)
				{
					controller_sortEmployee(listaEmpleados);
				}
            	else
				{
					printf("\n--- No hay empleados cargados ---\n\n");
				}
            	break;

            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	break;

            case 9:
            	controller_saveAsBinary("data.dat", listaEmpleados);
            	break;

            case 10:
            	if(flagEmpleados)
            	{
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	printf("\n\n--- Adios ---\n\n");
            	break;

            default:
				printf("\n--- Opcion incorrecta ---\n\n");
				break;
        }
    }while(option != 10);


    return 0;
}


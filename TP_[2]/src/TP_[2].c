/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Martinez Alexis
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 * CASE 4!!! INFORMAR LISTADOS
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define TAM_NOMBRE 51
#define TAM_APELLIDO 51

int main(void) {
	setbuf(stdout, NULL);


	Employee empleados[TAM];//= {	{100, "Alexis", "Martinez", 450.55, 1, FALSE}, {101, "Maria", "Martinez", 123.99, 2, FALSE}, {102, "David", "Martinez", 259.01, 3, FALSE},
			//{104, "Javier", "Martinez", 133.05, 1, FALSE}, {105, "Jose", "Martinez", 125, 2, FALSE}, {106, "Vicky", "Martinez", 238.15, 3, FALSE}};
	int opcion = -1;
	int id = 100;
	int flagCargaEmpleado = 0;
	int sector;
	float salario;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];

	initEmployees(empleados, TAM);

	do{
		PrintMenu(PRINCIPAL);
		opcion = -1;
		PedirNumero(&opcion, "Elija opcion: ");
		switch(opcion)
		{
		case 1:
			if(CargarEmpleado(empleados, TAM, nombre, TAM_NOMBRE, apellido, TAM_APELLIDO, &salario, &sector, &id))
			{
				addEmployee(empleados, TAM, id, nombre, apellido, salario, sector);
				printf("\n--- Empleado cargado con exito ---\n\n");
				flagCargaEmpleado = 1;
			}
			else
			{
				printf("--- Carga de empleado cancelada ---\n--- Regresando al menu principal ---\n\n");
			}
			break;

		case 2:
			if(flagCargaEmpleado)
			{
				if(!ModificarEmpleado(empleados, TAM))
				{
					printf("\n--- Modificacion cancelada ---\n--- Regresando al menu principal ---\n\n");
				}
			}
			else
			{
				printf("\n--- No hay empleados cargados ---\n\n");
			}

			break;

		case 3:
			if(flagCargaEmpleado)
			{
				if(!DarDeBajaEmpleado(empleados, TAM))
				{
					printf("\n--- Baja no realizada ---\n--- Regresando al menu principal ---\n\n");
				}
			}
			else
			{
				printf("\n--- No hay empleados cargados ---\n\n");
			}

			if(!VerificarEmpleadosActivos(empleados, TAM))
			{
				flagCargaEmpleado = 0;
			}
			break;

		case 4:
			if(flagCargaEmpleado)
			{
				MostrarInforme(empleados, TAM);
			}
			else
			{
				printf("\n--- No hay empleados cargados ---\n\n");
			}
			break;

		case 0:
			printf("\n\n--- ADIOS ---\n\n");
			break;

		default:
			printf("\n--- Opcion incorrecta ---\n\n");
			break;
		}

	}while(opcion != 0);

	return EXIT_SUCCESS;
}

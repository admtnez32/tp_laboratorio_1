#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile = NULL;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno = 0;
		fclose(pFile);
		printf("\n--- Datos cargados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}



    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile = NULL;

	pFile = fopen(path, "rb");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno = 0;
		fclose(pFile);
		printf("\n--- Datos cargados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo bin ---\n\n");
	}



    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* eAux = employee_new();

	if(pArrayListEmployee != NULL && eAux != NULL && employee_addEmployee(eAux) == 0)
	{
		ll_add(pArrayListEmployee, eAux);
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idSolicitado;
	int index;

	Employee* eEmpleado;

	if(pArrayListEmployee != NULL && controller_RequestId(pArrayListEmployee, &idSolicitado, &index) == 0)
	{
		eEmpleado = ll_get(pArrayListEmployee, index);
		employee_editEmployee(eEmpleado);
	}
	else
	{
		printf("\n--- Modificacion cancelada ---\n");
		printf("\n--- Volviendo al menu principal ---\n");
	}
    return retorno;
}


/// @brief Buscar Id
///
/// @param pArrayListEmployee LinkedList*
/// @param id int
/// @param index int*
/// @return	int
int controller_FindId(LinkedList* pArrayListEmployee, int id, int* index)
{
	int retorno = -1;
	int idEncontrado;
	int len;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && id >= 0)
	{
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i < len; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idEncontrado);

			if(idEncontrado == id)
			{
				*index = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief Solicitar Id
///
/// @param pArrayListEmployee LinkedList*
/// @param id int*
/// @param index int*
/// @return int
int controller_RequestId(LinkedList* pArrayListEmployee, int* id, int* index)
{
	int retorno = -1;
	int idSolicitado;
	int auxIndex;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		if(PedirNumero(&idSolicitado, "\nIngrese id: ") && controller_FindId(pArrayListEmployee, idSolicitado, &auxIndex) == 0)
		{
			*id = idSolicitado;
			*index = auxIndex;
			retorno = 0;
			printf("\n--- Id correcto ---\n\n");
		}
		else
		{
			printf("\n--- Error, id incorrecto ---\n");
		}
	}
	return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idSolicitado;
	int index;

	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && controller_RequestId(pArrayListEmployee, &idSolicitado, &index) == 0)
	{
		auxEmployee = ll_get(pArrayListEmployee, index);

		employee_delete(auxEmployee);
		ll_remove(pArrayListEmployee, index);
		printf("\n--- Baja exitosa ---\n\n");
		retorno = 0;
	}
	else
	{
		printf("\n--- Baja fallida ---\n\n");
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;


	Employee* auxEmployee=NULL;


	if(pArrayListEmployee != NULL){

		printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");

		for(i=0;i<ll_len(pArrayListEmployee);i++){

			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_ListEmployee(auxEmployee);
		}
		printf("\n\n");

		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
*/
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int orden;
	int flag = 0;

	if(pArrayListEmployee != NULL)
	{
		do
		{
			if(flag || PedirNumeroConReintentosConRango(&orden, "\nElija orden:\n 1. Ascendente\n 0. Descendente\n\nOrden: ", 0, 1, 3))
			{
				flag = 1;
				printf("\n\n");
				MenuOrdenar();
				PedirNumero(&opcion, "Ingrese opcion: ");

				switch(opcion)
				{
					case 1:
						ll_sort(pArrayListEmployee, employee_CompareByName, orden);
						printf("\n--- Empleados ordenados correctamente ---\n\n");
						break;

					case 2:
						ll_sort(pArrayListEmployee, employee_CompareById, orden);
						printf("\n--- Empleados ordenados correctamente ---\n\n");
						break;

					case 3:
						printf("\nAqui\n\n");
						ll_sort(pArrayListEmployee, employee_CompareByHoursWorked, orden);
						printf("\n--- Empleados ordenados correctamente ---\n\n");
						break;

					case 4:
						ll_sort(pArrayListEmployee, employee_CompareBySalary, orden);
						printf("\n--- Empleados ordenados correctamente ---\n\n");
						break;

					case 0:
						printf("\n--- Volviendo al menu principal ---\n\n");
						break;

					default:
						printf("\nOpcion incorrecta\n\n");
						break;
				}
			}
			else
			{
				printf("\n--- Ordenamiento cancelado ---\n\n");
			}
		}while(opcion != 0);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeToText(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 0;
		printf("\n--- Datos guardados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}

    return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeToBin(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 0;
		printf("\n--- Datos guardados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}

    return retorno;
    return 1;
}


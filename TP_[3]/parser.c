#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	Employee* eAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			eAux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, eAux);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* eAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		while(!feof(pFile))
		{
			eAux = employee_new();

			if(eAux != NULL && fread(eAux, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, eAux);
			}
		}
		retorno = 0;
	}

    return retorno;
}


/// @brief Parsea el archivo data.csv (modo texto) con los datos de los empleados
///
/// @param pFile FILE*
/// @param pArrayListEmployee LinkedList*
/// @return int
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id;
	int horasTrabajadas;
	int salario;
	char nombre[51];
	Employee* eEmpleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,salario\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			eEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(eEmpleado, &id);
			employee_getHorasTrabajadas(eEmpleado, &horasTrabajadas);
			employee_getSueldo(eEmpleado, &salario);
			employee_getNombre(eEmpleado, nombre);

			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, salario);
		}

		retorno = 0;
	}

	return retorno;
}

/// @brief Parsea el archivo data.dat (modo bin) con los datos de los empleados
///
/// @param pFile FILE*
/// @param pArrayListEmployee LinkedList*
/// @return int
int parser_EmployeeToBin(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* eEmpleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			eEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(eEmpleado, sizeof(Employee), 1, pFile);
		}

		retorno = 0;
	}

	return retorno;
}

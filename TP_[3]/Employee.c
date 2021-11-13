#include "Employee.h"


/// @brief Asignar espacio en memoria tipo Employee
///
/// @return Employee*
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}


/// @brief Crea y Carga un Empleado
///
/// @param idStr char*
/// @param nombreStr char*
/// @param horasTrabajadasStr char*
/// @param sueldoStr char*
/// @return Employee*
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this;
	this = NULL;

	int id;
	int horasTrabajadas;
	char nombre[51];
	int sueldo;

	this = employee_new();

	if(this != NULL)
	{
		id = atoi(idStr);
		strcpy(nombre, nombreStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		employee_setId(this, id);
		employee_setNombre(this, nombre);
		employee_setHorasTrabajadas(this, horasTrabajadas);
		employee_setSueldo(this, sueldo);
	}

	return (Employee*)this;
}


/// @brief Carga un empleado
///
/// @param this	Employee*
/// @param idStr char*
/// @param nombreStr char*
/// @param horasTrabajadasStr char*
/// @param sueldoStr char*
/// @return int
int employee_newParametrosAux(Employee* this, char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	int retorno = -1;

	int id;
	int horasTrabajadas;
	char nombre[51];
	int sueldo;

	if(this != NULL)
	{
		id = atoi(idStr);
		strcpy(nombre, nombreStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		employee_setId(this, id);
		employee_setNombre(this, nombre);
		employee_setHorasTrabajadas(this, horasTrabajadas);
		employee_setSueldo(this, sueldo);

		retorno = 0;
	}

	return retorno;
}


/// @brief Borrar un empleado
///
/// @param this	Employee*
/// @return int
int employee_delete(Employee* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}

return retorno;
}


/// @brief	Setear un id
///
/// @param this Employee*
/// @param id	int
/// @return int
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}



/// @brief Setear nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

/// @brief	Setear horas trabajadas
///
/// @param this Employee*
/// @param horasTrabajadas int
/// @return int
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/// @brief	Setear sueldo
///
/// @param this Employee*
/// @param sueldo int
/// @return int
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

/// @brief	Obtener un id
///
/// @param this Employee*
/// @param id int*
/// @return int
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}


return retorno;
}

/// @brief	Obtener nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}


return retorno;
}

/// @brief	Obtener horas trabajadas
///
/// @param this Employee*
/// @param horasTrabajadas int*
/// @return int
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

return retorno;
}

/// @brief	Obtener sueldo
///
/// @param this Employee*
/// @param sueldo int*
/// @return int
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}

return retorno;
}


/// @brief Busca proximo id
///
/// @param path	char*
/// @param id	char*
/// @return int
int employee_NextId(char* path, char* id)
{
	int retorno = -1;
	int aux;
	char idAux[50];

	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", idAux);

		fclose(pFile);

		aux = atoi(idAux);
		aux++;
		itoa(aux, idAux, 10);

		strcpy(id, idAux);

		pFile = fopen(path, "w");

		fprintf(pFile, "%s", idAux);

		fclose(pFile);

		retorno = 0;
	}

return retorno;
}


/// @brief Comparar 2 nombres
///
/// @param empleadoUno void*
/// @param empleadoDos void*
/// @return int
int employee_CompareByName(void* empleadoUno, void* empleadoDos)
{
	Employee* eUno;
	Employee* eDos;
	int retorno;

	if(empleadoDos != NULL && empleadoDos != NULL)
	{
		eUno = (Employee*) empleadoUno;
		eDos = (Employee*) empleadoDos;
		retorno = strcmpi(eUno->nombre, eDos->nombre);
		printf("\nOrdenando... Aguarde.\n\n");
	}
	return retorno;
}

/// @brief Comparar 2 Ids
///
/// @param empleadoUno void*
/// @param empleadoDos void*
/// @return int
int employee_CompareById(void* empleadoUno, void* empleadoDos)
{
	Employee* eUno;
	Employee* eDos;
	int retorno = 0;

	if(empleadoDos != NULL && empleadoDos != NULL)
	{
		eUno = (Employee*) empleadoUno;
		eDos = (Employee*) empleadoDos;

		if(eUno->id > eDos->id)
		{
			retorno = 1;
		}
		else
		{
			if(eUno->id < eDos->id)
			{
				retorno = -1;
			}
		}
		printf("\nOrdenando... Aguarde.\n\n");
	}
	return retorno;
}

/// @brief Comparar 2 horas
///
/// @param empleadoUno void*
/// @param empleadoDos void*
/// @return int
int employee_CompareByHoursWorked(void* empleadoUno, void* empleadoDos)
{
	Employee* eUno;
	Employee* eDos;
	int retorno = 0;

	if(empleadoDos != NULL && empleadoDos != NULL)
	{
		eUno = (Employee*) empleadoUno;
		eDos = (Employee*) empleadoDos;

		if(eUno->horasTrabajadas > eDos->horasTrabajadas)
		{
			retorno = 1;
		}
		else
		{
			if(eUno->horasTrabajadas < eDos->horasTrabajadas)
			{
				retorno = -1;
			}
		}
		printf("\nOrdenando... Aguarde.\n\n");
	}
	return retorno;
}

/// @brief Comparar 2 salarios
///
/// @param empleadoUno void*
/// @param empleadoDos void*
/// @return int
int employee_CompareBySalary(void* empleadoUno, void* empleadoDos)
{
	Employee* eUno;
	Employee* eDos;
	int retorno = 0;

	if(empleadoDos != NULL && empleadoDos != NULL)
	{
		eUno = (Employee*) empleadoUno;
		eDos = (Employee*) empleadoDos;

		if(eUno->sueldo > eDos->sueldo)
		{
			retorno = 1;
		}
		else
		{
			if(eUno->sueldo < eDos->sueldo)
			{
				retorno = -1;
			}
		}
		printf("\nOrdenando... Aguarde.\n\n");
	}
	return retorno;
}



/// @brief Crear empleado
///
/// @param this Employee*
/// @return int
int employee_addEmployee(Employee* this)
{
	int retorno = -1;
	int retornoNewParam;
	char nombre[51];
	char horasTrabajadas[51];
	char salario[51];
	char idStr[10];

	if(this != NULL &&
	   PedirNombreConReintentos(nombre, 51, "\nIngrese nombre: ", 3) &&
	   PedirNumeroCharConReintentos(horasTrabajadas, "Ingrese cantidad de horas trabajadas: ", 3) &&
	   PedirNumeroCharConReintentos(salario, "Ingrese salario: ", 3))
	{
		employee_NextId("lista_id.csv", idStr);
		retornoNewParam = employee_newParametrosAux(this, idStr, nombre, horasTrabajadas, salario);

		if(retornoNewParam == 0)
		{
			retorno = 0;
			printf("\n--- Alta exitosa ---\n\n");
		}
		else
		{
			printf("\n---1 Alta cancelada ---\n");
			printf("\n--- Volviendo al menu principal ---\n\n");
		}
	}
	else
	{
		printf("\n---2 Alta cancelada ---\n");
		printf("\n--- Volviendo al menu principal ---\n\n");
	}

	return retorno;
}

/// @brief Modificar empleado
///
/// @param this Employee*
/// @return int
int employee_editEmployee(Employee* this)
{
	int retorno = -1;
	int opcion;
	int horasTrabajadas;
	int salario;
	char cadena[51];

	if(this != NULL)
	{
		do{
			MenuModificar();
			PedirNumero(&opcion, "Ingrese opcion: ");

			switch(opcion)
			{
			case 0:
				printf("\n--- Volviendo al menu principal ---\n\n");
				break;

			case 1:
				if(PedirNombreConReintentos(cadena, 51, "\nIngrese nombre: ", 3))
				{
					employee_setNombre(this, cadena);
					printf("\n--- Nombre modificado ---\n\n");
				}
				else
				{
					printf("\n--- Modificacion cancelada ---\n\n");
				}
				break;

			case 2:
				if(PedirNumeroCharConReintentos(cadena, "Ingrese cantidad de horas trabajadas: ", 3))
				{
					horasTrabajadas = atoi(cadena);
					employee_setHorasTrabajadas(this, horasTrabajadas);
					printf("\n--- Horas modificadas ---\n\n");
				}
				else
				{
					printf("\n--- Modificacion cancelada ---\n\n");
				}
				break;

			case 3:
				if(PedirNumeroCharConReintentos(cadena, "Ingrese salario: ", 3))
				{
					salario = atoi(cadena);
					employee_setSueldo(this, salario);
					printf("\n--- Salario modificado ---\n\n");
				}
				else
				{
					printf("\n--- Modificacion cancelada ---\n\n");
				}
				break;

			default:
				printf("\n--- Opcion incorrecta ---\n\n");
				break;
			}
			retorno = 0;
		}while(opcion != 0);
	}


	return retorno;
}

/// @brief Listar empleado
///
/// @param this Employee*
/// @return int
int employee_ListEmployee(Employee* this)
{
	int retorno = -1;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;

	if(this != NULL)
	{
		employee_getId(this,&id);
		employee_getNombre(this,nombre);
		employee_getHorasTrabajadas(this,&horasTrabajadas);
		employee_getSueldo(this,&sueldo);

		printf("%4d %18s %20d %20d\n",id,nombre,horasTrabajadas,sueldo);

		retorno = 0;
	}

	return retorno;
}





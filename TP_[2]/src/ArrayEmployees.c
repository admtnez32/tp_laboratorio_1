#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int retorno;
	retorno = -1;


	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}

		retorno = 0;
	}

return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;
	int indice;

	indice = BuscarLugarLibre(list, len);

	if(list != NULL && len > 0 && indice >= 0)
	{
			if(list[indice].isEmpty == TRUE)
			{
				list[indice].id = id-1;
				strncpy(list[indice].name, name, 50);
				strncpy(list[indice].lastName, lastName, 50);
				list[indice].salary = salary;
				list[indice].sector = sector;
				list[indice].isEmpty = FALSE;
				retorno = 0;
			}
	}
	else
	{
		printf("\n--- Error. Array nulo o de tamanio no permitido ---\n\n");
	}

return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	Employee auxList;
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
		{
			for(int i = 0; i < len -1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(order)
					{
						if(strcmpi(list[i].lastName, list[j].lastName) > 0  || (strcmpi(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
						{
							auxList = list[i];
							list[i] = list[j];
							list[j] = auxList;
						}
					}
					else if(strcmpi(list[i].lastName, list[j].lastName) < 0  || (strcmpi(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
					{

								auxList = list[i];
								list[i] = list[j];
								list[j] = auxList;
					}
				}
			}
		}

return retorno;
}

int printEmployee(Employee list)
{
	printf("*  %-5d %-15s %-15s %-17.2f %-4d   *\n", list.id, list.name, list.lastName , list.salary, list.sector);

return 0;
}

int printEmployees(Employee* list, int len)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("*******************************************************************\n*								  *\n");
		printf("*  ID  	 NOMBRE		 APELLIDO	 SALARIO	SECTOR    *\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printEmployee(list[i]);
				retorno = 0;
			}
		}
		printf("*								  *\n*******************************************************************\n");
	}

return retorno;
}

int BuscarLugarLibre(Employee list[], int len)
{
	int retorno = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			retorno = i;
			break;
		}
	}

return retorno;
}

int CargarEmpleado(Employee list[], int len, char nombre[], int tamNombre, char apellido[], int tamApellido, float* salario, int* sector, int* id)
{
	int retorno = 0;
	int auxSector;
	int auxId;
	int indice;
	float auxSalario;

	indice = BuscarLugarLibre(list, len);

	if(indice >= 0){

		if(PedirCaracteresConReintentos(nombre, tamNombre, "Ingrese nombre: ", 3) &&
		   PedirCaracteresConReintentos(apellido, tamApellido, "Ingrese apellido: ", 3) &&
		   PedirFloatConReintentos(&auxSalario, "Ingrese salario: ", 3) &&
		   PedirNumeroConReintentos(&auxSector, "Ingrese sector: ", 3))
		{
			*salario = auxSalario;
			*sector = auxSector;
			auxId = *id + 1;
			*id = auxId;
			retorno = 1;

		}
	}
	else
	{
		printf("\n--- No hay mas lugar en el array ---\n\n");
	}

return retorno;
}

int SolicitarId(Employee listaEmpleados[], int tamEmpleados)
{
	int id;
	int reintentos = 3;
	int retorno = -1;

	do{
			printf("\n\n");
			printEmployees(listaEmpleados, tamEmpleados);

			if(PedirNumero(&id, "\nIngrese id: ") && findEmployeeById(listaEmpleados, tamEmpleados, id) >= 0)
			{
				printf("\n---- Id correcto ---\n");
				retorno = id;
				reintentos = 0;
			}
			else
			{
				printf("\n\n--- Id incorrecto ---\n--- Le quedan %d reintento/s ---\n\n", reintentos-1);
			}
		reintentos--;
	}while(reintentos > 0);

return retorno;
}

int ModificarEmpleado(Employee listaEmpleados[], int tamEmpleados)
{
	int retorno = 1;
	int id;
	int indice;
	int opcion;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;

	id = SolicitarId(listaEmpleados, tamEmpleados);
	indice = findEmployeeById(listaEmpleados, tamEmpleados, id);
	if(id != -1 && indice != -1)
	{
		do{
			printf("\n\n");
			PrintMenu(MODIFICAR);

			if(PedirNumero(&opcion, "Ingrese opcion: "))
			{
				switch(opcion)
				{
				case 1:
					if(PedirCaracteresConReintentos(nombre, 51, "\n\nIngrese nombre: ", 3))
					{
						strcpy(listaEmpleados[indice].name, nombre);
						printf("\n\n--- Nombre modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 2:
					if(PedirCaracteresConReintentos(apellido, 51, "\n\nIngrese apellido: ", 3))
					{
						strcpy(listaEmpleados[indice].lastName, apellido);
						printf("\n\n--- Apellido modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 3:
					if(PedirFloat(&salario, "\n\nIngrese salario: "))
					{
						listaEmpleados[indice].salary = salario;
						printf("\n\n--- Salario modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 4:
					if(PedirNumeroConReintentos(&sector, "\n\nIngrese sector: ", 3))
					{
						listaEmpleados[indice].sector = sector;
						printf("\n\n--- Sector modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 0:
					printf("\n--- Volviendo al menu principal ---\n\n");
					break;

				default:
					printf("\n--- Opcion no valida ---\n\n");
					break;
				}
			}
		}while(opcion != 0);
	}
	else
	{
		retorno = 0;
	}

return retorno;
}

int DarDeBajaEmpleado(Employee listaEmpleados[], int tamEmpleados)
{
	int retorno = 0;
	int id;

		id = SolicitarId(listaEmpleados, tamEmpleados);
		if(id != -1 && removeEmployee(listaEmpleados, tamEmpleados, id) == 0)
		{
			printf("--- Baja exitosa ---\n\n");
			retorno = 1;
		}

return retorno;
}

int VerificarEmpleadosActivos(Employee listaEmpleados[], int tamEmpleados)
{
	int retorno = 0;

	for(int i = 0; i < tamEmpleados; i++)
	{
		if(listaEmpleados[i].isEmpty == FALSE)
		{
			retorno = 1;
			break;
		}
	}

return retorno;
}

float MostrarTotalYPromedioSalarios(Employee listaEmpleados[], int tamEmpleados)
{
	float retorno = 0;
	int contador = 0;
	float acumulador = 0;

	if(listaEmpleados != NULL && tamEmpleados > 0)
	{
		for(int i = 0; i < tamEmpleados; i++)
		{
			if(listaEmpleados[i].isEmpty == FALSE)
			{
				acumulador = acumulador + listaEmpleados[i].salary;
				contador++;
			}
		}
		if(contador > 0)
		{
			retorno = (float)acumulador/contador;
			printf("--- Total de salarios: %.2f\n--- Promedio total: %.2f ---\n", acumulador, retorno);
		}

	}
return retorno;
}

void MostrarListado(Employee listaEmpleados[], int tamEmpleados)
{
	int contador = 0;
	float promedio;

	promedio = MostrarTotalYPromedioSalarios(listaEmpleados, tamEmpleados);

	for(int i=0; i<tamEmpleados; i++)
	{
		if(listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].salary > promedio)
		{
			contador++;
		}
	}

	if(contador > 0)
	{
		printf("--- Cantidad de empleados que superan el salario promedio: %d ---\n\n", contador);
	}
	else
	{
		printf("--- Ningun empleado supera el salario promedio ---\n\n");
	}
}


int MostrarInforme(Employee listaEmpleados[], int tamEmpleados)
{
	int opcion;
	int retorno;
	retorno = 0;

	do{
	PrintMenu(3);
	if(PedirNumeroConReintentosConRango(&opcion, "Ingrese opcion: ", 0, 2, 3))
	{
		switch(opcion)
		{
		case 1:
			sortEmployees(listaEmpleados, tamEmpleados, 1);
			printf("\n\n");
			printEmployees(listaEmpleados, tamEmpleados);
			printf("\n\n");
			break;

		case 2:
			MostrarListado(listaEmpleados, tamEmpleados);
			break;

		case 0:
			printf("\n--- Volviendo al menu principal ---\n\n");
			break;
		}

		retorno = 1;
	}
	}while(opcion != 0);

return retorno;
}


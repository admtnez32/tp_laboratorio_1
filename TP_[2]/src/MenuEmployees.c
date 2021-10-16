#include "MenuEmployees.h"

int MenuPrincipal(void)
{
	printf("*  --- MENU PRINCIPAL ---	*\n*				*\n"
		"*      1- ALTAS			*\n"
	    "*      2-MODIFICAR		*\n"
	    "*      3-BAJA			*\n"
	    "*      4-INFORMAR		*\n*				*"
	    "\n*      0-SALIR			*\n*				*\n");

return 0;
}

int MenuModificar(void)
{
	printf("* --- Que desea modificar? ---  *\n*				*\n"
		"*	1- NOMBRE		*\n"
	    "*	2- APELLIDO		*\n"
	    "*	3- SALARIO		*\n"
	    "*	4- SECTOR		*\n*				*"
	    "\n*	0- MENU PRINCIPAL	*\n*				*\n");
return 0;
}

int MenuInformes(void)
{
	printf("* ---Que listado quiere ver? ---*\n*				*\n"
			"*	1) Empleados ordenados	*\n* alfabéticamente por Apellido	*\n* y Sector			*\n*				*\n"
			"*	2) Total y promedio de	*\n* los salarios, y cuántos	*\n* empleados superan el		*\n* salario promedio		*\n*"
			"				*\n*	0) MENU PRINCIPAL	*\n*				*\n");

return 0;
}

int PrintMenu(int numberMenu)
{
	int retorno;
	retorno = -1;

	printf("*********************************\n*				*\n");
	//printf("-----------------------------\n\n");
	if(numberMenu == PRINCIPAL)
	{
		MenuPrincipal();
		retorno = 0;
	}
	else if(numberMenu == MODIFICAR)
		{
			MenuModificar();
			retorno = 0;
		}
		else
		{
			MenuInformes();
			retorno = 0;
		}
	printf("*********************************\n\n");
	//printf("-----------------------------\n\n");
return retorno;
}


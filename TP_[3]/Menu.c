#include "Menu.h"


void MenuPrincipal(void)
{
	printf("*********************************************************************************\n\n"
		"Menu:\n\n"
		 " 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
		 " 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
		 " 3. Alta de empleado\n"
		 " 4. Modificar datos de empleado\n"
		 " 5. Baja de empleado\n"
		 " 6. Listar empleados\n"
		 " 7. Ordenar empleados\n"
		 " 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
		 " 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n"
		 " 10. Salir\n\n"
		"*********************************************************************************\n\n");
}


void MenuModificar(void)
{
	printf("******************************************\n\n"
			"Modificar:\n\n"
			" 1. Nombre\n"
			" 2. Horas trabajadas\n"
			" 3. Salario\n\n"
			" 0. Menu principal\n\n"
			"******************************************\n\n");
}


void MenuOrdenar(void)
{
	printf("******************************************\n\n"
				"Ordenar por:\n\n"
				" 1. Nombre\n"
				" 2. ID\n"
				" 3. Horas trabajadas\n"
				" 4. Salario\n\n"
				" 0. Menu principal\n\n"
				"******************************************\n\n");
}

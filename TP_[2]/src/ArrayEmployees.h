#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "MenuEmployees.h"
#define TRUE 1
#define FALSE 0

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employee
*
* \param list Employee
* \return 0
*/
int printEmployee(Employee list);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*/
int printEmployees(Employee* list, int length);

/// @fn int BuscarLugarLibre(Employee[], int)
/// @brief busca lugar libre en el array de tipo Employee
///
/// @param list	lista de empleados de tipo Employee
/// @param len	tamanio de la lista
/// @return retorna -1 si no hay lugar libre; si encuentra lugar libre retorna el indice
int BuscarLugarLibre(Employee list[], int len);

/// @fn int CargarEmpleado(Employee[], int, char[], int, char[], int, float*, int*, int*, int)
/// @brief	Cargar un empleado de tipo Employee
///
/// @param list	lista de empleados
/// @param len tamanio de la lista
/// @param nombre	cadena donde guardar nombre
/// @param tamNombre	tamanio de cadena nombre
/// @param apellido	cadena donde guardar apellido
/// @param tamApellido	tamanio de cadena apellido
/// @param salario	puntero a cargar salario flotante
/// @param sector	puntero a cargar sector entero
/// @param id	puntero donde toma id y le suma 1
/// @return	retorna 0 si no pudo cargar el empleado; retorna 1 para todo ok
int CargarEmpleado(Employee list[], int len, char nombre[], int tamNombre, char apellido[], int tamApellido, float* salario, int* sector, int* id);

/// @fn int SolicitarId(Employee[], int)
/// @brief	Pide ID y verifica si existe y se encuentra activo
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
/// @return	retorna -1 si no encontro el ID; retorna el indice en la lista donde se encuentra el ID
int SolicitarId(Employee listaEmpleados[], int tamEmpleados);

/// @fn int ModificarEmpleado(Employee[], int)
/// @brief	Modifica un empleado, el user debe elegir que modificar
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
/// @return retorna 0 si no pudo modificar; retorna 1 para todo ok
int ModificarEmpleado(Employee listaEmpleados[], int tamEmpleados);

/// @fn int DarDeBajaEmpleado(Employee[], int)
/// @brief	Da de baja un empleado
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
/// @return	retorna 0 si no pudo dar de baja; retorna 1 para todo ok
int DarDeBajaEmpleado(Employee listaEmpleados[], int tamEmpleados);

/// @fn int VerificarEmpleadosActivos(Employee[], int)
/// @brief	Verifica si hay al menos un empleado activo
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
/// @return	retorna 0 si no hay empleados activos; retorna 1 si hay al menos un empleado activo
int VerificarEmpleadosActivos(Employee listaEmpleados[], int tamEmpleados);

/// @fn float MostrarTotalYPromedioSalarios(Employee[], int)
/// @brief	Muestra y calcula el total de salarios y el promedio
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
/// @return	retorna 0 si no puede mostrar; retorna el promedio todo ok
float MostrarTotalYPromedioSalarios(Employee listaEmpleados[], int tamEmpleados);

/// @fn void MostrarListado(Employee[], int)
/// @brief	Muestra cantidad de empleados que superan el salario promedio
///
/// @param listaEmpleados	lista de empleados de tipo Employee
/// @param tamEmpleados	tamanio de la lista
void MostrarListado(Employee listaEmpleados[], int tamEmpleados);

/// @fn int MostrarInforme(Employee[], int, int)
/// @brief
///
/// @param listaEmpleados
/// @param tamEmpleados
/// @return
int MostrarInforme(Employee listaEmpleados[], int tamEmpleados);
#endif /* ARRAYEMPLOYEES_H_ */

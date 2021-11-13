#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Menu.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_newParametrosAux(Employee* this, char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

int employee_addEmployee(Employee* this);
int employee_editEmployee(Employee* this);
int employee_delete(Employee* this);
int employee_ListEmployee(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_NextId(char* path, char* id);

int employee_CompareByName(void* empleadoUno, void* empleadoDos);
int employee_CompareById(void* empleadoUno, void* empleadoDos);
int employee_CompareByHoursWorked(void* empleadoUno, void* empleadoDos);
int employee_CompareBySalary(void* empleadoUno, void* empleadoDos);
#endif // employee_H_INCLUDED

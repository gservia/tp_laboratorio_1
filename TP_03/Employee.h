
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "input_validation.h"

#define NOMBRE_LEN 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

int employee_findById(LinkedList* listEmployee, int id);
int employee_load(Employee* pEmployee);
int employee_edit(Employee* pEmployee);
int employee_print(Employee* pEmployee);
int employee_compare(void* pEmployeeA, void* pEmployeeB);

#endif // employee_H_INCLUDED

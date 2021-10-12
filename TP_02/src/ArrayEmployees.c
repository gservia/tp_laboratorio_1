/*
 * ArrayEmployees.c
 * Author: Gabriel Servia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

static int getNewId(void);

/**
 * \brief Options Menu. Request a option to user
 * \return Return selected option
 */
char menuEmployees()
{
	char option;
	char optionAux;

	printf("\n=========== MENU ===========\n");
	printf("1. ALTA de empleado.\n");
	printf("2. MODIFICAR un empleado.\n");
	printf("3. BAJA de empleado.\n");
	printf("4. INFORMES:\n");
	printf("   A. Lista de empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf("   B. Total y promedio de los salarios. Cantidad de empleados que superan el salario promedio.\n");
	printf("5. Salir del sistema.\n");

	if (utn_getText(&optionAux, 2, "\nINGRESAR UNA OPCION: ", "ERROR: Comando no valido.\n", 0) == 0)
	{
		option = optionAux;
	}
	return option;
}


/**
 * \brief To indicate that all position in the array are empty
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 *
 */
int initEmployees(Employee* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		state = 0;
	}

	return state;
}


/**
 * \brief Find empty place in array
 * \param
 * \param
 * \param
 * \return
 */
int findEmptyPlaceEmployees(int* emptyPlace, Employee* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 1)
			{
				*emptyPlace = i;
				state = 0;
				break;
			}
		}
	}
	return state;
}


/**
 * \brief Add in a existing list of employees the values received as parameters in the first empty position
 * \param pEmployee Pointer to a Employee struct
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int addEmployees(Employee* pEmployee)
{
	int state = -1;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;

	if (pEmployee != NULL)
	{
		puts("\nALTA");
		if (utn_getName(nameAux, 51, "INGRESAR NOMBRE: ", "ERROR: Solo se aceptan letras en este campo.\n", 0) == 0)
		{
			if (utn_getName(lastNameAux, 51, "INGRESAR APELLIDO: ", "ERROR: Solo se aceptan letras en este campo.\n", 0) == 0)
			{
				if (utn_getFloat(&salaryAux, "INGRESAR SALARIO: ", "ERROR: Solo se aceptan numeros en este campo.\n", 0, 999999, 0) == 0)
				{
					if (utn_getInt(&sectorAux, "SECTORES:\n 1. Administracion\n 2. Contabilidad\n 3. Logistica\n 4. Produccion\n 5. Recursos humanos\n"
							"SELECCIONAR OPCION DEL SECTOR: ", "ERROR: Solo se aceptan opciones del 1 al 5 en este campo.\n", 1, 5, 0) == 0)
					{
						pEmployee->id = getNewId();
						strncpy(pEmployee->name, nameAux, sizeof(pEmployee->name));
						strncpy(pEmployee->lastName, lastNameAux, sizeof(pEmployee->lastName));
						pEmployee->salary = salaryAux;
						pEmployee->sector = sectorAux;
						pEmployee->isEmpty = 0;
						state = 0;
					}
				}
			}
		}
	}
	return state;
}


/**
 * \brief Create a new ID number
 */
static int getNewId(void) // Privada del archivo
{
	static int counter = 1; // Es global. Mantiene su valor
	return (counter++);
}


/**
 * \brief Print the content of employees array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int printEmployees(Employee* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		printf("ID	| APELLIDO		| NOMBRE		| SALARIO		| SECTOR\n");
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				printf("%d	| %s		| %s		| $ %.2f		| %d\n", list[i].id, list[i].lastName,
						list[i].name, list[i].salary, list[i].sector);
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Find an Employee by Id and returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeesById(Employee* list, int len, int idToFind)
{
	int position = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == idToFind && list[i].isEmpty == 0)
			{
				position = i;
				break;
			}
		}
	}
	return position;
}


/**
 * \brief Edit an employee in an existing list of employees
 * \param pEmployee Pointer to a Employee struct
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int editEmployees(Employee* pEmployee)
{
	int state = -1;
	char option;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int flagContinue;

	flagContinue = 1;

	if (pEmployee != NULL && pEmployee->isEmpty == 1)
	{
		puts("\nMODIFICACION");

		do {
			printf("SELECCIONE EL CAMPO A EDITAR:\n");
			printf(" 1. Nombre\n 2. Apellido\n 3. Salario\n 4. Sector\n");

			utn_getText(&option, 2, "\nINGRESE LA OPCION: ", "ERROR: Comando no valido.\n", 0);

			switch (option)
			{
				case '1':
					if (utn_getName(nameAux, 51, "INGRESAR NOMBRE: ", "ERROR: Solo se aceptan letras en este campo.\n", 0) == 0)
					{
						strncpy(pEmployee->name, nameAux, sizeof(pEmployee->name));
						state = 0;
					}
					break;
				case '2':
					if (utn_getName(lastNameAux, 51, "INGRESAR APELLIDO: ", "ERROR: Solo se aceptan letras en este campo.\n", 0) == 0)
					{
						strncpy(pEmployee->lastName, lastNameAux, sizeof(pEmployee->lastName));
						state = 0;
					}
					break;
				case '3':
					if (utn_getFloat(&salaryAux, "INGRESAR SALARIO: ", "ERROR: Solo se aceptan numeros en este campo.\n", 0, 999999, 0) == 0)
					{
						pEmployee->salary = salaryAux;
						state = 0;
					}
					break;
				case '4':
					if (utn_getInt(&sectorAux, "SECTORES:\n 1. Administracion\n 2. Contabilidad\n 3. Logistica\n 4. Produccion\n 5. Recursos humanos\n"
								"SELECCIONAR OPCION DEL SECTOR: ", "ERROR: Solo se aceptan opciones del 1 al 5 en este campo.\n", 1, 5, 0) == 0)
					{
						pEmployee->sector = sectorAux;
						state = 0;
					}
					break;
				default:
					printf("Elija una opcion entre 1 y 4. Vuelva intentar.\n");
			}

			utn_getInt(&flagContinue, "¿Desea continuar editando?\n 1. Si\n 2. No\nSeleccione una opcion: ", "ERROR: Comando no valido", 1, 2, 0);

		} while (flagContinue == 1);

	}
	return state;
}


/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param pEmployee Pointer to a Employee struct
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if OK
 */
int removeEmployees(Employee* pEmployee)
{
	int state = -1;
	int flagContinue;

	flagContinue = 2;

	if (pEmployee != NULL)
	{
		puts("\nBAJA");
		utn_getInt(&flagContinue, "¿Esta seguro que quiere dar de baja a este usuario?\n 1. Si\n 2. No\nSeleccione una opcion: ",
					"ERROR: Comando no valido", 1, 2, 0);

		if (flagContinue == 1)
		{
			pEmployee->isEmpty = 1;
			state = 0;
		}
	}
	return state;
}

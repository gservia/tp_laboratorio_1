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
 * \param int* emptyPlace
 * \param Employee* list
 * \param int len
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
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
int loadEmployeeData(Employee* pEmployee)
{
	int state = -1;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;

	if (pEmployee != NULL)
	{
		puts("\nCARGA DE DATOS");
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
						state = 0;
					}
				}
			}
		}
	}
	return state;
}


/** \brief Add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int state = -1;
	int firstEmptyPlace;

	if (findEmptyPlaceEmployees(&firstEmptyPlace, list, len) == 0)
	{
		list[firstEmptyPlace].id = id;
		strncpy(list[firstEmptyPlace].name, name, sizeof(list[firstEmptyPlace].name));
		strncpy(list[firstEmptyPlace].lastName, lastName, sizeof(list[firstEmptyPlace].lastName));
		list[firstEmptyPlace].salary = salary;
		list[firstEmptyPlace].sector = sector;
		list[firstEmptyPlace].isEmpty = 0;
		state = 0;
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
int printEmployees(Employee* list, int length)
{
	int state = -1;
	int i;

	if (list != NULL && length > 0)
	{
		printf("ID	| APELLIDO		| NOMBRE		| SALARIO		| SECTOR\n");
		for (i = 0; i < length; i++)
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
int findEmployeeById(Employee* list, int len, int id)
{
	int position = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
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

	if (pEmployee != NULL)
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
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if OK
 */
int removeEmployee(Employee* list, int len, int id)
{
	int state = -1;
	int position;
	int flagContinue;

	flagContinue = 2;

	if (list != NULL && len > 0)
	{
		position = findEmployeeById(list, len, id);

		puts("\nBAJA");
		utn_getInt(&flagContinue, "¿Esta seguro que quiere dar de baja a este usuario?\n 1. Si\n 2. No\nSeleccione una opcion: ",
						"ERROR: Comando no valido", 1, 2, 0);

		if (flagContinue == 1)
		{
			list[position].isEmpty = 1;
			state = 0;
		}
	}
	return state;
}

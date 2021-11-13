#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int state = -1;
	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		if (parser_EmployeeFromText(f, pArrayListEmployee) == 0)
		{
			state = 0;
		}
		fclose(f);
	}
    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int state = -1;
	FILE* f = fopen(path, "rb");

	if (f != NULL)
	{
		if (parser_EmployeeFromBinary(f, pArrayListEmployee) == 0)
		{
			state = 0;
		}
		fclose(f);
	}
    return state;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int state = -1;
	int idAux;
	int flagIdLoaded;
	Employee* pEmployeeAux;

	pEmployeeAux = employee_new();

	flagIdLoaded = -1;

	if (pEmployeeAux != NULL)
	{
		printf("\nALTA DE EMPLEADO\n");

		if (controller_getLastIdFromFile("idMaxInput.csv", &idAux) == 0) // Busca el ultimo ID ingresado al sistema
		{
			flagIdLoaded = 0;
		}
		else
		{
			if (controller_createIdMaxFile("idMaxInput.csv") == 0) // Si no encuentra archivo de ID, lo crea iniciando en 1001
			{
				if (controller_getLastIdFromFile("idMaxInput.csv", &idAux) == 0)
				{
					flagIdLoaded = 0;
				}
			}
		}

		if (flagIdLoaded == 0)
		{
			if (employee_load(pEmployeeAux) == 0)
			{
				if (employee_setId(pEmployeeAux, idAux) == 0)
				{
					ll_add(pArrayListEmployee, pEmployeeAux);
					controller_increaseIdMaxInFile("idMaxInput.csv", idAux);
					state = 0;
				}
			}
		}
	}
    return state;
}

/** \brief Aumentar en 1 el ultimo ID creado en archivo
 *
 * \param path char*
 * \param id int
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_increaseIdMaxInFile(char* path, int id)
{
	int state = -1;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		id++;
		fprintf(f, "%d\n", id);
		fclose(f);
		state = 0;
	}
    return state;
}

/** \brief Crear archivo en primera ejecucion con ID iniciado en 1001
 *
 * \param path char*
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_createIdMaxFile(char* path)
{
	int state = -1;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		fprintf(f, "1001\n");
		fclose(f);
		state = 0;
	}
    return state;
}

/** \brief Lee el ultimo ID ingresado el sistema
 *
 * \param path char*
 * \param id int*
 * \return Retorna 0 si tuvo exito
 *
 */
int controller_getLastIdFromFile(char* path, int* id)
{
	int state = -1;
	char idTxt[128];

	// "IdMaxInput.csv"
	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		if (fscanf(f, "%[^\n]\n", idTxt) == 1)
		{
			*id = atoi(idTxt);
			state = 0;
		}
	}
	fclose(f);
	return state;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int state = -1;
	int idToEdit;
	int position;
	Employee* pEmployeeAux;

	if (pArrayListEmployee != NULL)
	{
		if (controller_ListEmployee(pArrayListEmployee) == 0)
		{
			if (utn_getInt(&idToEdit, "\nIngresar el ID del empleado a modificar: ", "Error: comando no valido\n", 1, 999999, 0) == 0)
			{
				position = employee_findById(pArrayListEmployee, idToEdit);
				if (position > -1)
				{
					pEmployeeAux = ll_get(pArrayListEmployee, position);

					if (pEmployeeAux != NULL)
					{
						if (employee_edit(pEmployeeAux) == 0)
						{
							state = 0;
						}
					}
					else
					{
						printf("\n=== ID ingresado inexistente ===\n");
					}

				}
				else
				{
					printf("\n=== ID ingresado inexistente ===\n");
				}
			}
		}
	}
    return state;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int state = -1;
	int idToEdit;
	int position;
	int confirm;
	Employee* pEmployeeAux;

	if (pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		if (utn_getInt(&idToEdit, "\nIngresar el ID del empleado a dar de baja: ", "Error: comando no valido\n", 1, 999999, 0) == 0)
		{
			position = employee_findById(pArrayListEmployee, idToEdit);
			if (position > -1)
			{
				pEmployeeAux = ll_get(pArrayListEmployee, position);

				if (pEmployeeAux != NULL)
				{
					if (utn_getInt(&confirm, "\n¿Estas seguro que quieres eliminar a este empleado? Toda su informacion sera eliminada\n 1. Si\n 2. No\nIngrese una opcion: ",
								"Error: comando no valido\n", 1, 2, 0) == 0)
					{
						switch (confirm)
						{
							case 1:
								ll_remove(pArrayListEmployee, position);
								employee_delete(pEmployeeAux);
								state = 0;
								break;
							case 2:
								printf("\n=== Baja cancelada ===\n");
								break;
						}
					}
				}
				else
				{
					printf("\n=== ID ingresado inexistente ===\n");
				}
			}
			else
			{
				printf("\n=== ID ingresado inexistente ===\n");
			}
		}
	}
    return state;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int state = -1;
	int i;
	int len;
	Employee* pEmployeeAux;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if (len > 0)
		{
			printf("ID	| NOMBRE 	| HORAS TRABAJADAS	| SUELDO\n");

			for (i = 0; i < len; i++)
			{
				pEmployeeAux = ll_get(pArrayListEmployee, i);
				if (pEmployeeAux != NULL)
				{
					employee_print(pEmployeeAux);
				}
			}
			state = 0;
		}
		else
		{
			printf("=== No hay elementos en la lista ===\n");
		}
	}
    return state;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int state = -1;
	int option;
	int criteria;

	if (pArrayListEmployee != NULL)
	{
		if (utn_getInt(&option, "Ordenar lista por ID\n 1. Ascendente\n 2. Descendente\nIngresar la opcion deseada: ", "Error: comando no valido", 1, 2, 0) == 0)
		{
			if (option == 1)
			{
				criteria = 1;
			}
			else if (option == 2)
			{
				criteria = 0;
			}
			if (ll_sort(pArrayListEmployee, employee_compare, criteria) == 0)
			{
				state = 0;
			}
		}
	}
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int state = -1;
	int i;
	Employee* pEmployeeAux;

	FILE* f = fopen(path, "w");

	if (f != NULL)
	{
		fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployeeAux = ll_get(pArrayListEmployee, i);
			fprintf(f, "%d,%s,%d,%d\n", pEmployeeAux->id, pEmployeeAux->nombre, pEmployeeAux->horasTrabajadas, pEmployeeAux->sueldo);
		}
		state = 0;
		fclose(f);
	}
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}




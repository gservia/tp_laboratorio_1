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
	Employee* pEmployeeAux;

	pEmployeeAux = employee_new();

	if (pEmployeeAux != NULL)
	{
		printf("ALTA DE EMPLEADO\n");

		// Trabajar el ID maximo
		idAux = 1001;

		if (employee_load(pEmployeeAux) == 0)
		{
			if (employee_setId(pEmployeeAux, idAux) == 0)
			{
				ll_add(pArrayListEmployee, pEmployeeAux);
				state = 0;
			}
		}
	}
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
		controller_ListEmployee(pArrayListEmployee);

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
		}
		else
		{
			printf("=== No hay elementos en la lista ===\n");
		}
		state = 0;
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
			//8,Henrieta,90,30000
			//printf("Nombre: %s sueldo:%d\n",pEaux->nombre,pEaux->sueldo);
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


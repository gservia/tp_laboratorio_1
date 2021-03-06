#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int state = -1;
	Employee* pEmployeeAux;
	char idAux[256];
	char nombreAux[128];
	char horasAux[256];
	char sueldoAux[256];

	if (pFile !=NULL && pArrayListEmployee !=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux); // Saltea encabezado

		do
		{
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux) == 4)
			{
				pEmployeeAux = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);

				if(pEmployeeAux != NULL)
				{
					ll_add(pArrayListEmployee, pEmployeeAux);
					state = 0;
				}
			}
			else
			{
				employee_delete(pEmployeeAux);
				break;
			}
		} while (feof(pFile) == 0);
	}

    return state;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int state = -1;

	Employee* pEmployeeAux;

	if (pFile !=NULL && pArrayListEmployee !=NULL)
	{
		do
		{
			 pEmployeeAux = employee_new();

			 if (pEmployeeAux != NULL)
			 {
				 if (fread(pEmployeeAux, sizeof(Employee), 1, pFile) == 1)
				 {
					 ll_add(pArrayListEmployee, pEmployeeAux);
					 state = 0;
				 }
				 else
				 {
					 employee_delete(pEmployeeAux);
					 break;
				 }
			 }
		} while (feof(pFile) == 0);
	}
    return state;
}

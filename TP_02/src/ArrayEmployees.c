/*
 * ArrayEmployees.c
 * Author: Gabriel Servia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"


/**
 * \brief To indicate that all position in the array are empty
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int estado = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		estado = 0;
	}

	return estado;
}



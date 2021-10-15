/*
 * reports.c
 * Author: Gabriel Servia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"


/**
 * \brief Sort the elements in the array of employees by last name and sector, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int sortEmployees(Employee* list, int len, int order)
{
	int state = -1;
	Employee employeeAux;
	int i;
	int j;

	if (list != NULL && len > 0)
	{
		switch (order)
		{
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if (strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								// Son iguales. Ordeno por sector
								if (list[i].sector > list[j].sector)
								{
									employeeAux = list[i];
									list[i] = list[j];
									list[j] = employeeAux;
								}
							}
							else
							{
								if (strcmp(list[i].lastName, list[j].lastName) > 0)
								{
									employeeAux = list[i];
									list[i] = list[j];
									list[j] = employeeAux;
								}
							}
						}
					}
				}
				state = 0;
				break;
			case 0:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if (strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								// Son iguales. Ordeno por sector
								if (list[i].sector < list[j].sector)
								{
									employeeAux = list[i];
									list[i] = list[j];
									list[j] = employeeAux;
								}
							}
							else
							{
								if (strcmp(list[i].lastName, list[j].lastName) < 0)
								{
									employeeAux = list[i];
									list[i] = list[j];
									list[j] = employeeAux;
								}
							}
						}
					}
				}
				state = 0;
				break;
			default:
				break;
		}
	}
	return state;
}


/**
 * \brief Sort the elements in the array of employees by ID, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int sortById(Employee* list, int len, int order)
{
	int state = -1;
	Employee employeeAux;
	int i;
	int j;

	if (list != NULL && len > 0)
	{
		switch (order)
		{
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if (list[i].id > list[j].id)
							{
								employeeAux = list[i];
								list[i] = list[j];
								list[j] = employeeAux;
							}
						}
					}
				}
				state = 0;
				break;
			case 0:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if (list[i].id < list[j].id)
							{
								employeeAux = list[i];
								list[i] = list[j];
								list[j] = employeeAux;
							}
						}
					}
				}
				state = 0;
				break;
			default:
				break;
		}
	}
	return state;
}


/**
 * \brief Calculates total salaries and average
 * \param list Employee*
 * \param len int
 * \param pTotal
 * \param pAverage
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int totalAndAverageSalaries(Employee* list, int len, float* pTotal, float* pAverage)
{
	int state = -1;
	int i;
	int counter;
	float totalAux;
	float avgAux;

	counter = 0;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				totalAux += list[i].salary;
				counter++;
			}
		}

		avgAux = totalAux / counter;

		*pTotal = totalAux;
		*pAverage = avgAux;
		state = 0;
	}
	return state;
}


/**
 * \brief Calculates total salaries and average
 * \param list Employee*
 * \param len int
 * \param pQuantity
 * \param average
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int employeesOverAvgSalary(Employee* list, int len, int* pQuantity, float average)
{
	int state = -1;
	int i;
	int counter;

	counter = 0;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				if (list[i].salary > average)
				{
					counter++;
				}
			}
		}
		*pQuantity = counter;
		state = 0;
	}
	return state;
}


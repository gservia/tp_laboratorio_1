/*
 * menu.c
 * Author: Gabriel Servia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Options Menu. Request a option to user
 * \return Return selected option
 */
char menu()
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

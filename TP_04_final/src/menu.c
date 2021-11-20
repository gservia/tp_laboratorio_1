/*
 * menu.c
 * Author: Gabriel Servia
 */
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

/**
 * \brief Options Menu. Request a option to user
 * \return Return selected option
 */
int menu()
{
	int option;
	int optionAux;

	printf("\n  ==============================  MENU  ==============================\n");
	printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	printf(" 3. Alta de empleado\n");
	printf(" 4. Modificar datos de empleado\n");
	printf(" 5. Baja de empleado\n");
	printf(" 6. Listar empleados\n");
	printf(" 7. Ordenar empleados\n");
	printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
	printf("10. Salir\n");

	if (utn_getInt(&optionAux, "\nINGRESAR UNA OPCION: ", "ERROR: Comando no valido.\n", 1, 10, 0) == 0)
	{
		option = optionAux;
	}
	return option;
}

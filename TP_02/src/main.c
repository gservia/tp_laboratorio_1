/*
 ============================================================================
 Project     : TP_02
 Author      : Gabriel Servia
 Division    : 1° H
 University  : UTN FRA
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define EMPLOYEES_LEN 1000  // La nonima bajo ninguna circustancia superara los 1000 empleados

int main(void) {

	setbuf(stdout, NULL);

	Employee employeeList[EMPLOYEES_LEN]; // Lista de empleados con maximo de 1000 empleados
	char optionSelected;
	int flagContinue;
	int emptyPlace;
	int idToFind;
	int lastId;
	int position;

	flagContinue = 0;

	initEmployees(employeeList, EMPLOYEES_LEN);

	puts("=== ADMINISTRACION DE EMPLEADOS ===");

	do {
		optionSelected = menuEmployees();
		switch (optionSelected)
		{
			case '1':
				if (findEmptyPlaceEmployees(&emptyPlace, employeeList, EMPLOYEES_LEN) == 0)
				{
					if (addEmployees(&employeeList[emptyPlace]) == 0)
					{
						printf("\n=== Alta de empleado satisfatoria ===\n");
						lastId = employeeList[emptyPlace].id;
					}
					else
					{
						printf("\n=== Error en alta de empleado ===\n");
					}
				}
				else
				{
					printf("La lista de empleados esta completa. No es posible sumar empleados.\n");
				}
				break;
			case '2':
				printEmployees(employeeList, EMPLOYEES_LEN);

				if (utn_getInt(&idToFind, "\nINGRESE EL ID QUE DESEA MODIFICAR: ", "ERROR: El ID ingresado no existe.\n", 1, lastId, 0) == 0)
				{
					position = findEmployeesById(employeeList, EMPLOYEES_LEN, idToFind);
					if (employeeList[position].isEmpty = 0)
					{
						if (editEmployees(&employeeList[position]) == 0)
						{
							printf("\n=== Modificacion de empleado satisfatoria ===\n");
						}
						else
						{
							printf("\n=== Error en modificacion de empleado ===\n");
						}
					}
					else
					{
						printf("\n=== ERROR: El ID ingresado no existe o fue dado de baja ===\n");
					}
				}
				break;
			case '3':
				printEmployees(employeeList, EMPLOYEES_LEN);

				if (utn_getInt(&idToFind, "\nINGRESE EL ID QUE DESEA DAR DE BAJA: ", "ERROR: El ID ingresado no existe.\n", 1, lastId, 0) == 0)
				{
					position = findEmployeesById(employeeList, EMPLOYEES_LEN, idToFind);
					if (removeEmployees(&employeeList[position]) == 0)
					{
						printf("\n=== Baja de empleado satisfatoria ===\n");
					}
					else
					{
						printf("\n=== Baja de empleado cancelada ===\n");
					}
				}
				break;
			case '4':
				printf("Informes.\n");
				printEmployees(employeeList, EMPLOYEES_LEN);
				break;
			case '5':
				flagContinue = 1;
				break;
			default:
				printf("Elija una opcion entre 1 y 5. Vuelva intentar.\n");
		}
	} while (flagContinue == 0);

	puts("=== PROGRAMA FINALIZADO ===");

	return EXIT_SUCCESS;
}

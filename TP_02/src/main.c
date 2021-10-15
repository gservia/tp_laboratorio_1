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
#include "menu.h"
#include "reports.h"

#define EMPLOYEES_LEN 1000  // La nonima bajo ninguna circustancia superara los 1000 empleados

int main(void) {

	setbuf(stdout, NULL);

	Employee employeeList[EMPLOYEES_LEN]; // Lista de empleados con maximo de 1000 empleados
	char optionSelected;
	int flagContinue;
	int flagEmployeeAdded;
	int emptyPlace;
	int idToFind;
	int lastId;
	int position;
	float totalSalaries;
	float averageSalary;
	int qtyEmployeesOverAvgSalary;

	flagContinue = 0;
	flagEmployeeAdded = 0;

	initEmployees(employeeList, EMPLOYEES_LEN);

	puts("=== ADMINISTRACION DE EMPLEADOS ===");

	do {
		optionSelected = menu();
		switch (optionSelected)
		{
			case '1':
				if (findEmptyPlaceEmployees(&emptyPlace, employeeList, EMPLOYEES_LEN) == 0)
				{

					Employee employeeAux;
					if (loadEmployeeData(&employeeAux) == 0)
					{
						if (addEmployee(employeeList, EMPLOYEES_LEN, employeeAux.id, employeeAux.name, employeeAux.lastName,
								employeeAux.salary, employeeAux.sector) == 0)
						{
							printf("\n=== Alta de empleado satisfatoria ===\n");
							lastId = employeeList[emptyPlace].id;
							flagEmployeeAdded++;
						}
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
				if (flagEmployeeAdded > 0)
				{
					// Criterio 1: Ordena por ID de forma ascendente:
					sortById(employeeList, EMPLOYEES_LEN, 1);
					printEmployees(employeeList, EMPLOYEES_LEN);

					if (utn_getInt(&idToFind, "\nINGRESE EL ID QUE DESEA MODIFICAR: ", "ERROR: El ID ingresado no existe.\n", 1, lastId, 0) == 0)
					{
						position = findEmployeeById(employeeList, EMPLOYEES_LEN, idToFind);
						if (employeeList[position].isEmpty == 0)
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
				}
				else
				{
					printf("\n=== No hay empleados dados de alta ===\n");
				}
				break;
			case '3':
				if (flagEmployeeAdded > 0)
				{
					// Criterio 1: Ordena por ID de forma ascendente:
					sortById(employeeList, EMPLOYEES_LEN, 1);
					printEmployees(employeeList, EMPLOYEES_LEN);

					if (utn_getInt(&idToFind, "\nINGRESE EL ID QUE DESEA DAR DE BAJA: ", "ERROR: El ID ingresado no existe.\n", 1, lastId, 0) == 0)
					{
						if (removeEmployee(employeeList, EMPLOYEES_LEN, idToFind) == 0)
						{
							printf("\n=== Baja de empleado satisfatoria ===\n");
							flagEmployeeAdded--;
						}
						else
						{
							printf("\n=== Baja de empleado cancelada ===\n");
						}
					}
				}
				else
				{
					printf("\n=== No hay empleados dados de alta ===\n");
				}
				break;
			case '4':
				if (flagEmployeeAdded > 0)
				{
					printf("\nINFORMES:\n");
					printf("\nLISTA DE EMPLEADOS\n");
					// Criterio 1: Ordena alfabeticamente por apellido de forma descendente y luego por sector:
					sortEmployees(employeeList, EMPLOYEES_LEN, 1);
					printEmployees(employeeList, EMPLOYEES_LEN);

					totalAndAverageSalaries(employeeList, EMPLOYEES_LEN, &totalSalaries, &averageSalary);
					printf("\nTOTAL DE LOS SALARIOS: $ %.2f\n", totalSalaries);
					printf("\nPROMEDIO DE LOS SALARIOS: $ %.2f\n", averageSalary);

					employeesOverAvgSalary(employeeList, EMPLOYEES_LEN, &qtyEmployeesOverAvgSalary, averageSalary);
					printf("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d\n", qtyEmployeesOverAvgSalary);
				}
				else
				{
					printf("\n=== No hay empleados dados de alta ===\n");
				}
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

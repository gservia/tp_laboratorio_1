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

#define EMPLOYEES_LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	Employee employeeList[EMPLOYEES_LEN];

	initEmployees(employeeList, EMPLOYEES_LEN);






	return EXIT_SUCCESS;
}

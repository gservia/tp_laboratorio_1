/*
 * ArrayEmployees.h
 * Author: Gabriel Servia
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty; // 0: Load | 1: Empty
}Employee;

int initEmployees(Employee* list, int len);

char menuEmployees();

int findEmptyPlaceEmployees(int* emptyPlace, Employee* list, int len);

int addEmployees(Employee* pEmployee);

int printEmployees(Employee* list, int len);

int findEmployeesById(Employee* list, int len, int idToFind);

int editEmployees(Employee* pEmployee);

int removeEmployees(Employee* pEmployee);

#endif /* ARRAYEMPLOYEES_H_ */

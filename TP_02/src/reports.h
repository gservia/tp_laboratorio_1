/*
 * reports.h
 * Author: Gabriel Servia
 */

#ifndef REPORTS_H_
#define REPORTS_H_

int sortEmployees(Employee* list, int len, int order);

int sortById(Employee* list, int len, int order);

int totalAndAverageSalaries(Employee* list, int len, float* pTotal, float* pAverage);

int employeesOverAvgSalary(Employee* list, int len, int* pQuantity, float average);

#endif /* REPORTS_H_ */

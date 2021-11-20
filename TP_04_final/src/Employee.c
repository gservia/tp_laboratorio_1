
#include "Employee.h"


/**
 * \brief Creates memory space for one Employee
 * \return pEmployee Pointer to an Employee
 */
Employee* employee_new()
{
	Employee* pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}


/**
 * \brief Employee setting parametres
 * \param idStr
 * \param nombreStr
 * \param horasTrabajadasStr
 * \param sueldoStr
 * \return pEmployee Pointer to an Employee
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = NULL;
	pEmployee = employee_new();

	if (idStr != NULL && esNumerica(idStr, sizeof(idStr)) == 1 && nombreStr != NULL && horasTrabajadasStr != NULL &&
			esNumerica(horasTrabajadasStr, sizeof(idStr)) == 1 && sueldoStr != NULL && esNumerica(sueldoStr, sizeof(idStr)) == 1)
	{
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee, nombreStr);
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}
	return pEmployee;
}

/**
 * \brief Delete memory space of one Employee
 * \param this Pointer to Employee
 */
void employee_delete(Employee* this)
{
	if (this != NULL)
	{
		free(this);
	}
}


/**
 * \brief Setter id
 * \param this Employee*
 * \param id int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_setId(Employee* this, int id)
{
	int state = -1;

	if (this != NULL && id >= 0)
	{
		this->id = id;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter id
 * \param this Employee*
 * \param id int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_getId(Employee* this, int* id)
{
	int state = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter nombre
 * \param this Employee*
 * \param nombre int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_setNombre(Employee* this, char* nombre)
{
	int state = -1;

	if (this != NULL && nombre != NULL)
	{
		if (esNombre(nombre, 128) == 1)
		{
			strncpy(this->nombre, nombre, 128);
			state = 0;
		}
	}
	return state;
}


/**
 * \brief Getter nombre
 * \param this Employee*
 * \param nombre int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_getNombre(Employee* this, char* nombre)
{
	int state = -1;

	if (this != NULL && nombre != NULL)
	{
			strncpy(nombre, this->nombre, NOMBRE_LEN);
			state = 0;
	}
	return state;
}


/**
 * \brief Setter horasTrabajadas
 * \param this Employee*
 * \param horasTrabajadas int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int state = -1;

	if (this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter horasTrabajadas
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int state = -1;

	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		state = 0;
	}
	return state;
}


/**
 * \brief Setter sueldo
 * \param this Employee*
 * \param sueldo int
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_setSueldo(Employee* this, int sueldo)
{
	int state = -1;

	if (this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		state = 0;
	}
	return state;
}


/**
 * \brief Getter sueldo
 * \param this Employee*
 * \param sueldo int*
 * \return Returns 0 if it OK, or -1 if it gives an Error
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
	int state = -1;

	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		state = 0;
	}
	return state;
}


/**
 * \brief Finds an Employee by ID
 * \param listEmployee LinkedList*
 * \param id to find
 * \return Returns position if it's found, or -1 if it's not [Error]
 */
int employee_findById(LinkedList* listEmployee, int id)
{
	int position = -1;
	int i;
	int listLen;
	Employee* pEmployeeAux;

	if (listEmployee != NULL && id > 0)
	{
		listLen = ll_len(listEmployee);

		for (i = 0; i < listLen; i++)
		{
			pEmployeeAux = ll_get(listEmployee, i);

			if (pEmployeeAux->id == id)
			{
				position = i;
				break;
			}
		}
	}
	return position;
}


/**
 * \brief Load data of one Employee
 * \param pEmployee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int employee_load(Employee* pEmployee)
{
	int state = -1;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	if (utn_getName(nombreAux, NOMBRE_LEN, "Ingresar nombre: ", "Error en la carga del nombre\n", 0) == 0)
	{
		if (utn_getInt(&horasTrabajadasAux, "Ingresar cantidad de horas trabajadas: ", "Error en la carga de las horas\n", 0, 99999999, 0) == 0)
		{
			if (utn_getInt(&sueldoAux, "Ingresar sueldo: ", "Error en la carga del sueldo\n", 0, 999999999, 0) == 0)
			{
				employee_setNombre(pEmployee, nombreAux);
				employee_setHorasTrabajadas(pEmployee, horasTrabajadasAux);
				employee_setSueldo(pEmployee, sueldoAux);
				state = 0;
			}
		}
	}
	return state;
}


/**
 * \brief Print one Employee
 * \param pEmployee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int employee_print(Employee* pEmployee)
{
	int state = -1;
	int idAux;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	if (pEmployee != NULL)
	{
		employee_getId(pEmployee, &idAux);
		employee_getNombre(pEmployee, nombreAux);
		employee_getHorasTrabajadas(pEmployee, &horasTrabajadasAux);
		employee_getSueldo(pEmployee, &sueldoAux);

		printf("%d	| %s	| %d	| %d\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
		state = 0;
	}

	return state;
}

/**
 * \brief Edit data of one Employee
 * \param pEmployee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int employee_edit(Employee* pEmployee)
{
	int state = -1;
	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;
	int option;

	do {
		printf("¿Que campo desea modificar?\n 1. Nombre\n 2. Horas trabajadas\n 3. Sueldo\n 4. Finalizar y regresar al menu\n");

		if (utn_getInt(&option, "Ingresar la opcion deseada: ", "Error: comando no valido\n", 1, 4, 0) == 0)
		{
			switch (option)
			{
				case 1:
					if (utn_getName(nombreAux, NOMBRE_LEN, "Ingresar nombre: ", "Error en la carga del nombre\n", 0) == 0)
					{
						employee_setNombre(pEmployee, nombreAux);
						printf("\n=== Nombre modificado con exito ===\n\n");
						state = 0;
					}
					else
					{
						state = -1;
					}
					break;
				case 2:
					if (utn_getInt(&horasTrabajadasAux, "Ingresar cantidad de horas trabajadas: ", "Error en la carga de las horas\n", 0, 999, 0) == 0)
					{
						employee_setHorasTrabajadas(pEmployee, horasTrabajadasAux);
						printf("\n=== Horas trabajadas modificadas con exito ===\n\n");
						state = 0;
					}
					else
					{
						state = -1;
					}
					break;
				case 3:
					if (utn_getInt(&sueldoAux, "Ingresar sueldo: ", "Error en la carga del sueldo\n", 0, 999999999, 0) == 0)
					{
						employee_setSueldo(pEmployee, sueldoAux);
						printf("\n=== Sueldo modificado con exito ===\n\n");
						state = 0;
					}
					else
					{
						state = -1;
					}
					break;
				case 4:
					printf("=== Regreso al menu principal ===\n");
					break;
				default:
					printf("Solo se aceptan opciones de 1 a 4\n");
					break;
			}
		}
	} while (option != 4);
	return state;
}


/**
 * \brief Set the criteria to Sort list of Employee
 * \param pEmployeeA
 * \param pEmployeeB
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int employee_compare(void* pEmployeeA, void* pEmployeeB)
{
	int state = 0;

	if (((Employee*)pEmployeeA)->id > ((Employee*)pEmployeeB)->id)
	{
		state = 1;
	}
	if (((Employee*)pEmployeeA)->id < ((Employee*)pEmployeeB)->id)
	{
		state = -1;
	}

	return state;
}

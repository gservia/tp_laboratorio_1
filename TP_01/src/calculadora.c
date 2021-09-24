/*
 * calculadora.c
 * Author: Gabriel Servia
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"


/**
 * \brief Menu de la calculadora
 * \param numUno Trae el 1er operando del main al menu
 * \param numDos Trae el 2do operando del main al menu
 * \return Retorna la opcion elegida por el usuario como un char
 */
char calculadora_menu(float numUno, float numDos)
{
	char opcion;

	printf("\n=========== MENU ===========\n1. Ingresar 1er operando %.2f\n2. Ingresar 2do operando %.2f\n", numUno, numDos);
	printf("3. Calcular todas las operaciones\n a. Suma %.2f + %.2f | b. Resta %.2f - %.2f | c. Division %.2f / %.2f | d. Multiplicacion  %.2f * %.2f | e. Factoriales %.2f! y %.2f!\n", numUno, numDos, numUno, numDos, numUno, numDos, numUno, numDos, numUno, numDos);
	printf("4. Informar resultados\n");
	printf("5. Salir del programa\n");

	utn_getChar(&opcion, 49, 53, 0, "\nSeleccione una opcion: ", "Solo se aceptan opciones del 1 al 5.");

	return opcion;
}


/**
 * \brief Realiza la suma de 2 numeros
 * \param numUno Primer operando
 * \param numDos Segundo operando
 * \return Retorna el resultado de la suma
 */
float calculadora_suma(float numUno, float numDos)
{
	float resultado;
	resultado = numUno + numDos;
	return resultado;
}

/**
 * \brief Realiza la resta de 2 numeros
 * \param numUno Primer operando
 * \param numDos Segundo operando
 * \return Retorna el resultado de la resta
 */
float calculadora_resta(float numUno, float numDos)
{
	float resultado;
	resultado = numUno - numDos;
	return resultado;
}

/**
 * \brief Realiza la multiplicacion de 2 numeros
 * \param numUno Primer operando
 * \param numDos Segundo operando
 * \return Retorna el resultado de la multiplicacion
 */
float calculadora_multiplicacion(float numUno, float numDos)
{
	float resultado;
	resultado = numUno * numDos;
	return resultado;
}

/**
 * \brief Realiza la division de 2 numeros si el segundo operando es distinto de cero
 * \param pResultado Puntero al espacio de memoria del numero float donde se asignara el resultado de la funcion
 * \param numUno Primer operando
 * \param numDos Segundo operando
 * \return Retorna el resultado de la division
 */
int calculadora_division(float* pResultado, float numUno, float numDos)
{
	int estado = -1; // No se puede dividir por cero
	float buffer;

	if (numDos != 0)
	{
		estado = 0; // Se logra la division
		buffer = numUno / numDos;
		*pResultado = buffer;
	}
	return estado;
}


/**
 * \brief Convierte el numero float ingresado en entero y realiza el factorial
 * \param pResultado Puntero al espacio de memoria del numero entero donde se asignara el resultado de la funcion
 * \param numero Numero a factorizar
 * \return Retorna el resultado del factorial
 */
int calculadora_factorial(int* pResultado, float numero)
{
	int estado = -1; // Solo se aceptan numeros enteros positivos
	int numeroEntero;
	int factorial;
	int i;

	numeroEntero = (int) numero; //
	factorial = 1;

	if(numero == 0.00)
	{
		estado = 0; // Se realiza el factorial de cero
		*pResultado = 1;
	}
	else
	{
		if (!(numero - numeroEntero))
		{
			if (numeroEntero > 0)
			{
				estado = 0; // Se realiza el factorial de enteros positivos
				for (i = 1; i <= numeroEntero; i++)
				{
					factorial = factorial * i;
				}
				*pResultado = factorial;
			}
		}
	}
	return estado;
}


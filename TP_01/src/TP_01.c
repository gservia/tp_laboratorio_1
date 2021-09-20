/*
 ============================================================================
 Name        : TP_01.c
 Author      : Gabriel Servia
 University  : UTN FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#include "calculadora.h"

#define REINTENTOS 0
#define NUMERO_MIN -32768
#define NUMERO_MAX 32767

int main(void) {

	setbuf(stdout, NULL);

	float numeroUno;
	float numeroDos;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	int estadoDivision;
	int estadoFactorial;
	int factorialUno;
	int factorialDos;

	puts("===== CALCULADORA =====");

	menuCalculadora();

	utn_getFloat(&numeroUno, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el primer numero: ", "Error de ingreso");

	printf("%.2f\n", numeroUno);

	utn_getFloat(&numeroDos, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el segundo numero: ", "Error de ingreso");

	printf("%.2f\n", numeroDos);


	suma = calculadora_suma(numeroUno, numeroDos);
	printf("SUMA: %.2f\n", suma);

	resta = calculadora_resta(numeroUno, numeroDos);
	printf("RESTA: %.2f\n", resta);

	multiplicacion = calculadora_multiplicacion(numeroUno, numeroDos);
	printf("MULTIPLICACION: %.2f\n", multiplicacion);

	estadoDivision = calculadora_division(&division, numeroUno, numeroDos);
	if (estadoDivision == 0)
	{
		printf("DIVISION: %.2f\n", division);
	}
	else
	{
		printf("No se puede dividir por cero\n");
	}

	estadoFactorial = calculadora_factorial(&factorialUno, numeroUno);
	if (estadoFactorial == 0)
	{
		printf("FACTORIAL 1er NUMERO: %d\n", factorialUno);
	}
	else
	{
		printf("Operando 1: Solo se puede realizar el factorial de numeros enteros positivos\n");
	}

	estadoFactorial = calculadora_factorial(&factorialDos, numeroDos);
	if (estadoFactorial == 0)
	{
		printf("FACTORIAL 2do NUMERO: %d\n", factorialDos);
	}
	else
	{
		printf("Operando 2: Solo se puede realizar el factorial de numeros enteros positivos\n");
	}

	return EXIT_SUCCESS;
}


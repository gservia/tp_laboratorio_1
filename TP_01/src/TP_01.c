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
	char opcionElegida;
	float numeroUno, numeroDos;
	int flagContinuar, flagInputNumUno, flagInputNumDos, flagInputs;
	float suma, resta, multiplicacion, division;
	int estadoDivision, estadoFactorialUno, estadoFactorialDos;
	int factorialUno, factorialDos;

	numeroUno = 0;
	numeroDos = 0;
	flagContinuar = 0;
	flagInputNumUno = -1;
	flagInputNumDos = -1;
	flagInputs = -1;

	puts("===== CALCULADORA =====");
	while (flagContinuar == 0)
	{
		opcionElegida = menuCalculadora(numeroUno, numeroDos);
		switch (opcionElegida)
		{
			case '1':
				flagInputNumUno = utn_getFloat(&numeroUno, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el primer numero: ", "Error de ingreso");
				break;
			case '2':
				flagInputNumDos = utn_getFloat(&numeroDos, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el segundo numero: ", "Error de ingreso");
				break;
			case '3':
				if (flagInputNumUno == 0 && flagInputNumDos == 0) // Verifica que el usuario haya ingresado ambos operandos
				{
					flagInputs = 0;
					suma = calculadora_suma(numeroUno, numeroDos);
					resta = calculadora_resta(numeroUno, numeroDos);
					estadoDivision = calculadora_division(&division, numeroUno, numeroDos);
					multiplicacion = calculadora_multiplicacion(numeroUno, numeroDos);
					estadoFactorialUno = calculadora_factorial(&factorialUno, numeroUno);
					estadoFactorialDos = calculadora_factorial(&factorialDos, numeroDos);
					puts("=== CALCULOS EJECUTADOS ===");
					break;
				}
				printf("\nSE NECESITAN LOS 2 OPERANDOS PARA EJECUTAR LA OPCION 3\n");
				break;
			case '4':
				if (flagInputs == 0)
				{
					puts("====== RESULTADOS ======");
					printf("El resultado de %.2f + %.2f es: %.2f\n", numeroUno, numeroDos, suma);
					printf("El resultado de %.2f - %.2f es: %.2f\n", numeroUno, numeroDos, resta);
					if (estadoDivision == 0) // Validacion de division por cero
					{
						printf("El resultado de %.2f / %.2f es: %.2f\n", numeroUno, numeroDos, division);
					}
					else
					{
						printf("No es posible dividir por cero\n");
					}
					printf("El resultado de %.2f * %.2f es: %.2f\n", numeroUno, numeroDos, multiplicacion);
					if (estadoFactorialUno == 0) // Validacion de 1er factorial de enteros positivos
					{
						printf("El factorial de %.2f es: %d\n", numeroUno, factorialUno);
					}
					else
					{
						printf("%.2f: Solo se puede realizar el factorial de cero y numeros enteros positivos\n", numeroUno);
					}
					if (estadoFactorialDos == 0) // Validacion de 2do factorial de enteros positivos
					{
						printf("El factorial de %.2f es: %d\n", numeroDos, factorialDos);
					}
					else
					{
						printf("%.2f: Solo se puede realizar el factorial de cero y numeros enteros positivos\n", numeroDos);
					}
					flagInputs = 1; // Modifica el estado para que siempre se tenga que Calcular(Op. 3) para poder Informar (Op. 4)
					break;
				}
				printf("\nNECESITA EJECUTAR LA OPCION 3 PARA TENER RESULTADOS\n");
				break;
			case '5':
				flagContinuar = -1;
				printf("\n=== Programa finalizado ===");
				break;
		}
	}
	return EXIT_SUCCESS;
}

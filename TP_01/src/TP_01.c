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
	int flagContinuar;
	float suma, resta, multiplicacion, division;
	int estadoDivision;
	int estadoFactorialUno, estadoFactorialDos;
	int factorialUno, factorialDos;

	printf("===== CALCULADORA =====");
	flagContinuar = 0;
	//opcionElegida = 0;

	while (flagContinuar == 0)
	{

		/*
		 *  HACER MENU SEPARADO DE LA FUNCION
		 *  Y OTRA FUNCION QUE SOLO PIDA "Seleccione una opcion" para evitar repeticion
		 *
		 *  Validar que hayan ingresado ambas variables para avanzar a opcion 3. Y validar opcion 3 para 4
		 */
		opcionElegida = menuCalculadora();

		switch (opcionElegida)
		{
			case '1':
				utn_getFloat(&numeroUno, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el primer numero: ", "Error de ingreso");
				break;
			case '2':
				utn_getFloat(&numeroDos, NUMERO_MIN, NUMERO_MAX, REINTENTOS, "Ingrese el segundo numero: ", "Error de ingreso");
				break;
			case '3':
				suma = calculadora_suma(numeroUno, numeroDos);
				resta = calculadora_resta(numeroUno, numeroDos);
				estadoDivision = calculadora_division(&division, numeroUno, numeroDos);
				multiplicacion = calculadora_multiplicacion(numeroUno, numeroDos);
				estadoFactorialUno = calculadora_factorial(&factorialUno, numeroUno);
				estadoFactorialDos = calculadora_factorial(&factorialDos, numeroDos);
				break;
			case '4':
				printf("El resultado de %.2f+%.2f es: %.2f\n", numeroUno, numeroDos, suma);
				printf("El resultado de %.2f-%.2f es: %.2f\n", numeroUno, numeroDos, resta);
				if (estadoDivision == 0)
				{
					printf("El resultado de %.2f/%.2f es: %.2f\n", numeroUno, numeroDos, division);
				}
				else
				{
					printf("No es posible dividir por cero\n");
				}
				printf("El resultado de %.2f*%.2f es: %.2f\n", numeroUno, numeroDos, multiplicacion);
				if (estadoFactorialUno == 0)
				{
					printf("El factorial de %.2f es: %d\n", numeroUno, factorialUno);
				}
				else
				{
					printf("%.2f: Solo se puede realizar el factorial de numeros enteros positivos\n", numeroUno);
				}
				if (estadoFactorialDos == 0)
				{
					printf("El factorial de %.2f es: %d\n", numeroDos, factorialDos);
				}
				else
				{
					printf("%.2f: Solo se puede realizar el factorial de numeros enteros positivos\n", numeroDos);
				}
				break;
			case '5':
				flagContinuar = -1;
				printf("\n=== Programa finalizado ===");
				break;
		}
	}
	return EXIT_SUCCESS;
}

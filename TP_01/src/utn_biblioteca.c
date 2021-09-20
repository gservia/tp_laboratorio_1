/*
 * utn_biblioteca.c
 * Author: Gabriel Servia
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un numero float al usuario. Lo verifica y devuelve el resultado y estado
 * \param pResultado Puntero al espacio de memoria del numero float donde se asignara el resultado de la funcion
 * \param min Numero minimo que se acepta en la funcion
 * \param max Numero Maximo que se acepta en la funcion
 * \param reintentos Cantidad de reintentos que se la da al usuario para ingresar el numero float
 * \param variableTexto Mensaje que se imprime en pantalla al usuario para solicitar el numero float
 * \param textoError Mensaje de error que se imprime en pantalla si el usuario ingresa un numero incorrecto o fuera de rango
 * \return Retora 0 si el numero ingresado es correcto. Si hubo un error retorna -1, o -2 imprimiendo el mensaje de textoError
 */
int utn_getFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	int retorno = -1;
	float buffer;
	int i;
	int salidaScanf;

	if (pResultado != NULL && min <= max && reintentos >= 0 && variableTexto != NULL && textoError != NULL)
	{
		for (i = 0; i <= reintentos; i++)
		{
			printf("%s", variableTexto);
			salidaScanf = scanf("%f", &buffer);

			if (salidaScanf > 0 && buffer >= min && buffer <= max)
			{
				retorno = 0; // OK
				*pResultado = buffer;
				break;
			}
			else
			{
				retorno = -2;
				printf("%s\n", textoError);
			}
		}
	}
	return retorno;
}


/**
 * \brief Solicita un numero entero al usuario. Lo verifica y devuelve el resultado y estado
 * \param pResultado Puntero al espacio de memoria del numero entero donde se asignara el resultado de la funcion
 * \param min Numero minimo que se acepta en la funcion
 * \param max Numero Maximo que se acepta en la funcion
 * \param reintentos Cantidad de reintentos que se la da al usuario para ingresar el numero entero
 * \param variableTexto Mensaje que se imprime en pantalla al usuario para solicitar el numero entero
 * \param textoError Mensaje de error que se imprime en pantalla si el usuario ingresa un numero incorrecto o fuera de rango
 * \return Retora 0 si el numero ingresado es correcto. Si hubo un error retorna -1, o -2 imprimiendo el mensaje de textoError
 */
int utn_getInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int retorno = -1;
	int buffer;
	int i;
	int salidaScanf;

	if (pResultado != NULL && min <= max && reintentos >= 0 && variableTexto != NULL && textoError != NULL)
	{
		for (i = 0; i <= reintentos; i++)
		{
			printf("%s", variableTexto);
			salidaScanf = scanf("%d", &buffer);

			if (salidaScanf > 0 && buffer >= min && buffer <= max)
			{
				retorno = 0; // OK
				*pResultado = buffer;
				break;
			}
			else
			{
				retorno = -2;
				printf("%s\n", textoError);
			}
		}
	}
	return retorno;
}


/**
 * \brief Solicita un caracter al usuario. Lo verifica y devuelve el resultado y estado
 * \param pResultado Puntero al espacio de memoria del caracter donde se asignara el resultado de la funcion
 * \param min Numero minimo que se acepta en la funcion
 * \param max Numero Maximo que se acepta en la funcion
 * \param reintentos Cantidad de reintentos que se la da al usuario para ingresar el caracter
 * \param variableTexto Mensaje que se imprime en pantalla al usuario para solicitar el caracter
 * \param textoError Mensaje de error que se imprime en pantalla si el usuario ingresa un caracter incorrecto o fuera de rango
 * \return Retora 0 si el caracter ingresado es correcto. Si hubo un error retorna -1, o -2 imprimiendo el mensaje de textoError
 */
int utn_getChar(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int retorno = -1;
	char buffer;
	int i;
	int salidaScanf;

	if (pResultado != NULL && min <= max && reintentos >= 0 && variableTexto != NULL && textoError != NULL)
	{
		for (i = 0; i <= reintentos; i++)
		{
			printf("%s", variableTexto);
			fflush(stdin);
			salidaScanf = scanf("%c", &buffer);

			if (salidaScanf > 0 && buffer >= min && buffer <= max)
			{
				retorno = 0; // OK
				*pResultado = buffer;
				break;
			}
			else
			{
				retorno = -2;
				printf("%s\n", textoError);
			}
		}
	}
	return retorno;
}


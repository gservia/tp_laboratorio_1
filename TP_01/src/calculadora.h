/*
 * calculadora.h
 * Author: Gabriel Servia
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

char menuCalculadora();
float calculadora_suma(float numUno, float numDos);
float calculadora_resta(float numUno, float numDos);
float calculadora_multiplicacion(float numUno, float numDos);
int calculadora_division(float* pResultado, float numUno, float numDos);
int calculadora_factorial(int* pResultado, float numero);


#endif /* CALCULADORA_H_ */

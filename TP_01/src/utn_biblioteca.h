/*
 * utn_biblioteca.h
 * Author: Gabriel Servia
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

int utn_getFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int utn_getInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_getChar(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);

#endif /* UTN_BIBLIOTECA_H_ */

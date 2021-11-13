/*
 ============================================================================
 Project     : TP_03
 Author      : Gabriel Servia
 Division    : 1° H
 University  : UTN FRA
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option;
    int flagLoadFile;


    LinkedList* listaEmpleados = ll_newLinkedList();

    option = 0;
    flagLoadFile = -1;

    do {
    	option = menu();
    	switch (option)
        {
            case 1:
                // "data.csv" | "archivo.txt"
            	if (controller_loadFromText("data.csv", listaEmpleados) == 0)
            	{
            		printf("\n=== Carga de archivo satisfatoria (modo texto) ===\n");
            		flagLoadFile = 0;
            	}
            	else
            	{
            		printf("\n=== Error al cargar (modo texto) ===\n");
            	}
                break;

            case 2:
                // Cargar los datos de los empleados desde el archivo data.csv (modo binario).
            	if (controller_loadFromBinary("data.txt", listaEmpleados) == 0)
            	{
            		printf("\n=== Carga de archivo satisfatoria (modo binario) ===\n");
            		flagLoadFile = 0;
            	}
            	else
            	{
            		printf("\n=== Error al cargar (modo binario) ===\n");
            	}
                break;

            case 3:
            	if (flagLoadFile == 0)
            	{
                	if (controller_addEmployee(listaEmpleados) == 0)
                	{
                		printf("\n=== Alta de empleado satisfatoria ===\n");
                	}
                	else
                	{
                		printf("\n=== Error al dar de alta ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado datos en sistema. Seleccione la opcion 1 primero. ===\n");
            	}
                break;

            case 4:
            	if (flagLoadFile == 0)
            	{
                	if (controller_editEmployee(listaEmpleados) == 0)
                	{
                		printf("\n=== Modificacion de empleado satisfatoria ===\n");
                	}
                	else
                	{
                		printf("\n=== Error al modificar empleado ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado datos en sistema. Seleccione la opcion 1 primero. ===\n");
            	}
                break;

            case 5:
            	if (flagLoadFile == 0)
            	{
                	if (controller_removeEmployee(listaEmpleados) == 0)
                	{
                		printf("\n=== Baja de empleado satisfatoria ===\n");
                	}
                	else
                	{
                		printf("\n=== Error al dar de baja al empleado ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado datos en sistema. Seleccione la opcion 1 primero. ===\n");
            	}
                break;

            case 6:
            	if (controller_ListEmployee(listaEmpleados) == 0)
            	{
            		printf("\n=== Listado de empleados satisfactorio ===\n");
            	}
            	else
            	{
            		printf("\n=== Algo salio mal. No es posible listar los empleados ===\n");
            	}
                break;

            case 7:
            	if (flagLoadFile == 0)
            	{
                	if (controller_sortEmployee(listaEmpleados) == 0)
                	{
                		printf("\n=== Ordenamiento de lista satisfatorio ===\n");
                	}
                	else
                	{
                		printf("\n=== Error al ordenar lista ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado datos en sistema. Seleccione la opcion 1 primero. ===\n");
            	}
                break;

            case 8:
            	if (controller_saveAsText("dataGenerated.csv", listaEmpleados) == 0)
            	{
            		printf("\n=== Archivo guardado con exito (modo texto) ===\n");
            	}
            	else
            	{
            		printf("\n=== Error al guardar (modo texto) ===\n");
            	}
                break;

            case 9:
                // Guardar los datos de los empleados en el archivo data.csv (modo binario).
                break;

            case 10:
            	// Finaliza el programa
            	break;

            default:
            	printf("Elija opcion de 1 a 10\n");
            	break;
        }
    }while (option != 10);

    puts("\n=== PROGRAMA FINALIZADO ===");
    return 0;
}

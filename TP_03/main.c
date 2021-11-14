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
#include "utn.h"
#include "input_validation.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option;
    int flagLoadFileTxt;
    int flagLoadFileBin;
    int flagLoadOne;
    int flagSavedFileTxt;
    int flagSavedFileBin;
    int flagExit;

    LinkedList* listaEmpleados = ll_newLinkedList();

    option = 0;
    flagLoadFileTxt = -1;
    flagLoadFileBin = -1;
    flagLoadOne = -1;
    flagSavedFileTxt = -1;
    flagSavedFileBin = -1;
    flagExit = -1;

    do {
    	option = menu();
    	switch (option)
        {
            case 1:
            	if (flagLoadFileBin != 0)
            	{
                	if (controller_loadFromText("data.csv", listaEmpleados) == 0)
                	{
                		printf("\n=== Carga de archivo satisfatoria (modo texto) ===\n");
                		flagLoadFileTxt = 0;
                	}
                	else
                	{
                		printf("\n=== Error al cargar (modo texto) ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== Los datos ya fueron cargados por modo binario ===\n");
            	}

                break;

            case 2:
            	if (flagLoadFileTxt != 0)
            	{
                	if (controller_loadFromBinary("data.bin", listaEmpleados) == 0)
                	{
                		printf("\n=== Carga de archivo satisfatoria (modo binario) ===\n");
                		flagLoadFileBin = 0;
                	}
                	else
                	{
                		printf("\n=== Error al cargar (modo binario) ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== Los datos ya fueron cargados por modo texto ===\n");
            	}
                break;

            case 3:
            	if (controller_addEmployee(listaEmpleados) == 0)
                {
                	printf("\n=== Alta de empleado satisfatoria ===\n");
                	flagLoadOne = 0;
                }
                else
                {
                	printf("\n=== Error al dar de alta ===\n");
                }
                break;

            case 4:
            	if (flagLoadFileTxt == 0 || flagLoadOne == 0 || flagLoadFileBin == 0)
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
            		printf("\n=== No se han cargado datos en sistema ===\n");
            	}
                break;

            case 5:
            	if (flagLoadFileTxt == 0 || flagLoadOne == 0 || flagLoadFileBin == 0)
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
            		printf("\n=== No se han cargado datos en sistema ===\n");
            	}
                break;

            case 6:
            	if (flagLoadFileTxt == 0 || flagLoadOne == 0 || flagLoadFileBin == 0)
            	{
                	if (controller_ListEmployee(listaEmpleados) == 0)
                	{
                		printf("\n=== Listado de empleados satisfactorio ===\n");
                	}
                	else
                	{
                		printf("\n=== Algo salio mal. No es posible listar los empleados ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado datos en sistema ===\n");
            	}
                break;

            case 7:
            	if (flagLoadFileTxt == 0 || flagLoadOne == 0 || flagLoadFileBin == 0)
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
            		printf("\n=== No se han cargado datos en sistema ===\n");
            	}
                break;

            case 8:
            	if (flagLoadFileBin == 0 || flagLoadFileTxt == 0)
            	{
                	if (controller_saveAsText("data.csv", listaEmpleados) == 0)
                	{
                		printf("\n=== Archivo guardado con exito (modo texto) ===\n");
                		flagSavedFileTxt = 0;
                	}
                	else
                	{
                		printf("\n=== Error al guardar (modo texto) ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado el archivo en sistema ===\n");
            	}
                break;

            case 9:
            	if (flagLoadFileBin == 0 || flagLoadFileTxt == 0)
            	{
                	if (controller_saveAsBinary("data.bin", listaEmpleados) == 0)
                	{
                		printf("\n=== Archivo guardado con exito (modo binario) ===\n");
                		flagSavedFileBin = 0;
                	}
                	else
                	{
                		printf("\n=== Error al guardar (modo binario) ===\n");
                	}
            	}
            	else
            	{
            		printf("\n=== No se han cargado el archivo en sistema ===\n");
            	}
                break;

            case 10:
            	if (flagSavedFileTxt == 0 && flagSavedFileBin == 0)
            	{
            		printf("\nSaliendo...\n");
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	else
            	{
            		printf("\nNo has guardado o solo guardaste la informacion en un modo (texto/binario) ¿Estas seguro que deseas salir sin guardar los cambios?\n 1. Si\n 2. No\n");
            		if (utn_getInt(&flagExit, "Ingrese una opcion: ", "Error: comando no valido\n", 1, 2, 0) == 0)
            		{
            			switch (flagExit)
            			{
            				case 1:
            					printf("\nSaliendo...\n");
            					ll_deleteLinkedList(listaEmpleados);
            					break;
            				case 2:
            					printf("=== Regreso al menu principal ===\n");
            					option = 0;
            					break;
            			}
            		}
            	}
            	break;

            default:
            	printf("\n== Elija una opcion de 1 a 10 ==\n");
            	break;
        }
    }while (option != 10);

    puts("\n=== PROGRAMA FINALIZADO ===\n");
    return 0;
}

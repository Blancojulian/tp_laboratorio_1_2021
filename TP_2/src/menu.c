/*
 * menu.c
 *
 *
 * Author: Blanco Julian Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validaciones.h"
#include "arrayEmployees.h"




void showMenu(int* pOptionMenu, int* pOptionReport, int* pOptionModify, Employee* list, int len)
{
	int optionMenu;
	int optionReport;
	int optionModify;



	if(pOptionMenu != NULL && pOptionModify != NULL && pOptionReport != NULL && list != NULL && len > 0)
	{
		if(utn_getNumberInt(&optionMenu, "Menu de opciones:\n\n1- Alta de empleado.\n2- Modificar empleado.\n3- Baja de empleado.\n4- Informar:\n-. Lista empleados.\n-. Promedio y total de los salarios, y cuantos empleados superan el salario promedio.\n5- Salir.\n\nIngrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_MENU, 2) == 0)
		{
			system("CLS");
			if(optionMenu != 1 && searchOccupiedPlaceEmployee(list, len) != 0)
			{
				printf("Tiene que cargar un empleado para usar estas funciones.\n\n");
				*pOptionMenu = 0;
			}
			else
			{

				*pOptionMenu = optionMenu;
				switch (optionMenu)
				{
					case 2:
						if(utn_getNumberInt(&optionModify, "1- Cambiar nombre.\n2- Cambiar apellido.\n3- Cambiar salario.\n4- Cambiar sector.\n\nIngrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_MODIFY, 2) == 0)
						{
							*pOptionModify = optionModify;
						}
						break;
					case 4:
						if(utn_getNumberInt(&optionReport, "Menu de informe:\n\n1. Listado de empleados.\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\nIngrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_REPORT, 2) == 0)
						{
							*pOptionReport = optionReport;
						}
						break;
				}
			}
		}
	}
}

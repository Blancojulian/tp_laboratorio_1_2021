/*
 * arrayEmployees.c
 *
 *
 * Author: Blanco Julian Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"

static int generateNewId(void);



int requestDataEmployee(Employee* auxEmployee)
{
	int retorno = -1;
	Employee auxiliarEmpleado;

	if(auxEmployee != NULL)
	{
		if( utn_getString(auxiliarEmpleado.name, "Ingrese el nombre del empleado: ", "Error, nombre invalido.\n", 2, LONG_NAME - 1) == 0 &&
			utn_getString(auxiliarEmpleado.lastName, "Ingrese el apellido del empleado: ", "Error, apellido invalido.\n", 2, LONG_LASTNAME- 1) == 0 &&
			utn_getSalary(&auxiliarEmpleado.salary, "Ingrese el salario del empleado: ", "Error, salario invalido.\n", 1, FLT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxiliarEmpleado.sector, "Ingrese el sector del empleado (1 - 7): ", "Error, sector invalido.\n", 1, SECTOR_MAX, 2) == 0)
		{
			*auxEmployee = auxiliarEmpleado;
			retorno = 0;
		}
		else
		{
			printf("Error al ingresar los datos.");
		}
	}
	return retorno;
}




int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0){
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}



int addEmployees(Employee* list, int len, char* name, char* lastName, float salary, int sector)
{
	int retorno = -1;
	int index;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{
		if(searchFreePlaceEmployee(list, len, &index) == 0 && index < len)
		{
			list[index].isEmpty = 0;
			list[index].id = generateNewId();
			strncpy(list[index].name, name, LONG_NAME);
			strncpy(list[index].lastName, lastName, LONG_LASTNAME);
			list[index].salary = salary;
			list[index].sector = sector;
			retorno = 0;
		}
		else
		{
			printf("No hay espacios libres para dar de alta.");
		}
	}
	return retorno;
}



int findEmployeeById(Employee* list, int len, int id, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0 && pIndex != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



int modifyEmployee(Employee* list, int len, Employee aux, int index, int field)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && list[index].isEmpty == 0)
	{
		if( (field == 1 && utn_getString(aux.name, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0) ||
			(field == 2 && utn_getString(aux.lastName, "Ingrese el apellido del empleado: ", "Apellido invalido.\n", 2, LONG_LASTNAME- 1) == 0) ||
			(field == 3 && utn_getSalary(&aux.salary, "Ingrese el salario del empleado: ", "Salario invalido.\n", 1, FLT_MAX, 2) == 0) ||
			(field == 4 && utn_getNumberInt(&aux.sector, "Ingrese el sector del empleado (1 - 7): ", "Sector invalido.\n", 1, SECTOR_MAX, 2) == 0))
		{
			aux.id = list[index].id;
			aux.isEmpty = 0;
			list[index] = aux;
			retorno = 0;
		}
	}
	return retorno;
}




int removeEmployee(Employee* list, int len, int index)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && index < len && list[index].isEmpty == 0)
	{
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}




int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0){

		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf( "Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d.\n"
						,list[i].id , list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}





int searchFreePlaceEmployee(Employee* list, int len, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex!= NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}





int searchOccupiedPlaceEmployee(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}




int sortEmployeesByLastNameSector(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	Employee aux;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < (len - 1); i++)
			{
				if(	(order == 1 &&
					((strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) > 0 ||
					(strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) == 0 &&
					list[i].sector > list[i+1].sector)))) ||
					(order == 0 &&
					((strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) < 0 ||
					(strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) == 0 &&
					list[i].sector < list[i+1].sector)))))

				{
					aux = list[i];
					list[i] = list[i+1];
					list[i+1] = aux;
					flagSwap = 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}




int AccumulateAverageSalary(Employee* list, int len, float* pAccumulator, float* pAverage)
{
	int retorno = -1;
	int i;
	float accumulator = 0;
	int counter = 0;

	if (list != NULL && len > 0 && pAccumulator != NULL && pAverage != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				accumulator += list[i].salary;
				*pAccumulator = accumulator;
				counter++;
				retorno = 0;
			}
		}
		*pAverage = accumulator / counter;
	}
	return retorno;
}





int calculateEmployeesOverAverageSalary(Employee* list, int len, int* pCounter, float average)
{
	int retorno = -1;
	int i;
	int counter = 0;

	if (list != NULL && len > 0 && pCounter != NULL && average > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > average)
			{
				counter++;
			}
		}
		*pCounter = counter;
		retorno = 0;
	}
	return retorno;
}




static int generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}

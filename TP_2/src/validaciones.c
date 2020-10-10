/*
 * validaciones.c
 *
 *
 * Author: Blanco Julian Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

static int myGets(char* cadena, int longitud);//getSalary y getInt
static int isNumberInt(char* cadena, int limite);//getInt
static int getInt(int *pResultado);//utn_getNumberInt
static int isSalary(char* cadena, int limite);//getSalary
static int getSalary(float *pResultado);//utn_getSalary
static int isString(char* cadena,int limite);//getString
static int getString(char* pResultado,int longitud);//utn_getString


static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[LEN_BUFFER_STRING];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}



static int getInt(int* pResultado)
{
	int retorno	= -1;
	char bufferString[LEN_BUFFER_STRING];

	if(pResultado != NULL)
	{
		if( myGets(bufferString, sizeof(bufferString)) == 0 &&
			isNumberInt(bufferString, LEN_BUFFER_STRING)  == 1)
		{
			retorno = 0;
			*pResultado = atoi(bufferString);
		}
	}
	return retorno;
}





static int isString(char* cadena,int limite)
{
	int respuesta = 1; // Todo bien.

	for (int i = 0; i <= limite && cadena[i] != '\0'; i++)
	{
		if(	(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
			(cadena[i] < 'a' || cadena[i] > 'z' ))
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}




static int isNumberInt(char* cadena, int limite)
{
	int respuesta = 1; // Todo bien.
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}
	for ( ; i <= limite && cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9' )
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}

static int getSalary(float* pResultado)
{
	int retorno	= -1;
	char bufferString[LEN_BUFFER_STRING];

	if(pResultado != NULL)
	{
		if( myGets(bufferString, sizeof(bufferString)) == 0 &&
			isSalary(bufferString, LEN_BUFFER_STRING)  == 1)
		{
			retorno = 0;
			*pResultado = atof(bufferString);
		}
	}
	return retorno;
}




static int getString(char* pResultado,int longitud)
{
	int retorno = -1;
	char bufferString[LEN_BUFFER_STRING];
	if(pResultado != NULL && longitud > 0)
	{
		fflush(stdin);
		if(	myGets(bufferString,sizeof(bufferString)) == 0 &&
			isString(bufferString,LEN_BUFFER_STRING) == 1)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
		}
	}
	return retorno;
}




static int isSalary(char* cadena, int limite)
{
	int respuesta = 1; // Todo bien.
	int i = 0;
	int contadorPuntos = 0;

	if(cadena[0] == '-' || cadena[0] == '+')
	{
		i = 1;
	}
	for ( ; i <= limite && cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9' )
		{
			if(cadena[i] == '.' && contadorPuntos == 0)
			{
				contadorPuntos++;
			}
			else
			{
			respuesta = 0;
			break;
			}
		}
	}
	return respuesta;
}





int utn_getNumberInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if( 	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(	getInt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}




int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int reintentos, int limite)
{
	int retorno = -1;
	char bufferString[LEN_BUFFER_STRING];

	if( 	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 1)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(	getString(bufferString, LEN_BUFFER_STRING) == 0 &&
				strnlen(bufferString, sizeof(bufferString)-1) <= limite)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}




int utn_getSalary(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if( 	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(	getSalary(&bufferFloat) == 0 &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

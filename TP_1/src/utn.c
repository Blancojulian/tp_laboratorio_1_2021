/*
 * utn.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Blanco Julián Agustín
 */


#include <stdio.h>
#include <stdlib.h>

/*
 * \ brief - Calcula el factorial de 1 numero enteros.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - float operadorA, Primer numero de la operación matemática.
 * \ param - float operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int factorial(float operador,float *resultadoFactorial)
{
	int retorno = -1;
    float factorial;
    float contador;
    contador=operador;
    factorial=operador;

    if(factorial==0)
    {
    	*resultadoFactorial=1;
    	retorno=0;
    }

    if(contador>1)
    {

    	while(contador>1)
    	{
    		contador=contador-1;
    		factorial=factorial*contador;

    	}
    	retorno=0;
    	*resultadoFactorial=factorial;
    }
    return retorno;

}

/*
 * \ brief - Realiza la suma entre 2 numeros.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - float operadorA, Primer numero de la operación matemática.
 * \ param - float operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int suma(float operadorA, float operadorB,float *pResultado)
{
	int retorno =-1;

	if(pResultado != NULL)
	{
		*pResultado=operadorA+operadorB;
		retorno=0;
	}

    return retorno;
}

/*
 * \ brief - Realiza la resta entre 2 numeros.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - float operadorA, Primer numero de la operación matemática.
 * \ param - float operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int resta(float operadorA, float operadorB,float *pResultado)
{
	int retorno =-1;

		if(pResultado != NULL)
		{
			*pResultado=operadorA-operadorB;
			retorno=0;
		}

	    return retorno;
}

/*
 * \ brief - Realiza la multiplicación entre 2 numeros.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - float operadorA, Primer numero de la operación matemática.
 * \ param - float operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int multiplicacion(float operadorA, float operadorB,float *pResultado)
{
	int retorno =-1;

		if(pResultado != NULL)
		{
			*pResultado=operadorA*operadorB;
			retorno=0;
		}

	    return retorno;
}

/*
 * \ brief - Realiza la división entre 2 numeros.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - float operadorA, Primer numero de la operación matemática.
 * \ param - float operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int division(float operadorA, float operadorB,float *pResultado)
{

	int retorno =-1;

		if(pResultado != NULL && operadorB!=0)
		{
			*pResultado=operadorA/operadorB;
			retorno=0;
		}

	    return retorno;

}

/*
 * \ brief - Solicita un entero al usuario, lo válida y devuelve el resultado.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	float bufferfloat;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%f" , &bufferfloat);
			if(resultadoScanf == 1 && bufferfloat >= minimo && bufferfloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferfloat;
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







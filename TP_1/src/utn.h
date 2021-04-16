/*
 * utn.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Blanco Julián Agustín
 */

#ifndef UTN_H_
#define UTN_H_



int suma(float operadorA, float operadorB,float *pResultado);

int resta(float operadorA, float operadorB,float *pResultado);

int division(float operadorA, float operadorB,float *pResultado);

int multiplicacion(float operadorA, float operadorB,float *pResultado);

int factorial(float operador,float *resultadoFactorial);

int getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo);



#endif /* UTN_H_ */

/*
 * operaciones.c
 *
 *  Created on: 20 sep. 2021
 *      Author: agust
 */
#include <stdio.h>
#include <stdlib.h>
/*
/////////////////////////////////////////////////////////////////////
brief: función que pide y valida a través de un bucle un número de tipo float
param: se pide el puntero donde se guardará el número
return: void
/////////////////////////////////////////////////////////////////////
*/
void getMyFloat(float* num)
{
	int status = 0;

	printf("Ingresa un número: \n");
	status = scanf("%f", num);

	while(status != 1)
	{
		printf("Error - Ingresa un número valido: \n");
		fflush(stdin);
		status = scanf("%f", num);
	}
}

/*
/////////////////////////////////////////////////////////////////////
brief: funcion encargada de sumar
param1: se pide el primer número (float)
param2: se pide el segundo número (float)
param3: se pide el puntero donde se almacenará el resultado
return: void
/////////////////////////////////////////////////////////////////////
*/
void sumaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno + numDos;
}

/*
/////////////////////////////////////////////////////////////////////
brief: funcion encargada de restar
param1: se pide el primer número (float)
param2: se pide el segundo número (float)
param3: se pide el puntero donde se almacenará el resultado
return: void
/////////////////////////////////////////////////////////////////////
*/
void restaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno - numDos;
}

/*
/////////////////////////////////////////////////////////////////////
brief: funcion encargada de dividir
param1: se pide el primer número (float)
param2: se pide el segundo número (float)
param3: se pide el puntero donde se almacenará el resultado
return: int que refiere al estado
/////////////////////////////////////////////////////////////////////
*/
int divideOperacion(float numUno, float numDos, float* resultado)
{
	int status = -1; // Por defecto en ERROR

	if(numDos != 0)
	{
		*resultado = numUno / numDos;
		status = 0; // OK
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: funcion encargada de multiplicar
param1: se pide el primer número (float)
param2: se pide el segundo número (float)
param3: se pide el puntero donde se almacenará el resultado
return: void
/////////////////////////////////////////////////////////////////////
*/
void multiplicaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno * numDos;
}

/*
/////////////////////////////////////////////////////////////////////
brief: funcion encargada de realizar factorial
param1: se pide el número a factorear(int)
param2: se pide el puntero donde se almacenará el resultado
return: int que refiere al estado
/////////////////////////////////////////////////////////////////////
*/
int factorialOperacion(int num, float* resultado)
{
	int factorial = 1;
		int i;
		int status = -1; // Por defecto en ERROR
		if(num > 0)
		{
			for(i = num; i > 1; i--)
			{
				factorial = factorial * i;
			}

			*resultado = factorial;
			status = 0; // OK
		}else
		{
			if(num == 0)
			{
				*resultado = 1;
				status = 0; // OK
			}
		}

	return status;
}

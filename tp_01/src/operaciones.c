/*
 * operaciones.c
 *
 *  Created on: 20 sep. 2021
 *      Author: agust
 */
#include <stdio.h>
#include <stdlib.h>

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

void sumaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno + numDos;
}

void restaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno - numDos;
}

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

void multiplicaOperacion(float numUno, float numDos, float* resultado)
{
	*resultado = numUno * numDos;
}

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

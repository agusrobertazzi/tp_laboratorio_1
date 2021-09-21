/*
 ============================================================================
 Name        : tp_01.c
 Author      : Agus Robertazzi - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion = 0;
	int subOpcion = -1;
	float numUno;
	float numDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDiv;
	float resultadoMultpl;
	float resultadoFactUno;
	float resultadoFactDos;
	int statusUno = -1;
	int statusDos = -1;
	int statusDivision = -1;
	int statusFactUno = -1;
	int statusFactDos = -1;
	int statusResultado = -1;

	do
	{

		puts("\nMenu: \n\t1. Ingresar número 1\n\t2. Ingresar número 2\n\t3. Realizar todas las operaciones\n\t4. Imprimir todas las operaciones\n\t5. Salir");
		scanf("%d", &opcion);

		switch(opcion)
		{
			// Ingresar número 1
			case 1:
				getMyFloat(&numUno);

				// Verifica sí falta numDos, sí falta... pregunta sí lo quiere ingresar
				if(statusDos == -1)
				{
					puts("¿Desea ingresar el número dos?\n1. Si\n2. No");
					scanf("%d", &subOpcion);
					while(subOpcion != 1 && subOpcion != 2)
					{
						puts("Error - ¿Desea ingresar el número dos?\n1. Si\n2. No");
						fflush(stdin);
						scanf("%d", &subOpcion);
					}

					if(subOpcion == 1)
					{
						getMyFloat(&numDos);
						statusDos = 0;
					}
				}

				// Verifica que salga bien
				statusResultado = -1;
				subOpcion = -1;
				statusUno = 0;
				break;

			// Ingresar número 2
			case 2:
				getMyFloat(&numDos);

				// Verifica sí falta numUno, sí falta... pregunta sí lo quiere ingresar
				if(statusUno == -1)
				{
					puts("¿Desea ingresar el número uno?\n1. Si\n2. No");
					scanf("%d", &subOpcion);
					while(subOpcion != 1 && subOpcion != 2)
					{
						puts("Error - ¿Desea ingresar el número dos?\n1. Si\n2. No");
						fflush(stdin);
						scanf("%d", &subOpcion);
					}

					if(subOpcion == 1)
					{
						getMyFloat(&numUno);
						statusUno = 0;
					}
				}

				// Verifica que salga bien
				statusResultado = -1;
				subOpcion = -1;
				statusDos = 0;
				break;

			// Realizar operaciones
			case 3:
				if(statusUno != -1 && statusDos != -1)
				{
					// Realiza OPS
					sumaOperacion(numUno, numDos, &resultadoSuma);
					restaOperacion(numUno, numDos, &resultadoResta);
					statusDivision = divideOperacion(numUno, numDos, &resultadoDiv);
					multiplicaOperacion(numUno, numDos, &resultadoMultpl);
					statusFactUno = factorialOperacion((int)numUno, &resultadoFactUno);
					statusFactDos = factorialOperacion((int)numDos, &resultadoFactDos);
					printf("\n¡Operaciones realizadas!\n");

					statusResultado = 0;
				}
				else
				{
					// Falta ingresar un número
					if(statusUno == -1 && statusDos == -1)
					{
						printf("\nOlvido ingresar los dos números\n");
					}
					else
					{
						if(statusUno == -1)
						{
							printf("\nOlvido ingresar el primer número\n");
						}
						else
						{
							printf("\nOlvido ingresar el segundo número\n");
						}
					}
				}

				break;

			// Cargar resultados
			case 4:
				if(statusResultado == 0)
				{
					// Imprime resultados
					printf("\n-------------------------------\n");

					printf("El resultado de %.2f + %.2f es: %.2f\n", numUno, numDos, resultadoSuma);

					printf("El resultado de %.2f - %.2f es: %.2f\n", numUno, numDos, resultadoResta);

					if(statusDivision == -1)
					{
						printf("MATH ERROR - No se puede dividir por 0\n");
					}
					else
					{
						printf("El resultado de %.2f / %.2f es: %.2f\n", numUno, numDos, resultadoDiv);
					}

					printf("El resultado de %.2f * %.2f es: %.2f\n", numUno, numDos, resultadoMultpl);

					if(statusFactUno == -1)
					{
						printf("Aún no habilitamos la opción de factorial negativo\n");
					}
					else
					{
						printf("El resultado de !%d es: %d\n", (int)numUno, (int)resultadoFactUno);
					}

					if(statusFactDos == -1)
					{
						printf("Aún no habilitamos la opción de factorial negativo\n");
					}
					else
					{
						printf("El resultado de !%d es: %d\n", (int)numDos, (int)resultadoFactDos);
					}

					printf("-------------------------------\n");
				}
				else
				{
					// ALGO PASÓ
					if(statusUno == -1 && statusDos == -1)
					{
						printf("\nOlvido ingresar los dos números\n");
					}
					else
					{
						if(statusUno == -1)
						{
							printf("\nOlvido ingresar el primer número\n");
						}
						else
						{
							if(statusDos == -1)
							{
								printf("\nOlvido ingresar el segundo número\n");
							}
							else
							{
								printf("\n¡No realizaste las operaciones!\n");
							}
						}
					}
			}

				break;

			// Salir y resetear estados
			case 5:
				statusUno = -1;
				statusDos = -1;
				statusDivision = -1;
				statusFactUno = -1;
				statusFactDos = -1;
				statusResultado = -1;
				printf("\nSaliendo...\n");
				break;
			default:
				printf("\nOpción incorrecta.. intente nuevamente\n");

		}

	}while(opcion != 5);


	return EXIT_SUCCESS;
}

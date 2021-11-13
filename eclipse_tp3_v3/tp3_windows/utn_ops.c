#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_ops.h"
#define TRUE 1
#define FALSE 0
#define BUFFER_LEN 1000


static int myGets(char* pIngreso, int len)
{
	int status= FALSE;
	int indexFinal;

	if(fgets(pIngreso,len,stdin) != NULL)
	{
		// Aca cambia el /n por /0
		indexFinal = strlen(pIngreso)-1;

		if(pIngreso[indexFinal] == '\n')
		{
			pIngreso[indexFinal] = '\0';
		}

		status = TRUE;
	}

	return status;
}

// VALIDACIONES

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero entero
param: se pide un tipo char para validar si es un numero entero
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarEntero(char* pIngreso)
{
	int status = TRUE;

	if(strlen(pIngreso) > 0)
	{
		for(int i = 0;i< strlen(pIngreso);i++)
		{
			if(isdigit(pIngreso[i]) == FALSE)
			{
				if(i == 0)
				{
					if(pIngreso[0] != '-')
					{
						status = FALSE;
						break;
					}
				}
				else
				{
					status = 0;
				}
			}
		}
	}
	else
	{
		status = FALSE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero flotante (Si es entero, no avisa)
param: se pide un tipo char para validar si es un numero flotante
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarFlotante(char* pIngreso)
{
	int sign = 0;
	int digits = 0;
	int status = TRUE;

	if(strlen(pIngreso) > 0)
	{
		for(int i = 0;i < strlen(pIngreso); i++)
		{
			if(pIngreso[i] == '.' || pIngreso[i] == ',')
			{
				sign++;
			}
			else
			{
				if(isdigit(pIngreso[i]) == 0)
				{
					if(i == 0)
					{
						if(pIngreso[0] != '-')
						{
							status = FALSE;
							break;
						}
					}
					else
					{
						status = FALSE;
						break;
					}
				}
			}
			if(isdigit(pIngreso[i]) == 1)
			{
				digits++;
			}
		}

		if(sign > 1 || digits == 0)
		{
			status = FALSE;
		}

	}
	else
	{
		status = FALSE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un char ingresado anteriormente para validar sí es un tipo caracter realmente
param: se pide un tipo char para validar si es un caracter
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCaracter(char ingreso)
{
	int status = TRUE;

	if(isalpha(ingreso) == FALSE)
	{
		status = FALSE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es alfabética
param: se pide un tipo char para validar si es un array de caracteres alfabéticos
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCadena(char ingreso[])
{
	int i= 0;
	int retorno;

	if(ingreso!=NULL&&strlen(ingreso)>0)
	{
		retorno= TRUE;

		while(ingreso[i]!='\0')
		{
			if((ingreso[i] >= 'A' && ingreso[i] <= 'z' ) || ingreso[i] == 32 || ingreso[i] == '.' || ingreso[i] == ',' || ingreso[i] == '-'|| ingreso[i] == '_')
			{
				if(ingreso[i] > 'Z' && ingreso[i] < 'a')
				{
					retorno = FALSE;
					break;
				}
				i++;

			}
			else
			{
				retorno= FALSE;
				break;
			}

		}
	}

	return retorno;
}

// INGRESOS SIN REINTENTOS

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un INT o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: int que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
int ingresoInt(char* message, char* errorText)
{
	char buffer[BUFFER_LEN];
	int status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		status = atoi(buffer);
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un FLOAT o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: float que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
float ingresoFloat(char* message, char* errorText)
{
	char buffer[BUFFER_LEN];
	float status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarFlotante(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		status = atof(buffer);
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide un char, se valida sí es un CHAR o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: char que refiere al caracter ingresado
/////////////////////////////////////////////////////////////////////
*/
char ingresoChar(char* message, char* errorText)
{
	char buffer;
	char status;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);
		buffer = getchar();

		while(validarCaracter(buffer) == FALSE)
		{
			printf("%s",errorText);
			fflush(stdin);
			buffer = getchar();
		}

		status = buffer;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos la cadena de texto, la longitud de la cadena ,una cadena de caracteres referente al mensaje y otra al mensaje de error
param: La función pide una cadena de texto, se valida sí es una cadena o no. En caso de que no, se vuelve a pedir y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCadena(char pIngreso[],int len, char* message, char* errorText)
{
	int status = TRUE;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);

		while(myGets(pIngreso, len) == FALSE)
		{
			printf("%s", errorText);
			fflush(stdin);
		}
	}

	return status;
}


// INGRESOS CON REINTENTOS

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el entero, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un entero, se valida sí es un entero o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntRetry(int* pIngreso, char* message, char* errorText, int retry)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE)
		{
			if(retry == 0)
			{
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
			retry--;

		}

		*pIngreso = atoi(buffer);
		status = TRUE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el float, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un flotante, se valida sí es un flotante o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatRetry(float* pIngreso, char* message, char* errorText, int retry)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarFlotante(buffer) == FALSE)
		{
			if(retry == 0)
			{
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
			retry--;
		}

		*pIngreso = atof(buffer);
		status = TRUE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos el char, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide un caracter, se valida sí es un char o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCharRetry(char* pIngreso, char* message, char* errorText,int retry)
{
	char buffer;
	char status = TRUE;

	if(message != NULL && errorText != NULL && retry > 0)
	{
		printf("%s",message);
		fflush(stdin);
		buffer = getchar();

		while(validarCaracter(buffer) == FALSE)
		{
			if(retry == 0)
			{
				printf("Se acabaron los intentos. Reinicie el programa");
				status = FALSE;
				break;
			}

			printf("%s",errorText);
			fflush(stdin);
			buffer = getchar();
			retry--;
		}

		*pIngreso = buffer;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un array donde ingresaremos una cadena de texto, el tamaño de la cadena, una cadena de caracteres referente al mensaje y otra al mensaje de error, un int de cantidad de intentos
param: La función pide una cadena de texto, se valida sí es una cadena o no. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoTextoRetry(char pIngreso[],int len, char* message, char* errorText, int retry)
{
	int status = TRUE;

	if(message != NULL && errorText != NULL)
	{
		printf("%s",message);
		fflush(stdin);

		while(myGets(pIngreso,len) == FALSE)
		{
			if(retry == 0)
			{
				status = FALSE;
				break;
			}

			printf("%s", errorText);
			fflush(stdin);
			retry--;
		}

	}

	return status;
}

// INGRESOS CON MIN Y MAX

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un entero, una cadena de caracteres referente al mensaje y otra al mensaje de error,minimo y maximo, un int de cantidad de intentos
param: La función pide un int, se valida sí es un entero o no y si esta dentro de los parametros min y max. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntMinMax(int* pIngreso, char* message, char* errorText, int min, int max)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && min < max)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);

		while(validarEntero(buffer) == FALSE || atoi(buffer) > max || atoi(buffer) < min)
		{
			printf("%s", errorText);
			fflush(stdin);
			gets(buffer);
		}

		*pIngreso = atoi(buffer);
		status = TRUE;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un flotante, una cadena de caracteres referente al mensaje y otra al mensaje de error,minimo y maximo, un int de cantidad de intentos
param: La función pide un int, se valida sí es un flotante o no y si esta dentro de los parametros min y max. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatMinMax(float* pIngreso, char* message, char* errorText, float min, float max)
{
	char buffer[BUFFER_LEN];
	int status = FALSE;

	if(pIngreso != NULL && message != NULL && errorText != NULL && min < max)
	{
		printf("%s",message);
		fflush(stdin);
		gets(buffer);
		while(validarFlotante(buffer) == FALSE || atof(buffer) > max || atof(buffer) < min)
		{
			printf("%s",errorText);
			fflush(stdin);
			gets(buffer);
		}

		*pIngreso = atof(buffer);
		status = TRUE;
	}

	return status;
}

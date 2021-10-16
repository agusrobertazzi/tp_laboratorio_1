/*
 * utn_ops.h
 *
 *  Created on: 12 oct. 2021
 *      Author: agust
 */

#ifndef UTN_OPS_H_
#define UTN_OPS_H_

// VALIDACIONES
int validarEntero(char *pIngreso);
int validarFlotante(char *pIngreso);
int validarCaracter(char ingreso);
int validarCadena(char *pIngreso);

// INGRESOS SIN REINTENTOS
int ingresoInt(char* message, char* errorText);
float ingresoFloat(char* message, char* errorText);
char ingresoChar(char* message, char* errorText);
int ingresoCadena(char pIngreso[],int len, char* message, char* errorText);

// INGRESOS CON REINTENTOS
int ingresoIntRetry(int* pIngreso, char* message, char* errorText, int retry);
int ingresoFloatRetry(float* pIngreso, char* message, char* errorText, int retry);
int ingresoCharRetry(char* pIngreso, char* message, char* errorText,int retry);
int ingresoTextoRetry(char pIngreso[],int len, char* message, char* errorText, int retry);

// INGRESOS CON MIN Y MAX
int ingresoIntMinMax(int* pIngreso, char* message, char* errorText, int min, int max);
int ingresoFloatMinMax(float* pIngreso, char* message, char* errorText, float min, float max);

#endif /* UTN_OPS_H_ */

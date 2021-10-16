/*
 * ArrayEmployees.h
 *
 *  Created on: 14 oct. 2021
 *      Author: agust
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"

#define TRUE 0
#define FALSE -1
#define EMPLOYEES 1000

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int orden);
int printEmployees(Employee* list, int len);
int promedioEmployees(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */

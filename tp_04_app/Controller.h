/*
 * Controller.h
 *
 *  Created on: 5 nov. 2021
 *      Author: agust
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "defines.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee); // Falta

int controller_getEmployeeId(LinkedList* pArrayListEmployee);
int controller_findEmployee(LinkedList* pArrayListEmployee, int id);
int controller_printEmployee(LinkedList* pArrayListEmployee, int id);

int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee); // Falta

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee); // Falta
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee); // Falta

#endif /* CONTROLLER_H_ */

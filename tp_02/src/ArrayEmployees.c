#include "ArrayEmployees.h"

/*
brief: Recorre el array y establece todas las posiciones como isEmpty == TRUE (Libre)
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
return: 0 TRUE || -1 FALSE
 */
int initEmployees(Employee* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0) // Valida que el array exista y no se encuentre vacio
	{
		status = TRUE; // Sali� bien

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE; // Establece cada "Empleado" como LIBRE
		}
	}

	return status;
}

/*
brief: Recibe los parametros y crea un nuevo Empleado
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
param: Int id || ID del usuario
param: Char name[] || Nombre del usuario
param: Char lastName[] || Apellido del usuario
param: Float salary || Salario del usuario
param: Int sector || Sector del usuario
return: 0 TRUE || -1 FALSE
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && salary >= 0 && sector > 0 && sector < 6) // Valida que el array exista Y no se encuentre vacio y que todos los datos sean llenados
	{
		for(i = 0; i < len; i++) // Recorre el array en busca de un espacio libre
		{
			if(list[i].isEmpty == TRUE) // Verifica s� el espacio se encuentra libre o no
			{
				list[i].isEmpty = FALSE;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				status = TRUE; // Sali� bien
				break; // Una vez creado, deja de buscar y corta el bucle
			}
		}
	}

	return status;
}


/*
brief: Recorre el array y busca la posici�n donde conincida el id a buscar con el id del usuario
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
param: Int id || ID del usuario a buscar
return: -1 FALSE || Posici�n del empleado dentro del array
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				status = i;
			}
		}
	}

	return status;
}


/*
brief: Recorre el array y busca la posici�n donde conincida el id a buscar con el id del usuario para modificarlo
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
param: Int id || ID del usuario a modicar
return: -1 FALSE || 0 TRUE
 */
int modifyEmployee(Employee* list, int len, int id)
{
	int status = FALSE;
	int option;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{

		idModify = findEmployeeById(list, len, id);

		puts("---------------------------------");
		puts("�Que deseas modificar?");
		puts("1. Nombre");
		puts("2. Apellido");
		puts("3. Salario");
		puts("4. Sector");
		puts("---------------------------------");
		ingresoIntMinMax(&option, "", "Error. Ingrese valor valido: ", 1, 4);

		if(idModify != FALSE)
		{
			switch(option)
			{
			case 1:
				ingresoCadena(list[idModify].name, 51, "Ingrese el nuevo nombre: ", "Error. Intente nuevamente: ");
				break;
			case 2:
				ingresoCadena(list[idModify].lastName, 51, "Ingrese el nuevo apellido: ", "Error. Intente nuevamente: ");
				break;
			case 3:
				list[idModify].salary = ingresoFloat("Ingrese el nuevo salario: ", "Error. Intente nuevamente: ");
				while(list[idModify].salary < 0)
				{
					list[idModify].salary = ingresoFloat("Salario no puede ser negativo. Ingrese nuevamente: ", "Error. Intente nuevamente: ");
				}
				break;
			case 4:
				ingresoIntMinMax(&list[idModify].sector, "Ingrese el nuevo sector del empleado (1 a 5): ", "Error. Ingrese un sector v�lido: ", 1, 5);
				break;
			}
			status = TRUE;
		}
	}

	return status;
}

/*
brief: Recorre el array y busca la posici�n donde conincida el id a buscar con el id del usuario para eliminarlo
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
param: Int id || ID del usuario a eliminar
return: -1 FALSE || 0 TRUE
 */
int removeEmployee(Employee* list, int len, int id)
{
	int status = FALSE;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{
		idModify = findEmployeeById(list, len, id);

		if(idModify != FALSE)
		{
			list[idModify].isEmpty = TRUE;
			status = TRUE;
		}
	}

	return status;
}

/*
brief: Recorre el array y lo ordena alfabeticamente
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
param: Int orden || Orden ascendente o descendente
return: -1 FALSE || 0 TRUE
 */
int sortEmployees(Employee* list, int len, int orden)
{
	int status = FALSE;
	int i;
	int j;
	Employee* listAux;

	printf("\n\nOrden establecido: %d\n\n", orden);

	if(list != NULL && len > 0)
	{
		status = TRUE;
		if(orden == 1)
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) > 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							if(list[i].sector > list[j].sector)
							{
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}
		}
		else
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) < 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						printf("\n\nValidaci�n 1\n\n");
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							printf("\n\nValidaci�n 2\n\n");
							if(list[i].sector > list[j].sector)
							{
								printf("\n\nValidaci�n 3\n\n");
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}

		}
	}

	return status;
}

/*
brief: Recorre el array e imprime aquellos usuarios donde isEmpty == FALSE
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int printEmployees(Employee* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		puts("---------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID: %d || %s, %s || Salario: %2.f || Sector: %d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
			}
		}
		puts("---------------------------------");
	}

	return status;
}

/*
brief: Recorre el array, acumula los salarios y cuenta los empleados disponibles. Adem�s cuenta cuenta cuantos usuarios pasan el salario promedio y los imprime
param: Struct -> Employee* list || Lista de empleados
param: Int len || Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int promedioEmployees(Employee* list, int len)
{
	int status = FALSE;
	int i;
	float acum = 0;
	int cont = 0;
	float prom;
	int contProm = 0;


	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acum += list[i].salary;
				cont++;
			}
		}

		prom = acum / cont;

		puts("---------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > prom)
			{
				printf("ID: %d || %s, %s || Salario: %2.f || Sector: %d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
				contProm++;
			}
		}
		puts("---------------------------------");
		printf("Cantidad de empleados con un sueldo superior al promedio: %d\n", contProm);
		puts("---------------------------------");

	}

	return status;
}

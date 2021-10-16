#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0) // Valida que el array exista y no se encuentre vacio
	{
		status = TRUE; // Salió bien

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE; // Establece cada "Empleado" como LIBRE
		}
	}

	return status;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && salary >= 0 && sector > 0 && sector < 6) // Valida que el array exista Y no se encuentre vacio y que todos los datos sean llenados
	{
		for(i = 0; i < len; i++) // Recorre el array en busca de un espacio libre
		{
			if(list[i].isEmpty == TRUE) // Verifica sí el espacio se encuentra libre o no
			{
				list[i].isEmpty = FALSE;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				status = TRUE; // Salió bien
				break; // Una vez creado, deja de buscar y corta el bucle
			}
		}
	}

	return status;
}

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

int modifyEmployee(Employee* list, int len, int id)
{
	int status = FALSE;
	int option;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{

		idModify = findEmployeeById(list, len, id);

		puts("---------------------------------");
		puts("¿Que deseas modificar?");
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
				ingresoIntMinMax(&list[idModify].sector, "Ingrese el nuevo sector del empleado (1 a 5): ", "Error. Ingrese un sector válido: ", 1, 5);
				break;
			}
			status = TRUE;
		}
	}

	return status;
}

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

			/*printf("\n\nEntre al caso 1\n\n");
			do
			{
				printf("\n\nBucle 1\n\n");
				flagSwap = FALSE;
				for(i = 0; i < len - 1; i++)
				{
					printf("\n\nBucle 2\n\n");
					if((strcmp(list[i].lastName,list[i+1].lastName) > 0) && (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE))
					{
						printf("\n\nValidación 1\n\n");
						flagSwap = TRUE;
						*listAux=list[i];
						list[i]=list[i+1];
						list[i+1]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[i+1].lastName) == 0) && (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE))
						{
							printf("\n\nValidación 2\n\n");
							if(list[i].sector > list[i+1].sector)
							{
								printf("\n\nValidación 3\n\n");
								flagSwap = TRUE;
								*listAux=list[i];
								list[i]=list[i+1];
								list[i+1]=*listAux;
							}
						}
					}
					len--;
				}
			}while(flagSwap == TRUE);*/
		}
		else
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) < 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						printf("\n\nValidación 1\n\n");
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							printf("\n\nValidación 2\n\n");
							if(list[i].sector > list[j].sector)
							{
								printf("\n\nValidación 3\n\n");
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

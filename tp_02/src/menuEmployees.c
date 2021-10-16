#include "menuEmployees.h"

/*
brief: Inicializa un contador y lo suma cuando se retorna la función
return: Int incrementado en uno
 */
static int getNewId(void)
{
	static int counter = 0;

	return(counter++);
}

/*
brief: Inicializa el menú de la aplicación

 */
void initMenu(void)
{

	int contUsers = 0;
	int option;

	//Variables de usuario
	static int newId;
	static char newName[51];
	static char newLastName[51];
	static float newSalary;
	static int newSector;

	//Variables de busqueda
	int idFounded;
	int order;

	Employee employee[EMPLOYEES];

	initEmployees(employee, EMPLOYEES);

	do
	{
		//Muestra el menú
		puts("---------------------------------");
		puts("1. Dar de alta a nuevo empleado");
		puts("2. Modificar usuario");
		puts("3. Dar de baja empleado");
		puts("4. Informar empleado");
		puts("5. Salir");
		puts("---------------------------------");
		//Fin del menú
		fflush(stdin);
		ingresoIntMinMax(&option,"", "Error, ingrese un numero valido: " , 1, 5);

		switch(option)
		{
		case 1:

			if(contUsers < EMPLOYEES)
			{

				newId = getNewId();
				ingresoCadena(newName, 51, "Ingrese el nombre el empleado: ", "Error. Ingrese nuevamente: ");
				ingresoCadena(newLastName, 51, "Ingrese el apellido el empleado: ", "Error. Ingrese nuevamente: ");
				newSalary = ingresoFloat("Ingrese el salario del empleado: ", "Error. Ingrese un número válido: ");
				while(newSalary < 0)
				{
					newSalary = ingresoFloat("Ingrese un valor positivo: ", "Error. Ingrese un número válido: ");
				}
				ingresoIntMinMax(&newSector, "Ingrese el sector del empleado (1 a 5)", "Error. Ingrese un valor válido", 1, 5);

				if(addEmployee(employee, EMPLOYEES, newId, newName, newLastName, newSalary, newSector) == FALSE)
				{
					puts("---------------------------------");
					puts("Error. ¡Algo salió mal!");
					puts("---------------------------------");
				}
				else
				{
					contUsers++;
					puts("---------------------------------");
					puts("¡Empleado creado con éxito!");
					puts("---------------------------------");
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡Límite de empleados alcanzado!");
				puts("---------------------------------");
			}

			break;
		case 2:
			if(contUsers > 0)
			{
				if(printEmployees(employee, EMPLOYEES) != FALSE)
				{
					idFounded = ingresoInt("Ingrese el número de ID del empleado a modificar: ", "Error. Ingrese un número valido: ");
					if(findEmployeeById(employee, EMPLOYEES, idFounded) != FALSE)
					{
						if(modifyEmployee(employee, EMPLOYEES, idFounded) != FALSE)
						{
							puts("---------------------------------");
							puts("¡Empleado modificado con éxito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. ¡Algo salió mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. ¡Empleado no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen empleados. Debe existir al menos un empleado para usar esta opción!");
				puts("---------------------------------");
			}


			break;
		case 3:
			if(contUsers > 0)
			{
				if(printEmployees(employee, EMPLOYEES) != FALSE)
				{

					idFounded = ingresoInt("Ingrese el número de ID del empleado a eliminar: ", "Error. Ingrese un número valido: ");
					if(findEmployeeById(employee, EMPLOYEES, idFounded) != FALSE)
					{
						if(removeEmployee(employee, EMPLOYEES, idFounded) != FALSE)
						{
							contUsers--;
							puts("---------------------------------");
							puts("Error. ¡Empleado eliminado con éxito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. ¡Algo salió mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. ¡Empleado no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen empleados. Debe existir al menos un empleado para usar esta opción!");
				puts("---------------------------------");
			}

			break;
		case 4:
			if(contUsers > 0)
			{
				puts("---------------------------------");
				puts("Ingrese el orden en el que quieres ordenar los usuarios");
				puts("1. Ascendente");
				puts("2. Descendente");
				puts("---------------------------------");
				ingresoIntMinMax(&order, "", "Error. Ingrese un número válido: ", 1, 2);

				if(sortEmployees(employee, EMPLOYEES, order) != FALSE)
				{
					if(printEmployees(employee, EMPLOYEES) == FALSE)
					{
						puts("---------------------------------");
						puts("Error. ¡Algo salió mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("¡Fin de la impresión!");
						puts("---------------------------------");
					}

					if(promedioEmployees(employee, EMPLOYEES) == FALSE)
					{
						puts("---------------------------------");
						puts("Error. ¡Algo salió mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("¡Fin de la impresión!");
						puts("---------------------------------");
					}
				}
				else
				{
					puts("---------------------------------");
					puts("Error. ¡Algo salió mal!");
					puts("---------------------------------");
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen empleados. Debe existir al menos un empleado para usar esta opción!");
				puts("---------------------------------");
			}

			break;
		case 5:
			puts("---------------------------------");
			puts("¡Aplicación cerrada con éxito!");
			puts("---------------------------------");
			break;
		}


	}while(option != 5);

}

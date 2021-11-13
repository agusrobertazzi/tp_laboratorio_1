#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int status = TRUE;
	FILE* f = fopen(path,"r");

	if(f != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromText(f , pArrayListEmployee) == FALSE)
		{
			status = FALSE;
			/*/rewind(f);
			fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo); // Salteo la primera linea

			do
			{
	        	flag = FALSE;
				fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

		        auxId = atoi(id);

		        index = controller_findEmployee(pArrayListEmployee, auxId);

		        if(index != FALSE)
		        {
			        aux = ll_get(pArrayListEmployee, index);
			        if(aux != NULL)
			        {
			        	employee_delete(aux, pArrayListEmployee, index);
			        	flag = TRUE;
			        }
		        }

			}while(flag == TRUE);*/
		}
		fclose(f);

		employee_setMaxId("idMax.txt", pArrayListEmployee);
	}
	else
	{
		status = FALSE;
	}

    return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int status = TRUE;
	FILE* f = fopen(path,"rb");


	if(f != NULL && pArrayListEmployee != NULL)
	{
		if(parser_EmployeeFromBinary(f , pArrayListEmployee) == FALSE)
		{
			status = FALSE;
			/*rewind(f);

			do
			{
				fread(aux,sizeof(Employee),1,f);

				employee_getId(aux, &auxId);

		        index = controller_findEmployee(pArrayListEmployee, auxId);

		        if(index != FALSE)
		        {
			        aux = ll_get(pArrayListEmployee, index);
			        if(aux != NULL)
			        {
			        	employee_delete(aux, pArrayListEmployee, index);
			        	flag = TRUE;
			        }
		        }

			}while(flag == TRUE);*/
		}
		fclose(f);

		employee_setMaxId("idMax.txt", pArrayListEmployee);
	}
	else
	{
		status = FALSE;
	}

    return status;
}

/** \brief Retorna la posición del usuario mediante su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_findEmployee(LinkedList* pArrayListEmployee, int id)
{
	int status = FALSE;
	int i;
	int auxId;
	Employee* aux = employee_new();

	if(ll_len(pArrayListEmployee) > 0 && id >= 0)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				if(employee_getId(aux, &auxId)== TRUE)
				{
					if(id == auxId)
					{
						status = i;
						break;
					}
				}
			}
		}

	}

	return status;
}

/** \brief Hace un printf del usuario cuyo ID corresponda
 *
 * \param pArrayListEmployee LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_printEmployee(LinkedList* pArrayListEmployee, int id)
{
	int status = FALSE;
	int i;
	static Employee* aux;

	int idAux;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;

	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0 && id >= 0)
	{
		i = controller_findEmployee(pArrayListEmployee, id);
		if(i != FALSE)
		{
			aux = ll_get(pArrayListEmployee, i);

			if(aux != NULL)
			{
				employee_getId(aux, &idAux);
				employee_getNombre(aux, nombreAux);
				employee_getHorasTrabajadas(aux, &horasAux);
				employee_getSueldo(aux, &sueldoAux);
				status = TRUE;
				printf("#%d | Nombre: %s, Horas: %d, Sueldo: %d\n",idAux ,nombreAux , horasAux, sueldoAux);
			}
		}
	}

	return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	int status = FALSE;
	if(pArrayListEmployee != NULL)
	{

		int id;
		char nombreStr[128];
		int horasTrabajadas;
		int sueldo;

		id = employee_getMaxId("idMax.txt", pArrayListEmployee);

		printf("\n%d\n", id);

		ingresoCadena(nombreStr, 128, "Ingrese nombre: ", "Nombre no valido: ");
		while(validarCadena(nombreStr) == 0)
		{
			ingresoCadena(nombreStr, 128, "Ingrese nombre válido: ", "Nombre no valido: ");
		}

		horasTrabajadas = ingresoInt("Ingrese las horas trabajadas: ", "Horas no válidas: ");
		while(horasTrabajadas < 0)
		{
			horasTrabajadas = ingresoInt("Ingrese horas válidas: ", "Horas no válidas: ");
		}

		sueldo = ingresoInt("Ingrese el sueldo del empleado: ", "Sueldo no válido: ");
		while(sueldo <= 0)
		{
			sueldo = ingresoInt("Ingrese un sueldo válido: ", "Sueldo no válido: ");
		}

		Employee* aux = employee_new();
		if(aux != NULL)
		{

			employee_setId(aux, id);
			employee_setNombre(aux, nombreStr);
			employee_setHorasTrabajadas(aux, horasTrabajadas);
			employee_setSueldo(aux, sueldo);

			status = TRUE;
			ll_add(pArrayListEmployee, aux);
			employee_setMaxId("idMax.txt", pArrayListEmployee);
		}

	}

    return status;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int status = FALSE;
	int idElegido;
	int opcionElegida;
	int index;
	Employee* aux;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		idElegido = ingresoInt("Ingrese el ID a modificar: ", "Número no valido: ");
		index = controller_findEmployee(pArrayListEmployee, idElegido);
		if(index != FALSE)
		{
			aux = ll_get(pArrayListEmployee, index);

			controller_printEmployee(pArrayListEmployee, idElegido);

			puts("1. Nombre");
			puts("2. Horas Trabajadas");
			puts("3. Sueldo");
			ingresoIntMinMax(&opcionElegida, "¿Que quiere modificar?:" , "Número no válido: ", 1, 3);

			switch(opcionElegida)
			{
			case 1:
				ingresoCadena(auxNombre, 128, "Ingrese nombre: ", "Nombre no valido: ");
				while(validarCadena(auxNombre) == 0)
				{
					ingresoCadena(auxNombre, 128, "Ingrese nombre válido: ", "Nombre no valido: ");
				}
				employee_setNombre(aux, auxNombre);
				break;
			case 2:
				auxHoras = ingresoInt("Ingrese las horas trabajadas: ", "Horas no válidas: ");
				while(auxHoras < 0)
				{
					auxHoras = ingresoInt("Ingrese horas válidas: ", "Horas no válidas: ");
				}
				employee_setHorasTrabajadas(aux, auxHoras);
				break;
			case 3:
				auxSueldo = ingresoInt("Ingrese el sueldo del empleado: ", "Sueldo no válido: ");
				while(auxSueldo <= 0)
				{
					auxSueldo = ingresoInt("Ingrese un sueldo válido: ", "Sueldo no válido: ");
				}
				employee_setSueldo(aux, auxSueldo);
				break;
			}

			controller_printEmployee(pArrayListEmployee, idElegido);

			status = TRUE;
		}

	}

    return status;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int status = FALSE;
	int idElegido;
	int index;
	Employee* aux;


	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		idElegido = ingresoInt("Ingrese el ID a eliminar: ", "Número no valido: ");
		index = controller_findEmployee(pArrayListEmployee, idElegido);
		if(index != FALSE)
		{
			aux = ll_get(pArrayListEmployee, index);
			if(employee_setMaxId("idMax.txt", pArrayListEmployee) != FALSE)
			{
				if(aux != NULL)
				{
					employee_delete(aux, pArrayListEmployee, index);
				}

				status = TRUE;
			}
		}

	}

    return status;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int status = FALSE;
	Employee* aux;
	int auxId;

	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{

		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				if(employee_getId(aux, &auxId) == TRUE)
				{
					controller_printEmployee(pArrayListEmployee, auxId);
				}
			}
		}

		status = TRUE;

	}

    return status;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int status = FALSE;
	int option;

	if(ll_len(pArrayListEmployee) > 0)
	{
		ingresoIntMinMax(&option, "0. Descendente\n1. Ascendente\nOpción: ", "No válido. Ingrese nuevamente\n0. Descendente\n1. Ascendente\nOpción: ", 0, 1);
		status = ll_sort(pArrayListEmployee, employee_sort, option);
	}

    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int status = FALSE;
    FILE* f = fopen(path,"w");
    Employee* aux;
    int i = 0;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(f!=NULL)
    {
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
        	aux = ll_get(pArrayListEmployee,i);

        	employee_getId(aux, &auxId);
        	employee_getNombre(aux, auxNombre);
        	employee_getHorasTrabajadas(aux, &auxHoras);
        	employee_getSueldo(aux, &auxSueldo);

            fprintf(f,"%d,%s,%d,%d\n", auxId,auxNombre,auxHoras,auxSueldo);
        }
        fclose(f);
    }

    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"wb");
    int i;
    int status = TRUE;
    Employee* aux = employee_new();

    if(f != NULL)
    {

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
        	aux = ll_get(pArrayListEmployee, i);
            if(aux != NULL)
            {
                fwrite(aux,sizeof(Employee),1,f);
            }
        }
        fclose(f);
    }

    return status;
}


#include "Employee.h"

/** \brief Setea en un ARCHIVO el ID máximo
 *
 * \param char* path
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_setMaxId(char* path, LinkedList* pArrayListEmployee)
{
	int status = FALSE;
	int idMax;
	FILE* f = fopen(path, "w");

	if(f != NULL)
	{
		idMax = employee_getMaxId(path, pArrayListEmployee);
		idMax--;
		fprintf(f,"%d",idMax);
		status = idMax;
		fclose(f);
	}

	return status;
}

/** \brief Pide el ID máximo y lo incrementa en 1 para su utilización
 *
 * \param char* path
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_getMaxId(char* path, LinkedList* pArrayListEmployee)
{
	int status = FALSE;
	char idMax[20];
	int i;
	int idAux;
	int idAuxMax;
	int maxId;
	int flagIngreso = FALSE;
	Employee* aux = employee_new();
	FILE* f = fopen(path, "r");
	if(ll_len(pArrayListEmployee) > 0)
	{
		if(f != NULL)
		{
			fscanf(f,"%s", idMax);
			idAux = atoi(idMax);
			idAux++;

			for(i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				aux = ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					employee_getId(aux, &idAuxMax);
					if(flagIngreso == FALSE || idAuxMax > maxId)
					{
						flagIngreso = TRUE;
						maxId = idAuxMax;
					}
				}
			}

			maxId++;
			if(idAux > maxId)
			{
				status = idAux;
			}
			else
			{
				status = maxId;
			}

			fclose(f);
		}
		else
		{
			for(i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				aux = ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					employee_getId(aux, &idAux);
					if(flagIngreso == FALSE || idAux > maxId)
					{
						flagIngreso = TRUE;
						maxId = idAux;
					}
				}
			}

			maxId++;
			status = maxId;

		}
	}
	else
	{
		status = 1;
	}

	return status;
}

//Setters

/** \brief Setea el ID
 *
 * \param Employee* this
 * \param int id
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
	int status = FALSE;
	char idAux[20];

	sprintf(idAux,"%d",id);

	if(this != NULL && validarEntero(idAux)==1)
	{
		status = TRUE;
		this->id = id;
	}

	return status;
}

/** \brief Setea el nombre
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int status = FALSE;

	if(this != NULL && validarCadena(nombre) == 1)
	{
		status = TRUE;
		strcpy(this->nombre, nombre);
	}

	return status;
}

/** \brief Setea las horas trabajadas
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int status = FALSE;
	char auxHoras[20];
	sprintf(auxHoras,"%d",horasTrabajadas);

	if(this != NULL && validarEntero(auxHoras) == 1)
	{
		status = TRUE;
		this->horasTrabajadas = horasTrabajadas;
	}

	return status;
}

/** \brief Setea el sueldo
 *
 * \param Employee* this
 * \param int sueldo
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int status = FALSE;
	char auxSueldo[20];
	sprintf(auxSueldo,"%d",sueldo);

	if(this != NULL && validarEntero(auxSueldo) == 1)
	{
		status = TRUE;
		this->sueldo = sueldo;
	}

	return status;
}

//Getters

/** \brief Pide el ID
 *
 * \param Employee* this
 * \param int* id
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*id = this->id;
	}

	return status;
}

/** \brief Pide el nombre
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		strcpy(nombre, this->nombre);
	}

	return status;
}

/** \brief Pide las horas trabajadas
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*horasTrabajadas = this->horasTrabajadas;
	}

	return status;
}

/** \brief Pide el sueldo
 *
 * \param Employee* this
 * \param int* sueldo
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*sueldo = this->sueldo;
	}

	return status;
}

// Employee
/** \brief Crea un espacio de memoria para una struct Employee*
 *
 * \return Employee*
 *
 */
Employee* employee_new(void)
{

	Employee* aux = malloc(sizeof(Employee));

	return aux;
}

/** \brief Crea un nuevo employee con parametros
 *
 * param char* idStr
 * param char* nombreStr
 * param char* horasTrabajadasStr
 * param char* sueldoSrt
 *
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoSrt)
{
	int auxId;
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* aux = employee_new();

	if(validarEntero(idStr)==1 && validarCadena(nombreStr)==1 && validarEntero(horasTrabajadasStr)==1 && validarEntero(sueldoSrt)==1)
	{

	    auxId=atoi(idStr);
	    auxHorasTrabajadas=atoi(horasTrabajadasStr);
	    auxSueldo=atoi(sueldoSrt);

		if(aux != NULL)
		{
			employee_setId(aux, auxId);
			employee_setNombre(aux, nombreStr);
			employee_setHorasTrabajadas(aux, auxHorasTrabajadas);
			employee_setSueldo(aux, auxSueldo);
		}
	}
	else
	{
		aux = NULL;
	}

	return aux;
}

/** \brief Elimina el espacio de memoria del Employee
 *
 * param Employee* this
 * param LinkedList* linkedList
 * param int index
 *
 */
void employee_delete(Employee* this,LinkedList* linkedList,int index)
{
	if(this != NULL && linkedList != NULL && ll_len(linkedList) > 0 && index >= 0)
	{
		free(this);
		ll_remove(linkedList, index);
	}

}

/** \brief Compara por Nombre a los usuarios
 *
 * void* pFirst
 * void* pSecond
 *
 * return int
 *
 */
int employee_sort(void* pFirst , void* pSecond)
{

	int status = 0;
	char eFirstNombre[128];
	char eSecondNombre[128];
	Employee* eFirts = (Employee*) pFirst;
	Employee* eSecond = (Employee*) pSecond;

	if(employee_getNombre(eFirts, eFirstNombre) != FALSE && employee_getNombre(eSecond, eSecondNombre) != FALSE)
	{
		status = strcmp(eFirstNombre, eSecondNombre);
	}

	return status;

}

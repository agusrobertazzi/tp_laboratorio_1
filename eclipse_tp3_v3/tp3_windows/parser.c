#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int status = TRUE;
	int newId;
    char id[16];
    char nombre[128];
    char horas[256];
    char sueldo[256];
    Employee* aux;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo); // Salteo la primera línea

        do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo) == 4)
            {
                if(controller_findEmployee(pArrayListEmployee, atoi(id)) == FALSE) // Busca sí se encuentra el ID
                {
                	aux = employee_newParametros(id, nombre, horas, sueldo);
                	if(aux != NULL)
                	{
                		ll_add(pArrayListEmployee, aux);
                	}
                	else
                	{
                		status = FALSE;
                		break;
                	}
                }
                else
                {
                	newId = employee_getMaxId("idMax.txt", pArrayListEmployee);
                	sprintf(id, "%d", newId);
                	aux = employee_newParametros(id, nombre, horas, sueldo);
					if(aux != NULL)
					{
						ll_add(pArrayListEmployee, aux);
					}
					else
					{
						status = FALSE;
						break;
					}
                }
            }
            /*else
            {
            	status = FALSE;
            	break;
            }*/

        }while( feof(pFile) == 0 );
    }

    return status;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int status = TRUE;
	int auxId;
	int newId;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
    	Employee* aux;

        do
        {
        	aux=employee_new();

            if(fread(aux,sizeof(Employee),1,pFile)==1)
            {
            	employee_getId(aux, &auxId);
            	if(controller_findEmployee(pArrayListEmployee, auxId) == FALSE)
            	{
            		if(aux != NULL)
            		{
            			ll_add(pArrayListEmployee,aux);
            		}
            		else
            		{
						status = FALSE;
						break;
            		}
            	}
            	else
            	{
            		newId = employee_getMaxId("idMax.txt", pArrayListEmployee);
            		employee_setId(aux, newId);

            		if(aux != NULL)
            		{
            			ll_add(pArrayListEmployee,aux);
            		}
            		else
            		{
						status = FALSE;
						break;
            		}
            	}
            }
            else
            {
                status = FALSE;
                break;
            }

        }while( feof(pFile)==0 );
    }
    return status;

}

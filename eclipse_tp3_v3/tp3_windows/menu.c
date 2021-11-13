#include "menu.h"

/** \brief Inicializa el menu
 *
 */
void init_menu(void)
{
	int flagText = FALSE;
	int flagBin = FALSE;
	int flagBinCreated = FALSE;

	LinkedList* linkedList = ll_newLinkedList();
	int option;
	int initialOption;

	if(linkedList != NULL)
	{
		if(controller_loadFromBinary("dataGeneradoBinary.bin", linkedList) == TRUE)
		{
			flagBin = TRUE;
		}
		else
		{
			puts("-------------------------------------------------");
			puts("Tienes un archivo .csv con usuarios esperando a ser cargados");
			puts("¿Deseas cargarlos ahora? (Sí los cargas ahora, ya quedarán cargados cuando inicies el programa");
			puts("1. Si");
			puts("2. No");
			puts("-------------------------------------------------");
			ingresoIntMinMax(&initialOption, "Opción: ", "Error. Número inválido: ", 1, 2);
			if(initialOption == 1)
			{
				if(controller_loadFromBinary("dataGeneradoBinary.bin", linkedList) == TRUE)
				{
					flagText = TRUE;
					puts("-------------------------------------------------");
					puts("Carga realizada con éxito");
					puts("-------------------------------------------------");
					puts("\n");
				}
			}
		}

		//controller_loadFromBinary("dataGeneradoBinary.bin", linkedList);
		puts("\n\n\n");
		puts("-------------------------------------------------");
		puts("Bienvenido al programa");
		puts("-------------------------------------------------");
		puts("\n\n\n");

		do
		{
			// Inicio de menú
			puts("-------------------------------------------------");
			puts("1. Cargar los datos de los empleados desde archivo .csv (texto)."); // OK
			puts("2. Cargar los datos de los empleados desde archivo .csv (binario)."); // OK
			puts("3. Dar alta de empleado"); // OK
			puts("4. Modificar empleado"); // OK
			puts("5. Dar baja de empleado"); // OK
			puts("6. Listar empleados"); // OK
			puts("7. Ordenar e imprimir empleados"); // OK
			puts("8. Guardar y descargar usuarios en archivo .csv (texto)"); // OK
			puts("9. Guardar y descargar usuarios en archivo .csv (binario)"); // OK
			puts("10. Salir"); // OK
			puts("-------------------------------------------------");
			// Ingreso y validación
			ingresoIntMinMax(&option, "Opcion: ", "Error. Numero no válido; ", 1, 10);
			puts("\n");

			// Revisa opción
			switch(option)
			{

			case 1:

				// Cargar .CSV (Texto)
				if(flagText == FALSE)
				{
					if(flagBin == FALSE)
					{
						if(controller_loadFromText("data.csv", linkedList) == TRUE)
						{
							flagText = TRUE;
							puts("-------------------------------------------------");
							puts("Carga realizada con éxito");
							puts("-------------------------------------------------");
							puts("\n");
						}
						else
						{
							puts("-------------------------------------------------");
							puts("No se ha podido completar la carga");
							puts("-------------------------------------------------");
							puts("\n");
						}
					}
					else
					{
						puts("-------------------------------------------------");
						puts("Ya utilizaste el archivo binario");
						puts("-------------------------------------------------");
						puts("\n");
					}
				}
				else
				{
					puts("-------------------------------------------------");
					puts("Este archivo de texto ya está en uso");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 2:

				// Cargar .TXT (Binario)
				if(flagBin == FALSE)
				{
					if(flagText == FALSE)
					{
						if(flagBinCreated == TRUE)
						{
							if(controller_loadFromBinary("dataGeneradoBinary.bin", linkedList) == TRUE)
							{
								flagBin = TRUE;
								puts("-------------------------------------------------");
								puts("Carga realizada con éxito");
								puts("-------------------------------------------------");
								puts("\n");
							}
							else
							{
								puts("-------------------------------------------------");
								puts("No se ha podido completar la carga");
								puts("-------------------------------------------------");
								puts("\n");
							}
						}
						else
						{
							if(controller_loadFromText("data.csv", linkedList) == TRUE)
							{
								controller_saveAsBinary("dataGeneradoBinary.bin", linkedList);
								puts("-------------------------------------------------");
								puts("Carga realizada con éxito");
								puts("-------------------------------------------------");
								puts("\n");
							}
						}
					}
					else
					{
						puts("-------------------------------------------------");
						puts("Ya utilizaste el archivo de texto");
						puts("-------------------------------------------------");
						puts("\n");
					}
				}
				else
				{
					puts("-------------------------------------------------");
					puts("Este archivo binario ya está en uso");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 3:

				// Agregar nuevo Employee
				if(controller_addEmployee(linkedList) == TRUE)
				{
					puts("-------------------------------------------------");
					puts("Carga realizada con éxito");
					puts("-------------------------------------------------");
					puts("\n");
				}
				else
				{
					puts("-------------------------------------------------");
					puts("No se ha podido completar la carga");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 4:

				// Modificar Employee
				if(ll_len(linkedList) > 0)
				{
					if(controller_editEmployee(linkedList) == TRUE)
					{
						puts("-------------------------------------------------");
						puts("Modificación realizada con éxito");
						puts("-------------------------------------------------");
						puts("\n");
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No se ha podido completar la modificación");
						puts("-------------------------------------------------");
						puts("\n");
					}
				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 5:

				// Baja de Employee
				if(ll_len(linkedList) > 0)
				{
					if(controller_removeEmployee(linkedList) == TRUE)
					{
						puts("-------------------------------------------------");
						puts("Baja realizada con éxito");
						puts("-------------------------------------------------");
						puts("\n");
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No se ha podido completar la baja");
						puts("-------------------------------------------------");
						puts("\n");
					}
				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 6:

				if(ll_len(linkedList) > 0)
				{
					if(controller_ListEmployee(linkedList) != FALSE)
					{
						puts("\n");
						puts("-------------------------------------------------");
						puts("Impresión terminada");
						puts("-------------------------------------------------");
						puts("\n");
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No se ha podido listar");
						puts("-------------------------------------------------");
						puts("\n");
					}
				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 7:

				// 7. Ordenar e imprimir empleados
				if(ll_len(linkedList) > 0)
				{

					if(controller_sortEmployee(linkedList) != FALSE)
					{
						if(controller_ListEmployee(linkedList) != FALSE)
						{
							puts("\n");
							puts("-------------------------------------------------");
							puts("Impresión terminada");
							puts("-------------------------------------------------");
							puts("\n");
						}
						else
						{
							puts("-------------------------------------------------");
							puts("No se ha podido listar");
							puts("-------------------------------------------------");
							puts("\n");
						}
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No sé pudo ordenar correctamente a los Empleados");
						puts("-------------------------------------------------");
						puts("\n");
					}

				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 8:

				// Guardar y descargar archivo .CSV (Texto)
				if(ll_len(linkedList) > 0)
				{

					if(controller_saveAsText("dataGenerado.csv" , linkedList) != FALSE)
					{
						puts("-------------------------------------------------");
						puts("Archivo creado correctamente.");
						puts("-------------------------------------------------");
						puts("\n");
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No se pudo crear archivo de Backup");
						puts("-------------------------------------------------");
						puts("\n");
					}

				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}

				break;
			case 9:
				// Guardar y descargar archivo .TXT (Binario)
				if(ll_len(linkedList) > 0)
				{
					if(controller_saveAsBinary("dataGeneradoBinary.bin", linkedList) != FALSE)
					{
						flagBinCreated = TRUE;
						puts("-------------------------------------------------");
						puts("Archivo creado correctamente.");
						puts("-------------------------------------------------");
						puts("\n");
					}
					else
					{
						puts("-------------------------------------------------");
						puts("No se pudo crear archivo de Backup");
						puts("-------------------------------------------------");
						puts("\n");
					}

				}
				else
				{
					puts("-------------------------------------------------");
					puts("Debes tener al menos un empleado");
					puts("-------------------------------------------------");
					puts("\n");
				}


				break;
			case 10:
				// 10. Salir
				if(ll_len(linkedList) > 0)
				{
					controller_saveAsBinary("dataGeneradoBinary.bin" , linkedList);
				}

				puts("-------------------------------------------------");
				puts("Gracias por usar la aplicación");
				puts("-------------------------------------------------");
				break;
			}

		}
		while(option != 10);
	}
	else
	{
		puts("-------------------------------------------------");
		puts("El programa no inicializó correctamente");
		puts("-------------------------------------------------");
	}

}

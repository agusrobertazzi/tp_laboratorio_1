#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));

	if(newList != NULL)
	{
		newList->size = 0;
		newList->pFirstNode = NULL;
	}

	return newList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int size = -1;

	if(this != NULL)
	{
		size = this->size;
	}

	return size;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* aux = NULL;

	if (this != NULL && (nodeIndex < ll_len(this) && nodeIndex >= 0) && ll_len(this) > 0)
	{
		aux = this->pFirstNode;

		for (int i = 0; i < nodeIndex; i++)
		{
			aux = aux->pNextNode;
		}
	}
	return aux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int status = -1;
    Node* aux;//aux
    Node* newNode;//nuevo nodo
    int size = ll_len(this);
    if (this != NULL && (nodeIndex <= size && nodeIndex >= 0))// 0 1 2 3 4
    {
        newNode = (Node*)malloc(sizeof(Node));
        if(newNode!=NULL)
        {
            if(nodeIndex == 0)
            {
            	aux = getNode(this, nodeIndex);
                newNode->pNextNode = aux;
                this->pFirstNode = newNode;
                status = 0;

            }
            else
            {
            	aux = getNode(this, nodeIndex-1);
                newNode->pNextNode = aux->pNextNode;
                aux->pNextNode=newNode;
                status = 0;

            }

            if(status == 0)
            {
                newNode->pElement = pElement;
                size++;
                this->size=size;
            }
        }
    }

    return status;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

	int status = -1;

	status = addNode(this, ll_len(this), pElement);


	return status;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* aux = getNode(this, index);
    void* status = NULL;

    if(aux != NULL)
    {

    	status = aux->pElement;

    }

    return status;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int status = -1;
    Node* aux;

    if(this != NULL && index < ll_len(this) && index >= 0)
    {
    	aux = getNode(this, index);

    	if(aux != NULL)
    	{
    		aux->pElement = pElement;
    		status = 0;
    	}
    	//errorCode = addNode(this, index, pElement);
    }

    return status;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int status = -1;
    Node* aux;
    Node* memoryRemoved;

    if(this != NULL && index < ll_len(this) && index >= 0)
    {
		if(index == 0)
		{
			aux = getNode(this, index);
			if(aux != NULL)
			{
				this->pFirstNode = aux->pNextNode;

				memoryRemoved = aux;

				status = 0;
			}
		}
		else
		{
			aux = getNode(this, index-1);
			if(aux != NULL)
			{

				memoryRemoved = aux->pNextNode;
				if(index == ll_len(this)-1)
				{
					aux->pNextNode = NULL;
				}
				else
				{
					aux->pNextNode = memoryRemoved->pNextNode;
				}
				status = 0;
			}
		}

		if(status == 0)
		{
			free(memoryRemoved->pElement);
			free(memoryRemoved);
			this->size--;
		}

    }

    return status;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int status = -1;
    int i;

    if(this != NULL)
    {

		for(i = ll_len(this)-1; i >= 0; i--)
		{
			status = ll_remove(this, i);
			if(status == -1)
			{
				break;
			}
		}

    }

    return status;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int status = -1;

    if(this != NULL)
    {
    	status = ll_clear(this);
    	if(status == 0)
    	{
    		free(this);
    	}
    }

    return status;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int status = -1;
	int i;
	Node* aux;

    if(this != NULL)
    {
    	for(i = 0; i < ll_len(this);i++)
    	{
    		aux = getNode(this, i);
    		if(aux != NULL)
    		{
    			if(pElement == aux->pElement)
    			{
    				status = i;
    				break;
    			}
    		}
    	}
    }

    return status;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int status = -1;

    if(this != NULL)
    {
    	if(ll_len(this)>0)
    	{
    		status = 0;
    	}
    	else
    	{
    		status = 1;
    	}
    }

    return status;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int status = -1;

    if(this != NULL && (index <= ll_len(this) && index >= 0))
    {
    	status = addNode(this, index, pElement);
    }

    return status;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* status = NULL;

    status= ll_get(this, index);
	ll_remove(this, index);

	return status;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int status = -1;

	if(this != NULL)
	{
		status = ll_indexOf(this, pElement);

		if(status >= 0)
		{
			status = 1;
		}
		else
		{
			status = 0;
		}
	}

    return status;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int status = -1;
	void* pElement;

	if(this != NULL && this2 != NULL)
	{
		status = 0;

		for(int i = 0; i<ll_len(this2);i++)
		{
			pElement = ll_get(this2, i);
			status = ll_contains(this, pElement);

			if(status == 0)
			{
				break;
			}
		}
	}

	return status;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* status = NULL;

	void* temp;
	int size = ll_len(this);

	if(this!= NULL && from >= 0 && to <= size && from <= to)
	{
		status = ll_newLinkedList();

	    for (int i=from; i<to; i++)
	    {
	    	temp=ll_get(this,i);

	    	if(temp!=NULL)
	    	{
	    		ll_add(status, temp);
	    	}
	    }
	}

	return status;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* status = ll_subList(this, 0, ll_len(this));

    return status;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int i;
	int j;
	int status = -1;
	int len = ll_len(this);
	void* pElementA;
	void* pElementB;

	if(this != NULL && len > 0 && pFunc != NULL && (order == 0 || order == 1))
	{
		if(len >= 2)
		{
			for(i=0 ; i<len-1 ; i++)
			{
				status = 1;

				for(j=(i+1) ; j<len ; j++)
				{
					pElementA=ll_get(this,i);
					pElementB=ll_get(this,j);

					if(pElementA != NULL && pElementB != NULL)
					{
						if (order == 1)
						{
							if(pFunc(pElementA, pElementB)>0)
							{
								ll_set(this, i, pElementB);
								ll_set(this, j, pElementA);

								status = 0;
							}
						}
						else
						{
							if(pFunc(pElementA, pElementB) < 0)
							{
								ll_set(this, i, pElementB);
								ll_set(this, j, pElementA);

								status = 0;
							}
						}
					}
				}

				if(status != 0)
				{
					break;
				}
			}
		}

		status = 0;
	}

	return status;

}


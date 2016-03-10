#include "LinkedList.h"

void LinkedList_Create(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

void LinkedList_Destroy(void)
{
}


int LinkedList_InsertNext(List *list, ListElmnt *element, const void *data)
{
	ListElmnt *new_element;
	if ((new_element = (ListElmnt *)malloc(sizeof(ListElmnt))) == NULL)
		return -1;

	new_element->data = (void *) data;

	if (element == NULL){
		if(list->size == 0)
			list->tail = new_element;
		new_element->next = list->head;
		list->head = new_element;
	}
	else{
		return -1;
	}

	list->size++;
	return 0; 
}

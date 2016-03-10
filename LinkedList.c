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


void LinkedList_InsertNext(List *list, ListElmnt *element, const void *data)
{
	
}

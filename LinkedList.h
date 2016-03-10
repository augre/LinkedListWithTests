#ifndef D_LinkedList_H
#define D_LinkedList_H

/**********************************************************
 *
 * LinkedList is responsible for ...
 *
 **********************************************************/

#include<stdlib.h>

typedef struct ListElmnt_ {
    void *data;
    struct ListElmnt_ *next;
} ListElmnt;

typedef struct List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmnt *head;
    ListElmnt *tail;
} List;

void LinkedList_Create(List *list, void (*destroy)(void * data));
void LinkedList_Destroy(void);
void LinkedList_InsertNext(List *list, ListElmnt *element, const void *data);

#endif  /* D_FakeLinkedList_H */

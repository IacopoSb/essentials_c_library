#include "element.h"
#ifndef LIST_H
#define LIST_H

typedef struct list_element {
element value;
struct list_element *next;
} item;

typedef item *list;

list emptyList(void); // PRIMITIVE
Boolean isEmptyList(list l);
element head(list l);
list tail(list l);
list cons(element e, list l);
//void showList(list l); // NON PRIMITIVE
//Boolean member(element e, list l);
//int lengthList(list l);
//list append(list l1, list l2);
//list reverse(list l);
//list copy(list l);
//list delete(element el, list l);
//list inputordlist(int n);
//list insord(element el, list l);
void freeList(list l);
#endif
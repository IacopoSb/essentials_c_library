#include "list.h"

list emptyList(void) { 
	return NULL;
}

Boolean isEmptyList(list l) {
	if (l==NULL) return true; 
	else return false;
}

element head(list l) {
	if (isEmptyList(l)) fatalError("using \"head\" function on empty list!");
	else return l->value;
}

list tail(list l) {
	if (isEmptyList(l)) fatalError("using \"tail\" function on empty list!");
	else return l->next;
}

list cons(element e, list l)
{
	list t;      
	t = (list)malloc(sizeof(item));
	t->value = e;
	t->next = l;
	return(t);
}
													//NON PRIMITIVE, DA RIELABORARE SE ELEMENT E' STRUCT!!
void showList(list l) {
	printf("[");
	while (!isEmptyList(l)) {
		printElement(head(l));
		l = tail(l);
		if (!isEmptyList(l)) printf(", ");
		} 
	printf("]\n");
}

Boolean member(element el, list l) {
	while (!isEmptyList(l)) {
		if (isEqual(el,head(l))) return true;
		else l = tail(l);
	}
	return false;
}

int lengthList(list l) {
	if (isEmptyList(l)) return 0;
	else return 1 + lengthList(tail(l));
}

list append(list l1, list l2) {
	if (isEmptyList(l1)) return l2;
	return cons(head(l1), append(tail(l1),l2));
}

list reverse(list l) {
	if (isEmptyList(l)) return emptyList();
	else return append(reverse(tail(l)),cons(head(l), emptyList()));
}

list copy(list l) {
	if (isEmptyList(l)) return l;
	else return cons(head(l), copy(tail(l)));
}

list delete(element el, list l) {
	if (isEmptyList(l)) return emptyList();
	else if (el == head(l)) return tail(l);
	else return cons(head(l), delete(el, tail(l)));
}

list inputordlist(int n) { element e;
	if (n<0) exit(1);
	else if (n == 0) return emptyList();
	else { 
		e = getElement();
		return insord(e, inputordlist(n-1));
	}
}

list insord(element el, list l) {
	if (isEmptyList(l)) return cons(el, l);
	else if (isLess(el,head(l)) || isEqual(el,head(l))) return cons(el, l);
	else return cons(head(l), insord(el, tail(l)));
}

void freeList(list l) {
	if (isEmptyList(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}
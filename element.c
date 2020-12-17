#include"element.h"
#include<stdio.h>

#ifdef ISITSTRING


Boolean isEqual(element e1, element e2) {
	if ((strcmp(e1, e2)==0) return true;
	else return false;
}

Boolean isLess(element e1,element e2){
	if ((strcmp(e1, e2)>0) return true;
	else return false;
}


#else

Boolean isEqual(element e1, element e2) {
	return(e1 == e2);
}

Boolean isLess(element e1,element e2){
	return(e1<e2);
}

#endif
element getElement(){
	element el;
	scanf(TYPEOFELEMENTFORFUNCTION,&el);
	return el;}

void printElement(element el){
	printf(TYPEOFELEMENTFORFUNCTION,el);
}

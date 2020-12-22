#include"element.h"

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
	if(e1 == e2) return true;
	else return false;
}

Boolean isLess(element e1,element e2){
	if(e1<e2) return true;
	else return false;
}

#endif
element getElement(){
	element el;
	scanf(TYPEOFELEMENTFORFUNCTION,&el);
	return el;}

void printElement(element el){
	printf(TYPEOFELEMENTFORFUNCTION,el);
}

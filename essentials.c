#include"essentials.h"

void fatalError(char * message){
	printf("\n\nFATAL ERROR:\n\t");
	printf(message);
	printf("\n\n");
	system("pause");
	exit(-1);
}
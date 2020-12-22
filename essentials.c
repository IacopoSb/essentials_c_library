#include"essentials.h"

void fatalError(char * message){
	printf("\n\nFATAL ERROR:\n\t");
	printf(message);
	printf("\n\n");
	system("pause");
	exit(-1);
}

char readField(char buffer[], char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && ch != EOF)
	{
		buffer[i++] = ch;
		ch = fgetc(f);
	}
	buffer[i] = '\0';
	return ch;														//ritorna il separatore (char sep) se e solo se è andato a buon fine
}



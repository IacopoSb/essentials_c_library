#include"essentials.h"

void fatalError(char * message){
	printf("\n\nFATAL ERROR:\n\t");
	printf(message);
	printf("\n\n");
	system("pause");
	exit(-1);
}

char readField(char buffer[], char sep, FILE* f)		//leggi da un file i dati fino a 'sep' e salva in buffer
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && ch != EOF)
	{
		buffer[i++] = ch;
		ch = fgetc(f);
	}
	buffer[i] = '\0';									//sovrascrivi 'sep' con il fine stringa
	return ch;											//ritorna il separatore (char sep) se e solo se è andato a buon fine (ovvero è stato trovato nel file il separatore)
}

void scanfStringBetweenSymbols(char buffer[], int dimension, char symbol){		//leggi da tastiera una stringa compresa tra symbol
	char ch;
	do { 
		ch = getchar(); 
	} while (ch != symbol);
	int i = 0;
	ch = getchar();
	while (ch != symbol && i < dimension - 1) {
		buffer[i] = ch;
		i++;
		ch = getchar(); 
	} 
	nomeCliente[i] = '\0';
	return;
}

void readFileUntil(char sep, FILE* f){					//salta tutti i caratteri da un file fino a 'sep'
	char ch;
	do{
		ch = fgetc(f);
	} while (ch!=symbol);
	return;
}

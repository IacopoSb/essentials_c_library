#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//funzioni comunemente usate NON fondamentali
void fatalError(char * message);												//esce dal programma con messaggio d'errore 'message'
char readField(char buffer[], char sep, FILE* f);								//leggi da un file i dati fino a 'sep' e salva in buffer
void scanfStringBetweenSymbols(char buffer[], int dimension, char symbol);		//leggi da tastiera una stringa compresa tra 'symbol'	ES /Mia Stringa/ se symbol=='/'
void readFileUntil(char sep, FILE* f);											//salta tutti i caratteri da un file fino a 'sep'

#endif
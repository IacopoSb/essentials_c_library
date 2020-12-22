#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//funzioni comunemente usate NON fondamentali
void fatalError(char * message);
char readField(char buffer[], char sep, FILE* f);

#endif
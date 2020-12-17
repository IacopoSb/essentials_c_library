#define _CRT_SECURE_NO_DEPRECATE

#ifndef ELEMENT_H
#define ELEMENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DEFINIZIONE
#define TYPEOFELEMENTFORFUNCTION "%f"
typedef float element; 

//rimuovi il commento se element è una stringa

//#define ISITSTRING

typedef enum { false, true } Boolean;

Boolean isLess(element, element);
Boolean isEqual(element, element);
element getElement(void);
void printElement(element);
#endif
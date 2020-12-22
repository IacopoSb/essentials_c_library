#define _CRT_SECURE_NO_DEPRECATE

#ifndef ELEMENT_H
#define ELEMENT_H


//DEFINIZIONE
#define TYPEOFELEMENTFORFUNCTION "%f"
typedef float element; 

typedef enum { false, true } Boolean;

//se element non è una struttura si possono usare le funzioni sottostanti de-commentandole, altrimenti è necessario ricrearle ad hoc
//vengono usate in alcune funzioni lista non primitive e negli ordinamenti



//se typedef è una stringa, rimuovi il commento per usare le funzioni sottostanti per stringhe

//#define ISITSTRING

/*
Boolean isLess(element a, element b);				//true se a<b, false altrimenti	
Boolean isEqual(element a, element b);				//true se a=b, false altrimentu
element getElement(void);
void printElement(element);
*/
#endif
#define _CRT_SECURE_NO_DEPRECATE
#include "element.h"
#ifndef ORDINAMENTO_H
#define ORDINAMENTO_H

void scambia(element* a, element* b)
int naiveSort(element v[], int n);
int trovaPosMax(element v[], int n);
void bubbleSort(element v[], int n);
void insertSort(element v[], int n);
void insOrd(element v[], int pos);
void mergeSort(element v[], int first, int last, element vout[]);
void merge(element v[], int i1, int i2,	int fine, element vout[]);
void quickSortR(int a[], int iniz, int fine);
void quickSort(int a[], int dim);

#endif
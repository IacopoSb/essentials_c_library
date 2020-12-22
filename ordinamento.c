/*
Le funzioni sono create per un elemento generico "element" e utilizzano le funzioni presenti in essentials.h.
Nel caso di strutture modificare la zona lateralmente commentata a seconda delle richieste del testo
*/
#include"ordinamento.h"


//FUNZIONE FONDAMENTALE SCAMBIA
void scambia(element* a, element* b)
{
	element tmp = *a;
	*a = *b;
	*b = tmp;
}




//NAIVE SORT

int naiveSort(element v[], int n) {
	int p;
	while (n > 1) {
		p = trovaPosMax(v, n);
		if (p < n - 1) scambia(&v[p], &v[n - 1]);
		n--;
	}
}

int trovaPosMax(element v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++) {
		if (!isLess(v[posMax], v[i])) posMax = i;
	}
	return posMax;
}




//BUBBLE SORT

void bubbleSort(element v[], int n) {
	int i, ordinato = 0;
	while (n > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < n - 1; i++){
			if (!isLess(v[i],v[i + 1]))			//v[i]>v[i+1]
				scambia(&v[i], &v[i + 1]);
			ordinato = 0;
			}
		n--;
	}
}






//INSERT SORT

void insertSort(element v[], int n) {
	int k;
	for (k = 1; k < n; k++) {
		insOrd(v, k);
	}
}

void insOrd(element v[], int pos) {
	int i = pos - 1;
	element x = v[pos];
	while (i >= 0 && isLessx (x, v[i])) {		//x<v[i]
		v[i + 1] = v[i];
		i--;
	}
	v[i + 1] = x;
}


//MERGE SORT

void mergeSort(element v[], int first, int last, element vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}

void merge(element v[], int i1, int i2,	int fine, element vout[]) {		//esegue l'ordinamento vero e proprio
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (isLess(v[i], v[j]))			//v[i]<v[j]
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}



//QUICK SORT

void quickSort(element a[], int dim)
{
	quickSortR(a[], 0, dim - 1);
}

void quickSortR(element a[], int iniz, int fine)
{
	int i, j, iPivot;
	element pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && (isless(a[i], pivot) || isEgual(a[i], pivot)) i++;		//a[i]<= pivot
			while (j > i && (!isless(a[i], pivot) || isEgual(a[i], pivot))) j--;		//a[j]>= pivot
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);

		if (i != iPivot && (!isEgual(a[i], a[iPivot]))	//a[i] != a[iPivot]
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
} /* quickSortR */
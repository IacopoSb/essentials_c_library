/*
In questo file sono raccolti i metodi di ordinamento di array

https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

*/
#include"ordinamento.h"


//FUNZIONE FONDAMENTALE SCAMBIA
void scambia(element* a, element* b)
{
	element tmp = *a;
	*a = *b;
	*b = tmp;
}




//NAIVE SORT: il più banale ma il meno efficiente
/*
Cerca il maggiore del vettore e lo sposta in ultima posizione e ripete la ricerca per n-1 elementi (escludendo quindi quelli già spostati come magiori)
*/

int naiveSort(element v[], int n) {
	int p;
	while (n > 1) {
		p = trovaPosMax(v, n);								//p = indice della cella dove si trova il valore massimo
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




//BUBBLE SORT: semplie ma non molto ottimizzato
/*
Corregge il difetto principale del naïve sort: quello di non accorgersi se l’array, a un certo punto, è già ordinato.

Opera per “passate successive” sull’array:
– a ogni iterazione, considera una ad una tutte le possibili coppie di elementi adiacenti, scambiandoli se risultano nell’ordine errato
– così, dopo ogni iterazione, l’elemento massimo è in fondo alla parte di array considerata

Quando non si verificano scambi, l’array è ordinato, e l’algoritmo termina.
*/

void bubbleSort(element v[], int n) {
	int i, ordinato = 0;
	while (n > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < n - 1; i++){
			if (!isLess(v[i],v[i + 1]))
				scambia(&v[i], &v[i + 1]);
			ordinato = 0;
			}
		n--;
	}
}






//INSERT SORT: utilizza il concetto di creazione di un nuovo array, efficente ma complesso
/*
Per ottenere un array ordinato basta costruirlo ordinato, inserendo gli elementi al posto giusto fin dall’inizio.

Idealmente, il metodo costruisce un nuovo array, contenente gli stessi elementi del primo, ma ordinato.

In pratica, non è necessario costruire un secondo array, in quanto le stesse operazioni possono essere svolte direttamente sull’array originale: così, alla fine esso risulterà ordinato.


Scelta di progetto
- “vecchio” e “nuovo” array condividono lo stesso array fisico di N celle (da 0 a N-1)
- in ogni istante, le prime K celle (numerate da 0 a K-1) costituiscono il nuovo array 
- le successive N-K celle costituiscono la parte residua dell’array originale
- Come conseguenza della scelta di progetto fatta, in ogni istante il nuovo elemento da inserire si trova nella cella successiva alla fine del nuovo array, cioè la (K+1)-esima (il cui indice è K)

*/

void insertSort(element v[], int n) {
	int k;
	for (k = 1; k < n; k++) {
		insOrd(v, k);
	}
}

void insOrd(element v[], int pos) {
	int i = pos - 1;
	element x = v[pos];
	while (i >= 0 && isLessx (x, v[i])) {		//determina la posizione in cui va inserito il nuovo elemento
		v[i + 1] = v[i];				// crea lo spazio spostando gli altri elementi in avanti di una posizione
		i--;
	}
	v[i + 1] = x;						//inserisci il nuovo elemento alla posizione prevista
}


//MERGE SORT: molto complesso ma il più efficiente, divide il vettore in sotto-array
/*
Produce sempre due sub-array di egual ampiezza
In pratica:
- si spezza l’array in due parti di ugual dimensione
- si ordinano separatamente queste due parti (chiamata ricorsiva)
- si fondono i due sub-array ordinati così ottenuti in modo da ottenere un unico array ordinato.

Il punto cruciale è l’algoritmo di fusione (merge) dei due array
*/

void mergeSort(element v[], int first, int last, element vout[]) {		//si limita a dividere l'array
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
		if (isLess(v[i], v[j]))
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}



//QUICK SORT: molto complesso e l'efficienza varia dalla scelta del valore di pivot
/*
Come merge-sort, suddivide il vettore in due sotto-array, delimitati da un elemento “sentinella” (pivot)

Il pivot viene spostato in modo opportuno in modo da raggiungere…

…l’obiettivo che è quello di avere nel primo sotto-array solo elementi minori o uguali al pivot, nel secondo sotto-array solo elementi maggiori


Struttura dell’algoritmo:
- scegliere un elemento come pivot
- partizionare l’array nei due sub-array
- ordinarli separatamente (ricorsione)

L’operazione-base è il partizionamento dell’array nei due sub-array. Per farla:
- se il primo sub-array ha un elemento > pivot, e il secondo array un elemento < pivot, questi due elementi vengono scambiati

Poi si riapplica quicksort ai due sub-array.


Esecuzione:
Si determina arbitrariamente un pivot
– ad esempio pivot = a[dim - 1]

Si scandisce il vettore dato mediante due indici:
– i, che parte da 0 e procede in avanti
– j, che parte da dim - 1 (dim = dimensione del vettore) e procede all’indietro

Scansione in avanti: ogni elemento a[i] viene confrontato con il pivot
– se a[i] > pivot, la scansione in avanti si ferma e si passa alla…

Scansione all’indietro: ogni elemento a[j] viene confrontato con il pivot
– se a[j] < pivot, la scansione in indietro si ferma e l’elemento a[j] viene scambiato con a[i]

Poi si riprende con la scansione avanti, indietro, ...
– Il tutto si ferma quando i == j. A questo punto si scambia a[i] con il pivot

Alla fine della scansione il pivot è collocato nella sua posizione definitiva

L’algoritmo è ricorsivo: si richiama su ciascun sottoarray fino a quando non si ottengono sotto-array con un solo elemento

A questo punto il vettore iniziale risulta ordinato!



La complessità dipende dalla scelta del pivot:
- se il pivot è scelto male (uno dei due sub-array ha lunghezza zero), i confronti sono N^2
- se però il pivot è scelto bene (in modo da avere due sub-array di egual dimensione): Numero globale di confronti: O(N log2 N)

Dunque:
- Il Quick Sort è efficiente come il Merge Sort se il pivot è scelto correttamente
- Se si ha sfortuna allora l’efficienza scende fino ad un livello compatibile con il Bubble Sort (che non è proprio un fulmine…)
*/

void quickSort(int a[], int dim)			//Si introduce una funzione che fa da interfaccia con i clienti e che invoca opportunamente la funzione ricorsiva
{
	quickSortR(a[], 0, dim - 1);
}

void quickSortR(int a[], int iniz, int fine)
{
	int i, j, iPivot, pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		/* determinati i due sottoinsiemi */
/* posiziona il pivot */
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
} /* quickSortR */
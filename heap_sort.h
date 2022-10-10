#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "print_swap.h"

/*
	HEAP SORT
	Complessità temporale: O(N log N)
	Spazio ausiliario: O(1)
		
	L'heapsort, per eseguire l'ordinamento, utilizza una struttura chiamata heap; 
	Un heap è rappresentabile con un albero binario in cui tutti i nodi seguono una data proprietà, detta priorità. 
	Esso è completo almeno fino al penultimo livello dell'albero (con le foglie sull'ultimo livello compattate a sinistra) 
	In uno heap decrescente (utilizzato per ordinare ad esempio un array in senso crescente) ogni nodo padre contiene un 
	valore maggiore o uguale a quello dei suoi due figli diretti, di conseguenza risulterà maggiore anche di tutti i nodi 
	che si trovano nel sottoalbero di cui esso è la radice.

	Gli elementi che si trovano nella seconda metà dell'array rappresenteranno foglie dello heap e quindi esse saranno già
	al loro posto giusto e non vi è infatti alcun elemento dopo di esse.

	L'ordinamento dell'heap NON è affatto un algoritmo Divide and Conquer. 
	Utilizza una struttura di dati heap per ordinare in modo efficiente il suo elemento e non un "approccio divide 
	et impera" per ordinare gli elementi.

	Confronto con il selection sort
	L'ordinamento dell'heap è simile all'ordinamento della selezione, ma con un modo migliore per ottenere l'elemento 
	massimo. Sfrutta la struttura dei dati dell'heap per ottenere l'elemento massimo in un tempo costante.
*/

#include<cmath>
int heapsize;

void maxHeapify(int arr[], int i)
{
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<heapsize && arr[l]>arr[max])
		max = l;

	if(r<heapsize && arr[r]>arr[max])
		max = r;

	if(max != i)
	{
		swap(arr[i], arr[max]);
		maxHeapify(arr, max);
	}
}

void buildMaxHeap(int arr[])
{
	int n = heapsize;
	for(int i=floor(n/2); i>=0; i--)	//tutti gli elementi nel sottoarray [floor(n/2)...n] sono foglie dell'albero
		maxHeapify(arr, i);
}

void heapSort(int arr[], int n)
{
	heapsize = n;
	buildMaxHeap(arr);		//O(n)
	for(int i=n-1; i>0; i--)
	{
		swap(arr[0], arr[i]);
		heapsize--;
		maxHeapify(arr, 0);		//O(log n)
	}
}

#endif
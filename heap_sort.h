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

// To heapify a subtree rooted with node i (which is an index in arr[]) 
// n is size of heap
void MaxHeapify(int arr[], int n, int i)
{
    //Indexes
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    //Sistemo la struttura in modo che non ci siano figli più grandi dei genitori

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

    //Ripeto ricorsivamente la procedura in modo da estendere la proprietà al resto delle foglie

        // Recursively heapify the affected sub-tree
        MaxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = floor(n/2) ; i >= 0; i--)
        MaxHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) 
    {   
        swap(arr[0], arr[i]);   // Move current root(MAX element) to end
                                //ex.    9 3 4 8 2 6
                                //       3 4 8 2 6 9
        MaxHeapify(arr, i, 0);  // call max heapify on the reduced heap
    }
}

#endif
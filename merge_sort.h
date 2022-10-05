#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "print_swap.h"

//Merge sort                        Complessità totale : O(n log n) in ogni caso

//Procedura Merge per la combinazione
void merge(int vet[], int start, int middle, int end)
{
    int i = start;
	int j = middle +1;
	int k = start;
	int aux[end+1]; //vettore ausiliario di dimensione n

    while(i <= middle && j <= end)
    {
        if(vet[i] <= vet[j]) //Inserisco in auxl'elemento minore delle partizioni ordinate
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    }

    //Se "consumo" una delle due partizioni devo inserire in ordine tutti gli elementi dell'altra
    while(i <= middle)
        aux[k++] = vet[i++];

    while(j <= end)
        aux[k++] = vet[j++];

    for(k = start; k <= end; k++) //Copio i valori nell'array di partenza
		vet[k] = aux[k];
}

//Algoritmo di suddivisione
void merge_sort(int vet[], int start, int end){
	
    if(start < end) //Se c'è più di un elemento
    {
        int middle = floor((start+end)/2);
        merge_sort(vet, start, middle);
        merge_sort(vet, middle+1, end);
        merge(vet, start, middle, end);
    }
}

void merge_sort(int vet[], int n){
    //Richiamo passando il vettore, l'indice del primo e dell'ultimo elemento
    merge_sort(vet, 0, n-1);
}

#endif
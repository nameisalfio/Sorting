#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "print_swap.h"

void countingSort(int A[],int n)
{ 
    //Calcolo del range 
    int max = A[0];
    int min = A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i] < min)  min = A[i];
        if(A[i] > max)  max = A[i];
    }
    int range = max-min+1;

    int B[range]{0};    //vettore contatore
    
    //incremento l'elemento di indice x per ogni ricorrenza di  x in A
    for(int i=0; i<n; i++)
        ++B[A[i]];
    
    //modifico il vettore B in modo da avere nell'elemento di indice i, il numero di elementi minori o uguali di i nel vettore A
    //implicitamente ci da informazione su dove collocare l'elemento nel vettore risultante
    for(int i=1; i<range; i++)
        B[i] = B[i]+B[i-1];     //sommo ad ogni elemento il valore del precedente
    
    int ris[n]; //vettore risultato
    for(int i=0; i<n; i++)
        ris[--B[A[i]]] = A[i];

        //B[A[i]]--;    //prima decremento il numero di elementi minori o uguali rimanenti
        //ris[B[A[i]]] = A[i];  //poi inserisco la ricorrenza appena rimossa nella posizione corretta

    //copio gli elementi ordinati nel vettore A
    for(int i=0; i<n; i++)
        A[i] = ris[i];
}

#endif
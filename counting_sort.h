#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

/*
    CountingSort
    L’algoritmo counting sort suppone che ciascuno degli n elementi di input sia un numero intero compreso nell’intervallo da 0 a k, per
    qualche intero k. Quando il range di valori è confrontabile con il numero di elementi da ordinare, quindi se k = O(n), l’ordinamento 
    viene effettuato nel tempo Teta(n), ma più correttamente, la complessità di Counting Sort è Teta(n+k). 
    Il concetto che sta alla base di counting sort è determinare, per ogni elemento di input x, il 
    numero di elementi minori di x. Nel codice di counting sort, supponiamo che l’input sia un array A[1 . . n], quindi lunghezza[A] = n. 
    Occorrono altri due array: 
        - l’array B[1 . . n] contiene l’output ordinato; 
        - l’array C[0 . . k] fornisce la memoria temporanea di lavoro;

    Un’importante proprietà di counting sort è la stabilità: i numeri con lo stesso valore si presentano nell’array di output nello stesso 
    ordine in cui si trovano nell’array di input. Ovvero, i pareggi fra due numeri vengono risolti applicando la seguente regola: 
        "il numero che si presenta per primo nell’array di input sarà inserito per primo nell’array di output". 

    Normalmente, la proprietà della stabilità è importante soltanto quando i dati satellite vengono spostati insieme con gli elementi da 
    ordinare. La stabilità di counting sort è importante per un’altra ragione: counting sort viene spesso utilizzato come subroutine 
    di radix sort.

*/

#include "print_swap.h"

int getMax(int A[], int n){
    int max = A[0];
    for(int i=0; i<n; i++)
        if(A[i] > max)  max = A[i];
    return max;
}
int getMin(int A[], int n){
    int min = A[0];
    for(int i=0; i<n; i++)
        if(A[i] < min)  min = A[i];
    return min;
}

void countingSort(int A[],int n)
{ 
    //Calcolo del range 
    int max = getMax(A, n);
    int min = getMin(A, n);
    int range = max-min+1;

    int C[range]{0};    //counting
    for(int i=0; i<n; i++)
        C[A[i]]++;      //incremento per ogni ricorrenza dell'elemento A[i] trovata

    for(int i=1; i<range; i++)
        C[i] += C[i-1]; //in C[i] ho il numero di elementi minori o uguali ad i nell'array di input

    int B[n];   //output
    for(int i=n-1; i>=0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;      //decremento C[A[i]] per tenere conto degli elementi uguali inseriti
    }

    for(int i=0; i<n; i++)  //ricopio i valori ordinati nell'array di input
        A[i] = C[i];
}

#endif
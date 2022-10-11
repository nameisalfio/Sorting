#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

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
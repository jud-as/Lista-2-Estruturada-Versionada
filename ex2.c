#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort() {
    int aux, n, i;
    int array[6]={66, 2, 13, 70, 90, 2};

    for ( n = 1; n <=5; n++)
    {
        for ( i = 0; i <= 3; i++)
        {
            if (array[i] > array[i+1])
            {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
            
        }
        
    }

}

void quickSwap(int array[], int i, int j) {
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

int particionaSwap(int array[], int inicio, int fim) {
    int pivo, pivo_indice, i;

    pivo = array[fim];
    pivo_indice = inicio;

    for ( i = inicio; i < fim; i++)
    {
        if (array[i] <= pivo)
        {
            quickSwap(array, i, pivo_indice);
            pivo_indice++;
        }
        
    }

    quickSwap(array, pivo_indice, fim);
    return pivo_indice;
    
}

int particionaRandom(int array[], int inicio, int fim) {

    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
    quickSwap(array, pivo_indice, fim);
    return particionaSwap(array, inicio, fim);
}

void quickSort(int array[], int inicio, int fim) {

    if (inicio < fim)
    {
        int pivo_indice = particionaRandom(array, inicio, fim);
        quickSort(array, inicio, pivo_indice -1);
        quickSort(array, pivo_indice +1, fim);
    }
}


void mergeSort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int*v, int *c, int i, int m, int f);

void mergeSort(int *v, int n) {
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n-1);
    free(c);
}

void sort(int *v, int *c, int i, int f) {
    if (i >= f) return;
    int m = (i + f) /2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);

    if (v[m] <= v[m + 1]) return;

    merge(v, c, i, m, f);
}

void merge(int *v, int *c, int i, int m, int f) {
    int z,
        iv = i, ic = m + 1;

    for (z = i; z <= f; z++) c[z] = v[z];

    z = i;

    while (iv <= m && ic <= f)
    {
        if (c[iv] <= c[ic]) v[z++] = c[iv++];
        else v[z++] = c[ic++];    
    }

    while (iv <= m ) v[z++] = c[iv++];
    
    while (ic <= f ) v[z++] = c[ic++];
}

int main() {
    int array[5]={3, 22, 96, 50, 68};
    int v[8] = { 1, 7, 55, 23, 89, 99, 11, 40 };
    int i;
    srand(time(NULL));

    //bubble sort implement//

    clock_t inicial = clock();
    bubbleSort();
    printf("\n\n\nBubble Sort: \n\n");
    for ( i = 0; i <=6-1; i++)
    {
        printf("%d \t", array[i]);
    }
    clock_t final = clock();
    double tempoBubbleSort = (double)(final-inicial) / CLOCKS_PER_SEC;
      
    //quick sort implement//
    
    inicial = clock();
    quickSort(array, 0, 5-1);
    printf("\n\n\nQuick Sort: \n\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%d\t", array[i]);
    }
    final = clock();
    double tempoQuickSort = (double)(final-inicial) / CLOCKS_PER_SEC;
    
    //mergesort implement//

    inicial = clock();
    mergeSort(v, 8);
    printf("\n\n\nMerge Sort: \n\n");
    for ( i = 0; i < 8; i++)
    {
        printf("%d\t", v[i]);
    }
    final = clock();
    double tempoMergeSort = (double)(final-inicial) / CLOCKS_PER_SEC;

    printf("\n\n\n---------------------------------------\n");
    printf("Tempo Bubble Sort: %lf segundos\n", tempoBubbleSort);
    printf("Tempo Merge Sort: %lf segundos\n", tempoMergeSort);
    printf("Tempo QuickSort: %lf segundos\n", tempoQuickSort);
    return 0;
}
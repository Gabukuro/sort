#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "sorts.c"
#include "utils.c"

int main()
{
    int option, i;

    printf("\nDo you want to view the input and output values ?\n[ 1 ] - YES\n[ 0 ] - NO\n\nYour choice: ");
    scanf("%d", &option);

    system("cls || clear");

    for (i = 1; i <= 6; i++)
    {

        float j = pow(10, i);
        int size = (int) j;
        int *vetor;
        clock_t Ticks[2];

        vetor = (int *)malloc(size * sizeof(int));

        createRandomVetor(vetor, size);

        printf("\nData ordering tests for vectors with %i values:\n\n", size);
        printf("\tSort type\t==\tRuntime (seconds)\n");
        teste(vetor, size, bubbleSort, "BubbleSort", option);
        teste(vetor, size, selectionSort, "SelectionSort", option);
        teste(vetor, size, insertionSort, "InsertionSort", option);
        teste(vetor, size, quickSort, "QuickSort", option);
        teste(vetor, size, mergeSort, "MergeSort", option);
    }

    return 0;
}

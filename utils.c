#include <time.h>
#include <stdlib.h>

void createRandomVetor(int *vetor, int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        vetor[i] = rand() % size;
    }
}

void printVetor(int *vetor, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("\t[ %i, ", vetor[i]);
        }
        else if (i == (size - 1))
        {
            printf("%i ]\n", vetor[i]);
        }
        else
        {
            printf("%i, ", vetor[i]);
        }
    }
}

void copiaVetor(int *vetOriginal, int *vetCopia, int size)
{
    for (int i = 0; i < size; i++)
    {
        vetCopia[i] = vetOriginal[i];
    }
}

void teste(int *vetor, int size, void (*func)(int *, int, int), char sorType[], int option)
{
    float runtime;
    int *vetorCopia;
    vetorCopia = (int *)malloc(size * sizeof(int));
    clock_t start, end;

    copiaVetor(vetor, vetorCopia, size);

    if (strcmp(sorType, "QuickSort") == 0 || strcmp(sorType, "MergeSort") == 0)
    {
        start = clock();
        func(vetorCopia, 0, size - 1);
        end = clock();
    }
    else
    {
        start = clock();
        func(vetorCopia, size, 0);
        end = clock();
    }

    runtime = ((float)end - start) / CLOCKS_PER_SEC;

    printf("\t%s\t==\t%f\n", sorType, runtime);

    if (option == 1)
    {
        printf("\tInput:\n");
        printVetor(vetor, size);
        printf("\tOutput:\n");
        printVetor(vetorCopia, size);
        printf("\n");
    }
}
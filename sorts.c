void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *vetor, int size, int a)
{
	int i, j;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void selectionSort(int *vetor, int size, int a)
{
    int menor, i, j;
    for (i = 0; i < size - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < size; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        swap(&vetor[i], &vetor[menor]);
    }
}

void insertionSort(int *vetor, int size, int a)
{
    int key, j, i;
    for (i = 0 + 1; i < size; i++)
    {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}

int partition(int *vetor, int left, int right)
{
    int pivot = vetor[right];
    int i = (left - 1);
    int j;
    for (j = left; j < right; j++)
    {
        if (vetor[j] < pivot)
        {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[right]);
    return (i + 1);
}

void quickSort(int *vetor, int left, int right)
{
    if (left < right)
    {
        int pi = partition(vetor, left, right);

        quickSort(vetor, left, pi - 1);
        quickSort(vetor, pi + 1, right);
    }
}

void merge(int *vetor, int left, int mid, int right)
{

    int size1 = right - left + 1;
    int size2 = right - mid;
    int *temp;
    temp = (int *)malloc(size1 * sizeof(int));

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (vetor[i] <= vetor[j])
        {
            temp[k] = vetor[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = vetor[i];
        k++;
        i++;
    }

    while (j <= right)
    {
        temp[k] = vetor[j];
        k++;
        j++;
    }

    for (i = left; i <= right; i++)
    {
        vetor[i] = temp[i - left];
    }
}

void mergeSort(int *vetor, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid + 1, right);
        merge(vetor, left, mid, right);
    }
}

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;  /* declaración afuera */
    
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int n, i;
    
    if (argc < 2) {
        printf("%s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    n = argc - 1;

    /* reservar arreglo */
    int *arr = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        arr[i] = atoi(argv[i + 1]);

    quicksort(arr, 0, n - 1);

    printf("Arreglo ordenado: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

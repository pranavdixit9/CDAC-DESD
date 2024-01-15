#include <stdio.h>
#include <stdlib.h>

// Function to partition the array into two subarrays
// Returns the position of the pivot element
int split(int *arr, int lower, int higher);

// Recursive function to perform quicksort
void quicksort(int *arr, int lower, int higher);

// Function to display the elements of an array within a given range
void display(int *arr, int lower, int higher);

int main() {
    int size;

    printf("Enter size of array\n");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter array :\n");

    for (int i = 0; i < size; i++)
        scanf("%d", arr + i);

    printf("Unsorted array :");
    display(arr, 0, size);

    // Start the quicksort process
    quicksort(arr, 0, size - 1); `

    printf("Sorted Array :");
    display(arr, 0, size);

    free(arr);
    return 0;
}

// Function to partition the array and return the pivot position
int split(int *arr, int lower, int higher) {
    int p, q, temp;

    p = lower + 1;
    q = higher;

    while (q >= p) {

        while (arr[p] < arr[lower])
            p++;

        while (arr[q] > arr[lower])
            q--;

        if (q > p) {
            temp = arr[q];
            arr[q] = arr[p];
            arr[p] = temp;
        }
    }

    temp = arr[q];
    arr[q] = arr[lower];
    arr[lower] = temp;

    return q;                                               // Return the position of the pivot
}

// Recursive function to perform quicksort
void quicksort(int *arr, int lower, int higher) {
    int i;

    if (higher > lower) {
        i = split(arr, lower, higher);
        quicksort(arr, lower, i - 1);                       // Sort the left subarray
        quicksort(arr, i + 1, higher);                      // Sort the right subarray
    }
}

// Function to display the elements of an array within a given range
void display(int *arr, int lower, int higher) {
    for (int i = lower; i < higher; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
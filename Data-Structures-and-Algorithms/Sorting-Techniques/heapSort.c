#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void sort(int *, int);
void heap(int *, int, int);

int main() {
    int size;

    // Prompt the user for the size of the array
    printf("Enter Size of array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int *arr = (int *)malloc(sizeof(int) * size);

    if (arr == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }

    // Prompt the user to input the array elements
    printf("Enter array to be sorted: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    // Display the unsorted array
    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", *(arr + i));
    }
    printf("\n\n");

    // Call the sorting function to sort the array
    sort(arr, size);

    // Display the sorted array
    printf("Sorted Array:   ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", *(arr + i));
    }
    printf("\n\n");

    return 0;
}

// Function to perform Heap Sort
void sort(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        // Build the initial max-heap
        heap(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        // Extract the maximum element and place it at the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heap(arr, i, 0);
    }
}

// Function to maintain the max-heap property
void heap(int *arr, int size, int i) {
    int largest, temp, left, right;

    right = 2 * i + 2;
    left = 2 * i + 1;

    if (left >= size)
        return;                                                 // Leaf nodes are already max-heaps

    largest = i;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        temp = arr[i];                                         // Swap the largest element with the root
        arr[i] = arr[largest];
        arr[largest] = temp;

        heap(arr, size, largest);                             // Recursively heapify the affected subtree
    }
}

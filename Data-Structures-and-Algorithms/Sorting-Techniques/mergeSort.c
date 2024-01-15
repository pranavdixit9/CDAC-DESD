#include <stdio.h>
#include <stdlib.h>

void partition(int *, int, int);                  	// Function to split and merge arrays
void merge_sort(int *, int, int, int, int);       	// Function to merge two sorted arrays
void display(int *, int, int);                   	// Function to display the contents of an array

int main() {
    int size, choice;

    int *arr;

    printf("Enter Size of Array: ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);      	// Allocate memory for the array

    if (arr == NULL) {                            	// NULL check for MALLOC
        printf("Memory can't be allocated\n");
        exit(0);
    }

    printf("Enter array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);                      	// Input array elements
    }

    printf("Entered Array: ");
    display(arr, 0, size - 1);

    partition(arr, 0, size - 1);                  	// Sort the array

    printf("\n\nFinal Sorted Array: ");
    display(arr, 0, size - 1);

    free(arr);

    return 0;
}

void display(int *arr, int first, int last) 
{
    for (int i = first; i <= last; i++) 
    {
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void partition(int *arr, int first, int last) {
    printf("Splitting Arrays from index %d to %d:\n", first, last);

    if (first >= last) 
    {
        return;                                   	// Base case: If the array is empty or has one element, it's already sorted
    }

    int mid = (first + last) / 2;                	// Calculate the middle index of the array
    partition(arr, first, mid);                   	// Recursively split the left half of the array
    partition(arr, (mid + 1), last);             	// Recursively split the right half of the array
    display(arr, first, mid);                     	// Display the left half of the array
    display(arr, mid + 1, last);                 	// Display the right half of the array
    merge_sort(arr, first, mid, mid + 1, last);   	// Merge the two sorted halves
    display(arr, first, last);                   	// Display the merged array
}

void merge_sort(int *arr, int first, int last, int first1, int last1) 
{
    int *result;
    int size = (last - first + 1) + (last1 - first1 + 1);

    result = (int *)malloc(sizeof(int) * size);

    if (result == NULL) 							// NULL check for MALLOC
    {
        printf("Memory for the merged array can't be allocated\n");
        exit(1);
    }

    int k = 0, i = first;
    int j = first1;

    while (i <= last && j <= last1) 
    {
        if (arr[i] < arr[j]) 
        {
            result[k] = arr[i];  					// If the element at 'i' in the left subarray is smaller, copy it to the result.
            i++;
            k++;
        } else 
        {
            result[k] = arr[j];  					// If the element at 'j' in the right subarray is smaller or equal, copy it to the result.
            j++;
            k++;
        }
    }

    while (i <= last) 
    {
        result[k] = arr[i];  						// Copy any remaining elements in the left subarray to the result.
        i++;
        k++;
    }

    while (j <= last1) 
    {
        result[k] = arr[j];  						// Copy any remaining elements in the right subarray to the result.
        j++;
        k++;
    }

    k = 0;

    for (int a = first; a <= last1; a++) 
    {
        arr[a] = result[k];  						// Copy the sorted elements from the result back to the original array.
        k++;
    }

    display(arr, first, last1);  					// Display the merged and sorted subarray.

    free(result);  									// Free the memory allocated for the result array.
}
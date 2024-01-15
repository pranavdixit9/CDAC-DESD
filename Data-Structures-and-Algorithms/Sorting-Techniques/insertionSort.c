#include<stdio.h>
#include<stdlib.h>

int n;
void insertEle(int *, int);
void displayArr(int *, int);
void insSort(int *arr, int n);
int main()
{
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int count;
	int *arr;

	arr = (int *)malloc(n*sizeof(int));
	if(arr == NULL)
	{
		printf("Array Creation Failed!\n");
	}

	insertEle(arr,n);
	printf("Before Sorting: \n");
	displayArr(arr,n);

	insSort(arr,n);
	printf("After Sorting: \n");
	displayArr(arr,n);

	free(arr);
}
void insertEle(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d", &arr[i]);
	}
	printf("\n");
	printf("Array Defined Successfully!\n");
	printf("\n");
}
void displayArr(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("\n");
}

void insSort(int *arr, int n)
{
    int temp, j;

    for (int i = 0; i < n; i++)						    // Loop through the array from the second element (index 1) to the last.
    {
        temp = arr[i];									// Store the current element to be inserted in its correct position.
        j = i - 1;

        // Compare the current element (temp) with the elements before it and
        // shift the larger elements to the right to make space for the current element.
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j]; 						// Shift the element to the right.
            j -= 1;             						// Move to the previous element for comparison.
        }

        arr[j + 1] = temp;								// Insert the current element (temp) into its correct position.
    }
}


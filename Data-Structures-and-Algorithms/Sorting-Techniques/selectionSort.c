#include<stdio.h>
#include<stdlib.h>

#define swap(type,a,b) {type t; t = a; a = b; b = t;}				//macro to swap elements of array

int n;
void insertEle(int *, int);
void displayArr(int *, int);
void seleSort(int *arr, int n);
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

	seleSort(arr,n);
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

void seleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_i = i;							//take first element as initial smallest element

        for (int j = i + 1; j < n; j++)			//inner loop starts from i plus one; that is from element after ith element 
        {
            if (arr[j] < arr[min_i])
            {
                min_i = j;						//update min_i to lowest element of array
            }
        }

        if (min_i != i)							//if min_i != i, swap the elements, will bring smallest element to the starting, repeat in iteration.
        {
            swap(int, arr[min_i], arr[i]);
        }
    }
}

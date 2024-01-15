#include<stdio.h>
#include<stdlib.h>

#define swap(type,a,b) {type t; t = a; a = b; b = t;}				//macro to swap elements of array

int n;
void insertEle(int *, int);
void displayArr(int *, int);
void bubSort(int *, int);
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

	bubSort(arr,n);
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
void bubSort(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(int, arr[j], arr[j+1]);
			}
		}
	}
}
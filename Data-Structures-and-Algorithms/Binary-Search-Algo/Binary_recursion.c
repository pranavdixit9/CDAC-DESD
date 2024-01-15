#include<stdio.h>
#include<stdlib.h>

#define swap(type,a,b) {type t; t = a; a = b; b = t;}				//macro to swap elements of array

void sort(int *, int);
int binSearch(int *, int, int, int);
void display(int *, int);

int main()
{
	int size;

	printf("Enter the size of array: ");								//User defined size of array
	scanf("%d", &size);

	int arr[size];			

	for(int i = 0; i < size; i++)										//Unique elements filled in array
	{
		int flag=0;
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
		for(int j=0;j<=i;j++)
		{
			if(arr[i]==arr[j])
			{
				flag++;
			}
		}
		if(flag>1)
		{
			printf("Please enter a unique element!\n");
			--i;
		}	
	}

	printf("----ENTERED ARRAY----\n");
	display(arr, size);

	printf("----SORTED ARRAY----\n");
	sort(arr, size);
	display(arr, size);

	int sear;
	printf("Enter the element to search: ");
	scanf("%d", &sear);

	int f = binSearch(arr, 0, size, sear);							//calling binary search
	if(f == -1)
	{
		printf("Number not found!\n");
	}
	else
	{
		printf("%d was found at position %d\n", sear, f+1);	
	}
}

void sort(int *arr, int n)						//using Selection sort to sort array before applying merge sort
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

void display(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

#include <stdio.h>

int binSearch(int *arr, int start, int end, int sear) 
{
    if (end >= start) 
    {
        int mid = start + (end - start) / 2; 						// Calculate the middle index of the current search range.

        if (arr[mid] == sear) 
        {
            return mid; 											// The target element is found at index 'mid'.
        }

        if (arr[mid] > sear) 
        {
            										// If the middle element is greater than the target, recursively search in the left half of the array.
            return binSearch(arr, start, mid - 1, sear);
        } else 
        {
            										// If the middle element is less than the target, recursively search in the right half of the array.
            return binSearch(arr, mid + 1, end, sear);
        }
    }

    return -1; 														// If the target is not found in the array, return -1.
}

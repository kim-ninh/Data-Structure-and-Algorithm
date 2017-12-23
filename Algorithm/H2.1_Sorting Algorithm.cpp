//Sorting Algorithm.cpp
#include"H2.1_Sorting Algorithm.h"
void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectionSort(int a[], int n)
{
	for(int i = 0; i < n -1; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (a[i] > a[min])
			Swap(a[min], a[i]);
			
	}
}

void Heapify(int arr[], int n, int i)
{
	int saved = arr[i];
	while (i < n / 2)
	{
		int child = 2 * i + 1;
		if (child < n - 1)
			if (arr[child] < arr[child + 1]) child++;
		if (saved >= arr[child]) break;
		arr[i] = arr[child];
		i = child;
	}
	arr[i] = saved;
}

void buildHeap(int arr[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	while (n != 0)
	{
		Swap(arr[0], arr[n - 1]);
		Heapify(arr, n - 1, 0);
		n--;
	}
}
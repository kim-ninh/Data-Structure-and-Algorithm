#include<iostream>
#include"PriorityQueue.cpp"
using namespace std;

void topDown(int arr[],int n, int i)
{
	int hold = arr[i];
	while (i < n / 2)
	{
		int child = 2 * i + 1;
		if (child < n - 1)
			if (arr[child] < arr[child + 1])child++;
		if (arr[child] < hold)
			break;
		arr[i] = arr[child];
		i = child;
	}
	arr[i] = hold;
}

void bottomUp(int arr[], int n, int i)
{
	int hold = arr[i];
	while (i > 0)
	{
		int parent = (i - 2 + i % 2) / 2;
		if (arr[parent] > hold)
			break;
		arr[i] = arr[parent];
		i = parent;
	}
	arr[i] = hold;
}

void buildHeap(int a[], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		topDown(a, n, i);
	//or
	/*for (int i = n - 1; i > 0; i--)
		bottomUp(a, n, i);*/
}

void heapSort(int a[], int n)
{
	buildHeap(a, n);
	while (n > 0)
	{
		swap(a[0], a[n - 1]);
		n--;
		topDown(a, n, 0);
	}
}

int main()
{
	/*int a[] = { 9,5,7,3,2,10,22,69,35,96 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	
	heapSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;*/
	PRIORITY_QUEUE<int> aQ;
	
	aQ.insert(21);
	aQ.insert(13);
	aQ.insert(16);
	aQ.insert(24);
	aQ.insert(31);
	aQ.insert(19);
	aQ.insert(68);
	aQ.insert(65);
	aQ.insert(26);
	aQ.insert(32);

	int n;
	while (!aQ.isEmpty())
	{
		aQ.deleteMin(n);
		cout << n << endl;
	}
	/*for (int i = 0; i <= aQ.rear; i++)
		cout << aQ.items[i] << endl;*/

	system("pause");
	return 0;
}
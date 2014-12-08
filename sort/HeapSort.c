#include "stdio.h"
#include "time.h"

const int N = 20;

void show(int *arr, int len)
{
	int i;
	for(i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void adjustdown(int *arr, int i, int end)
{
	int key = arr[i];
	int p = i;
	int left = 2 * p + 1;

	while(left <= end)
	{
		//no swap
		if(key >= arr[left] && (left + 1 <= end && key >= arr[left + 1]))
		{
			break;
		}
		else if(key >= arr[left] && left + 1 > end)
		{
			break;
		}
		//swap left
		else if(key < arr[left] && left + 1 <= end && arr[left] > arr[left + 1])
		{
			swap(arr + p, arr + left);
			p = left;
			left = 2 * p + 1;
		}
		else if(key < arr[left] && left + 1 > end)
		{
			swap(arr + p, arr + left);
			p = left;
			left = 2 * p + 1;
		}
		//swap left + 1
		else if(key < arr[left + 1] && left + 1 <= end && arr[left + 1] >= arr[left])
		{
			swap(arr + p, arr + left + 1);
			p = left + 1;
			left = 2 * p + 1;
		}
	}
}

void heapSort(int *arr, int len)
{
	int p;
	int end;

	for(p = (len - 1 - 1) / 2; p >= 0; --p)
	{
		adjustdown(arr, p, len - 1);
	}

	for(end = len - 1; end >= 1; --end)
	{
		swap(arr, arr + end);
		adjustdown(arr, 0, end - 1);
	}
}

int main(int argc, char const *argv[])
{
	int arr[N], index;
	srand(time(NULL));

	for(index = 0; index < N; ++ index)
	{
		arr[index] = rand() % 100 + 1;
	}
	show(arr, N);
	heapSort(arr, N);
	show(arr, N);

	return 0;
}
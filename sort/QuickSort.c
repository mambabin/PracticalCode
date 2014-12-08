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

int partition(int *arr, int len)
{
	int low, high;
	int key;
	key = arr[0];
	low = 0;
	high = len - 1;

	while(low < high)
	{
		while(low < high && arr[high] >= key)
		{
			high--;
		}
		if(low >= high)
		{
			break;
		}
		else
		{
			swap(&arr[low], &arr[high]);
		}

		while(low < high && arr[low] < key)
		{
			low++;
		}
		if(low < high)
		{
			swap(&arr[low], &arr[high]);
		}
	}
	return low;
}

void quickSort(int *arr, int len)
{
	if(len == 0 || len == 1)
		return;
	int k;
	k = partition(arr, len);
	quickSort(arr, k);
	quickSort(arr + k + 1, len - k - 1);
}

int main(int argc, char const *argv[])
{
	int arr[N], index;
	srand(time(NULL));

	for(index = 0; index < N; ++index)
	{
		arr[index] = rand() % 100 + 1;
	}

	show(arr, N);
	quickSort(arr, N);
	show(arr, N);

	return 0;
}
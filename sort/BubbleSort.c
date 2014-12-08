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

void bubbleSort(int *arr, int len)
{
	int pos, index;
	for(pos = 0; pos < len - 1; ++pos)
	{
		for(index = 0; index < len - 1 - pos; ++index)
		{
			if(arr[index] > arr[index + 1])
				swap(arr + index, arr + index + 1);
		}
	}
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
	bubbleSort(arr, N);
	show(arr, N);

	return 0;
}
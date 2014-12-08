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

void selectSort(int *arr, int len)
{
	int pos, index;
	int minIndex;

	for(pos = 0; pos < len - 1; ++pos)
	{
		minIndex = pos;
		for(index = pos + 1; index < len; ++index)
		{
			if(arr[index] < arr[minIndex])
				minIndex = index;
		}
		if(minIndex != pos)
			swap(arr + pos, arr + minIndex);
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
	selectSort(arr, N);
	show(arr, N);

	return 0;
}
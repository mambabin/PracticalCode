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

void insertSort(int *arr, int len)
{
	int pos, index;
	int key;

	for(pos = 1; pos < len; ++pos)
	{
		key = arr[pos];
		for(index = pos - 1; index >= 0; --index)
		{
			if(key < arr[index])
			{
				arr[index + 1] = arr[index];
			}
			else
				break;
		}
		arr[index + 1] = key;
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
	insertSort(arr, N);
	show(arr, N);
	
	return 0;
}
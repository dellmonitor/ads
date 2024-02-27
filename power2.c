#include <stdio.h>
#include <stdlib.h>

int isPowerOfTwo(int x)
{
	return (x != 0) && (x & (x - 1)) == 0;
}

int combinations(int *array, int start, int end, int sum)
{ 
	if (start == end)
	{
		return isPowerOfTwo(sum);
	}
	return combinations(array, start + 1, end, sum + array[start]) + combinations(array, start + 1, end, sum);
}

int main(int argc, char **argv)
{
	int n, i, count;
	scanf("%d", &n);
	int *array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", array + i);
	}
	count = combinations(array, 0, n, 0);
	printf("%d", count);
	free(array);
	return 0;
}

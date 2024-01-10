#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b, int *base)
{
	int store = base[a];
	base[a] = base[b];
	base[b] = store;
	return;
}

int partion(int low, int high, int *base)
{
	int i = low, j = low;
	while (i < high) {
		if (base[i] < base[high]) {
			swap(i, j, base);
			i = i + 1;
		}
		j = j + 1;
	}
	swap(i, high, base);
	return i;
}

void quickSortRec(int low, int high, int *base)
{
	int q;
	while (low < high) {
		printf("%d\n", low);
		printf("%d\n", high);
		printf("%d\n", q);
		q = partion(low, high, base);
		if (q - low < high - q) {
			quickSortRec(low, q - 1, base);
			low = q + 1;
		}
		else {
			quickSortRec(q + 1, high, base);
			high = q - 1;
		}
	}
	return;
}

void quickSort(int nel, int *base)
{
	quickSortRec(0, nel - 1, base);
	return;
}

void selectSort(int nel, int *base)
{
	int j = nel - 1, k, i;
	while (j > 0) {
		k = j;
		i = j - 1;
		while (i >= 0) {
			if (base[k] < base[i])
				k = i;
			i = i - 1;
		}
		swap(j, k, base);
		j = j - 1;
	}
	return;
}

int main(int argc, char **argv)
{
	int n, m, i;
	scanf("%d %d", &n, &m);
	int *array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	if (n < m)
		quickSort(n, array);
	else
		selectSort(n, array);
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	free(array);
	return 0;
}

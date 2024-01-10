#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)
{
	if (abs(a) < abs(b))
		return -1;
	else if (abs(a) > abs(b))
		return 1;
	return 0;
}

void merge(int k, int l, int m, int *base)
{
	int i = k, j = l + 1, h = 0;
	int *aux = (int*)malloc((m - k + 1) * sizeof(int));
	while (h < m - k + 1) {
		if ((j <= m) && ((i == l + 1) || (compare(base[j], base[i]) == -1))) {
			aux[h] = base[j];
			j = j + 1;
		}
		else {
			aux[h] = base[i];
			i = i + 1;
		}
		h = h + 1;
	}
	for (i = 0; i < h; i++)
		base[k + i] = aux[i];
	free(aux);
}

void mergeSortRec(int low, int high, int *base)
{
	int mid;
	if  (low < high) {
		mid = (low + high) / 2;
		mergeSortRec(low, mid, base);
		mergeSortRec(mid + 1, high, base);
		merge(low, mid, high, base);
	}
	return;
}

void mergeSort(int nel, int *base)
{
	mergeSortRec(0, nel - 1, base);
	return;
}
void insertSort(int nel, int *base)
{
	int i = 1, elem, loc;
	while (i < nel) {
		elem = base[i];
		loc = i - 1;
		while ((loc >= 0) && (compare(base[loc], elem) == 1)) {
			base[loc + 1] = base[loc];
			loc = loc - 1;
		}
		base[loc + 1] = elem;
		i = i + 1;
	}
	return;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	int *array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	if (n < 5)
		insertSort(n, array);
	else
		mergeSort(n, array);
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	free(array);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

union Int32 {
	int x;
	unsigned char bytes[4];
};

union Int32 *distributionSort(unsigned char (*key)(union Int32 c, int place), int place, int card, union Int32 *base, int nel)
{
	int *count = (int*)calloc(card, sizeof(int));
	int j = 0, k, i;
	while (j < nel) {
		k = key(base[j], place);
		count[k] = count[k] + 1;
		j = j + 1;
	}
	i = 1;
	while (i < card) {
		count[i] = count[i] + count[i - 1];
		i = i + 1;
	}
	union Int32 *d = (union Int32*)malloc(nel * sizeof(union Int32));
	j = nel - 1;
	while (j >= 0) {
		k = key(base[j], place);
		i = count[k] - 1;
		count[k] = i;
		d[i] = base[j];
		j = j - 1;
	}
	free(count);
	free(base);
	return d;
}

unsigned char placeKey(union Int32 number, int place)
{
	if (place == 3)
		return number.bytes[place] ^ 128;
	return number.bytes[place];
}

union Int32 *radixSort(int radix, union Int32 *numbers, int nel)
{
	int i = 0;
	while (i < radix) {
		numbers = distributionSort(placeKey, i, 256, numbers, nel);
		i++;
	}
	return numbers;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	union Int32 *numbers = (union Int32*)malloc(n * sizeof(union Int32));
	for (i = 0; i < n; i++)
		scanf("%d", &numbers[i].x);
	numbers = radixSort(4, numbers, n);
	for (i = 0; i < n; i++)
		printf("%d ", numbers[i].x);
	free(numbers);
	return 0;
}

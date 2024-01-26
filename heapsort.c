#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pair {
	char *string;
	int aCount;
};

void swap(void *base, int a, int b, size_t width)
{
	size_t storeByte;
	char *aByteAddress = (char*)base + a * width, 
	     *bByteAddress = (char*)base + b * width;
	for (size_t i = 0; i < width; i++) {
		storeByte = *aByteAddress;
		*aByteAddress = *bByteAddress;
		*bByteAddress = storeByte;
		aByteAddress++;
		bByteAddress++;
	}
	return;
}

int cmp(const void *a, const void *b)
{
	return ((struct Pair*)a)->aCount - ((struct Pair*)b)->aCount;
}

const void *elementAddress(void *base, size_t index, size_t width)
{
	return (const void*)((size_t)base + index * width);
}

void heapify (void *base, size_t i, size_t nel, size_t width,
		int (*compare)(const void *a, const void *b))
{
	size_t left, right, j = i;
	do {
		swap(base, i, j, width);
		left = 2 * i + 1;
		right = left + 1;
		j = i;
		if ((left < nel) && (compare(elementAddress(base, i, width), 
					     elementAddress(base, left, width)) < 0))
			i = left;
		if ((right < nel) && (compare(elementAddress(base, i, width),
					      elementAddress(base, right, width)) < 0))
			i = right;
	} while (i != j);
	return;
}

void buildHeap(void *base, size_t nel, size_t width,
		int (*compare)(const void *a, const void *b))
{
	int i = (nel / 2) - 1;
	while (i >= 0) {
		heapify(base, i, nel, width, compare);
		i--;
	}
	return;
}

void hsort(void *base, size_t nel, size_t width,
		int (*compare)(const void *a, const void *b))
{
	buildHeap(base, nel, width, compare);
	int i = nel - 1;
	while (i > 0) {
		swap(base, 0, i, width);
		heapify(base, 0, i, width, compare);
		i--;
	}
	return;
}

int countA(char *string)
{
	int i, count = 0;
	for (i = 0; string[i] != '\0'; i++)
		if (string[i] == 'a')
			count++;
	return count;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	struct Pair *array = (struct Pair*)malloc(n * sizeof(struct Pair));
	for (i = 0; i < n; i++) {
		scanf("%ms", &array[i].string);
		array[i].aCount = countA(array[i].string);
	}
	hsort(array, n, sizeof(struct Pair), cmp);
	for (i = 0; i < n; i++) {
		printf("%s ", array[i].string);
		free(array[i].string);
	}
	free(array);
	return 0;
}

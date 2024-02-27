#include <stdlib.h>

unsigned long *fibonacci(unsigned long limit)
{
	unsigned long previous_fibonacci= 1, next_fibonacci = 1, store;
	unsigned long *fibonacci_sequence = (unsigned long*)calloc(100,sizeof(unsigned long));
	fibonacci_sequence[0] = 0;
	fibonacci_sequence[1] = 1;
	int i = 2;
	while (fibonacci_sequence[i - 2] + fibonacci_sequence[i - 1] < limit) {
		fibonacci_sequence[i] = fibonacci_sequence[i - 2] + fibonacci_sequence[i - 1];
		i++;
	}
	return fibonacci_sequence;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
	if (nel == 0 || nel == 1)
		return;
	unsigned long i, j, k, loc, d;
	unsigned long *fibonacci_sequence = fibonacci(nel);
	for (i = 99; fibonacci_sequence[i] == 0; i--);
	do {
		d = fibonacci_sequence[i];
		for (j = d; j < nel; j++) {
			for (loc = j - d; loc >= 0 && loc < nel && compare(loc, loc + d) == 1; loc = loc - d) {
				swap(loc, loc + d);
			}
		}
		i--;
	} while (i >= 2);
	free(fibonacci_sequence);
	return;
}

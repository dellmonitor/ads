#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned long x, fibonacci_sequence[100], previous_fibonacci= 1, next_fibonacci = 1, store;
	scanf("%ld", &x);
	int i = 0;
	while ((next_fibonacci > 0) && (next_fibonacci <= x)) {
		store = next_fibonacci;
		next_fibonacci = next_fibonacci + previous_fibonacci;
		previous_fibonacci = store;
		fibonacci_sequence[i] = previous_fibonacci;
		i = i + 1;
	}
	i = i - 1;
	if (x == 0) printf("0");
	else {
		for (i; i >= 0; i--) {
			if (fibonacci_sequence[i] <= x) {
				printf("1");
				x = x - fibonacci_sequence[i];
			}
			else printf("0");
		}
	}
}

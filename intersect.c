#include <stdio.h>

unsigned int power_of_two(int i)
{
	unsigned int value = 1;
	while (i > 0) {
		value = value << 1;
		i = i - 1;
	}
	return value;
}


int main(int argc, char **argv)
{
	int cardA, cardB, i, a_number, b_number;
	unsigned int A = 0, B = 0, intersect;
	scanf("%d", &cardA);
	for (i = 0; i < cardA; i++) {
		scanf("%d", &a_number);
		A = A + power_of_two(a_number);
	}
	scanf("%d", &cardB);
	for (i = 0; i < cardB; i++) {
		scanf("%d", &b_number);
		B = B + power_of_two(b_number);
	}
	intersect = A & B;
	for (i = 0; i < 32; i++) {
		if (intersect % 2) printf("%d ", i);
		intersect = intersect >> 1;
	}
	return 0;
}

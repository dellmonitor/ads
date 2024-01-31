#include <stdio.h>

int main(int argc, char **argv)
{
	int cardA, cardB, i, a_number, b_number;
	unsigned int A = 0, B = 0, intersect;
	scanf("%d", &cardA);
	for (i = 0; i < cardA; i++) {
		scanf("%d", &a_number);
		A = A + (1 << a_number);
	}
	scanf("%d", &cardB);
	for (i = 0; i < cardB; i++) {
		scanf("%d", &b_number);
		B = B + (1 << b_number);
	}
	intersect = A & B;
	for (i = 0; i < 32; i++) {
		if (intersect % 2) printf("%d ", i);
		intersect = intersect >> 1;
	}
	return 0;
}

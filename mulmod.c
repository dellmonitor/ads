#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned long a, b, m, mulmod = 0;
	scanf("%ld%ld%ld", &a, &b, &m);
	int i, bits[64];
	for (i = 0; i < 64; i++) {
		bits[i] = b % 2;
		b = b >> 1;
	}
	for (i = 63; i > 0; i--) {
		mulmod = ((mulmod % m + (a % m) * bits[i]) % m) * 2;
	}
	mulmod = (mulmod % m + (a % m) * bits[0]) % m;
	printf("%ld", mulmod);
	return 0;
}

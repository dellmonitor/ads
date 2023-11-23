#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	long x0, a, polynom_value = 0, derivative_value = 0;
	scanf("%d", &n);
	scanf("%ld", &x0);
	for (int i = n; i > 0; i--) {
		scanf("%ld", &a);
		polynom_value = (polynom_value + a) * x0;
		if (i != 1) derivative_value = (derivative_value + a * i) * x0;
		else derivative_value = derivative_value + a;
	}
	scanf("%ld", &a);
	polynom_value = polynom_value + a;
	printf("%ld %ld", polynom_value, derivative_value);
	return 0;
}

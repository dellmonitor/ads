#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n, a, b;
	scanf("%d", &n);
	char bar;
	float *fractions = (float*)malloc(n * sizeof(float));
	for (int i = 0; i < n; i++) {
		scanf("%d%1c%d", &a, &bar, &b);
		fractions[i] = ((float)a) / ((float)b);
	}
	int left = 0, right = 0, start = 0, i = 0, minLen = 0;
	float prod = 1, maxProd = fractions[0];
	while (i < n) {
		prod = prod * fractions[i];
		if (prod > maxProd) {
			maxProd = prod;
			left = start;
			right = i;
			minLen = right - left;
		}
		else if ((prod == maxProd) && (i - start < minLen)) {
			left = start;
			right = i;
			minLen = i - start;
		}
		i = i + 1;
		if (prod < 1) {
			prod = 1;
			start = i;
		}
	}
	printf("%d %d", left, right);
	free(fractions);
	return 0;
}

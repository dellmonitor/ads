#include <stdio.h>

int main(int argc, char **argv)
{
	int n, i, k;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &k);
	long sum = 0;
	for (i = 0; i < k; i++) sum += a[i];
	long maxk = sum;
	for (i = k; i < n; i++) {
		sum = sum + a[i] - a[i - k];
		if (sum > maxk) maxk = sum;
	}
	printf("%ld", maxk);
	return 0;
}

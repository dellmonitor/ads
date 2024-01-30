#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	int store;
	while (b != 0) {
		store = a;
		a = b;
		b = store % b;
	}
	return a;
}

int *ComputeLogarithms(int m)
{
	int *logarithmTable = (int*)malloc((1 << m) * sizeof(int));
	int i = 1, j = 0;
	while (i - 1 < m) {
		while (j < (1 << i)) {
			logarithmTable[j] = i - 1;
			j = j + 1;
		}
		i = i + 1;
	}
	return logarithmTable;
}

int **SparseTableBuild(int *base, int nel, int *logarithmTable)
{
	int m = logarithmTable[nel] + 1, i, j;
	int **sparseTable = (int**)calloc(nel, sizeof(int*));
	for (i = 0; i < nel; i++) {
		sparseTable[i] = (int*)calloc(m, sizeof(int));
		sparseTable[i][0] = (base[i] > 0) ? base[i] : (- base[i]);
	}
	for (j = 1; j < m; j++)
		for (i = 0; i <= nel - (1 << j); i++)
			sparseTable[i][j] = gcd(sparseTable[i][j - 1],
						sparseTable[i + (1 << (j - 1))][j - 1]);
	return sparseTable;
}

int SparseTableQuery(int **sparseTable, int left, int right, int *logarithmTable)
{
	int j = logarithmTable[right - left + 1];
	return gcd(sparseTable[left][j], sparseTable[right - (1 << j) + 1][j]);
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	int *array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	int *logarithmTable = ComputeLogarithms(32 - (__builtin_clz(n + 1)));
	int **sparseTable = SparseTableBuild(array, n, logarithmTable);
	int m, left, right, intervalGCD;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &left, &right);
		intervalGCD = SparseTableQuery(sparseTable, left, right, logarithmTable);
		printf("%d\n", intervalGCD);
	}
	free(array);
	free(logarithmTable);
	for (i = 0; i < n; i++)
		free(sparseTable[i]);
	free(sparseTable);
	return 0;
}

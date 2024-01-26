#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int query(int *base, int left, int right, int i, int a, int b)
{
	int maxElement;
	if ((left == a) && (right == b))
		maxElement = base[i];
	else {
		int mid = (a + b) / 2;
		if (right <= mid)
			maxElement = query(base, left, right, 2 * i + 1, a, mid);
		else if (left > mid)
			maxElement = query(base, left, right, 2 * i + 2, mid + 1, b);
		else
			maxElement = max(query(base, left, mid, 2 * i + 1, a, mid), query(base, mid + 1, right, 2 * i + 2, mid + 1, b));
	}
	return maxElement;
}

int segmentTreeQuery(int *base, int nel, int left, int right)
{
	int maxElement = query(base, left, right, 0, 0, nel - 1);
	return maxElement;
}

void build(int *base, int i, int a, int b, int *t)
{
	if (a == b)
		t[i] = base[a];
	else {
		int mid = (a + b) / 2;
		build(base, 2 * i + 1, a, mid, t);
		build(base, 2 * i + 2, mid + 1, b, t);
		t[i] = max(t[2 * i + 1], t[2 * i + 2]);
	}
	return;
}

int *segmentTreeBuild(int *base, int nel) {
	int *segmentTree = (int*)calloc(4 * nel, sizeof(int));
	build(base, 0, 0, nel - 1, segmentTree);
	return segmentTree;
}

void update(int index, int value, int i, int a, int b, int *base)
{
	if (a == b)
		base[i] = value;
	else {
		int mid = (a + b) / 2;
		if (index <= mid)
			update(index, value, 2 * i + 1, a, mid, base);
		else
			update(index, value, 2 * i + 2, mid + 1, b, base);
		base[i] = max(base[2 * i + 1], base[2 * i + 2]);
	}
	return;
}

void segmentTreeUpdate(int index, int value, int nel, int *base)
{
	update(index, value, 0, 0, nel - 1, base);
	return;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	int *array = (int*)malloc(n * sizeof(n));
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	int *segmentTree = segmentTreeBuild(array, n);
	char operation[4];
	scanf("%s", &operation);
	int left, right, index, value, maxElement;
	while (strcmp(operation, "END") != 0) {
		if (strcmp(operation, "MAX") == 0) {
			scanf("%d%d", &left, &right);
			maxElement = segmentTreeQuery(segmentTree, n, left, right);
			printf("%d\n", maxElement);
		}
		else if (strcmp(operation, "UPD") == 0) {
			scanf("%d%d", &index, &value);
			segmentTreeUpdate(index, value, n, segmentTree);
		}
		scanf("%s", &operation);
	}
	free(array);
	free(segmentTree);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Three
{
	int index, k, cap;
	int *v;
} Three;

typedef struct PriorityQueue
{
	struct Three **heap;
	int cap, count;
} PriorityQueue;

void swap(Three *a, Three *b)
{
	Three store = *a;
	*a = *b;
	*b = store;
	return;
}

int less(Three *a, Three *b)
{
	return (a->v[a->k] < b->v[b->k]);
}

PriorityQueue InitPriorityQueue(int n)
{
	PriorityQueue q;
	q.heap = (Three**)malloc(n * sizeof(Three*));
	q.cap = n;
	q.count = 0;
	return q;
}

Three *Maximum(PriorityQueue *q)
{
	return q->heap[0];
}

void Insert(PriorityQueue *q, Three *ptr)
{
	int i = q->count;
	q->count = i + 1;
	q->heap[i] = ptr;
	while ((i > 0) && less(q->heap[(i - 1) / 2], q->heap[i]))
	{
		swap(q->heap[(i - 1) / 2], q->heap[i]);
		q->heap[i]->index = i;
		i = (i - 1) / 2;
	}
	q->heap[i]->index = i;
	return;
}

void IncreaseKey(PriorityQueue *q, Three *ptr)
{
	int i = ptr->index;
	ptr->k = ptr->k + 1;
	while ((i > 0) && less(q->heap[(i - 1) / 2], ptr))
	{
		swap(q->heap[(i - 1) / 2], q->heap[i]);
		q->heap[i]->index = i;
		i = (i - 1) / 2;
	}
	ptr->index = i;
	return;
}

void Heapify(int i, int n, Three **heap)
{
	int left, right, j;
	while (1)
	{
		left = 2 * i + 1;
		right = left + 1;
		j = i;
		if ((left < n) && less(heap[i], heap[left]))
		{
			i = left;
		}
		if ((right < n) && (less(heap[i], heap[right])))
		{
			i = right;
		}
		if (i == j)
		{
			break;
		}
		swap(heap[i], heap[j]);
		heap[i]->index = i;
		heap[j]->index = j;
	}
}

Three *ExtractMax(PriorityQueue *q)
{
	Three *ptr = q->heap[0];
	q->count = q->count - 1;
	if (q->count > 0)
	{
		q->heap[0] = q->heap[q->count];
		q->heap[0]->index = 0;
		Heapify(0, q->count, q->heap);
	}
	return ptr;
}

int main()
{
	int k, i, j;
	scanf("%d", &k);
	int *n = (int*)malloc(k * sizeof(int));
	int **arrays = (int**)malloc(k * sizeof(int*));
	for (i = 0; i < k; i++)
	{
		scanf("%d", n + i);
		arrays[i] = (int*)malloc(n[i] * sizeof(int));
	}
	PriorityQueue q = InitPriorityQueue(k);
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n[i]; j++)
		{
			int d;
			scanf("%d", &d);
			arrays[i][j] = -d;
		}
		Three *ptr = (Three*)malloc(sizeof(Three));
		ptr->index = i;
		ptr->k = 0;
		ptr->v = arrays[i];
		ptr->cap = n[i];
		Insert(&q, ptr);
	}
	int size = 0;
	for (i = 0; i < k; i++) size = size + n[i];
	int *sorted = (int*)malloc(size * sizeof(int));
	Three *max;
	for (i = 0; i < size; i++)
	{
		max = ExtractMax(&q);
		sorted[i] = max->v[max->k];
		if (max->k + 1 != max->cap)
		{
			max->k = max->k + 1;
			Insert(&q, max);
		}
		else
		{
			free(max);
		}
	}
	for (int j = 0; j < size; j++) printf("%d ", -sorted[j]);
	printf("\n");
	for (i = 0; i < k; i++)
	{
		free(arrays[i]);
	}
	free(arrays);
	free(n);
	free(sorted);
	free(q.heap);
}

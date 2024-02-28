#include <stdio.h>
#include <stdlib.h>

typedef struct Two
{
	int index, v;
} Two;

typedef struct PriorityQueue
{
	struct Two **heap;
	int cap, count;
} PriorityQueue;

void swap(Two *a, Two *b)
{
	Two store = *a;
	*a = *b;
	*b = store;
	return;
}

int greater(Two *a, Two *b)
{
	return (a->v > b->v);
}

PriorityQueue InitPriorityQueue(int n)
{
	PriorityQueue q;
	q.heap = (Two**)malloc(n * sizeof(Two*));
	q.cap = n;
	q.count = 0;
	return q;
}

void Insert(PriorityQueue *q, Two *ptr)
{
	int i = q->count;
	q->count = i + 1;
	q->heap[i] = ptr;
	while ((i > 0) && greater(q->heap[(i - 1) / 2], q->heap[i]))
	{
		swap(q->heap[(i - 1) / 2], q->heap[i]);
		q->heap[i]->index = i;
		i = (i - 1) / 2;
	}
	q->heap[i]->index = i;
	return;
}

void Heapify(int i, int n, Two **heap)
{
	int left, right, j;
	while (1)
	{
		left = 2 * i + 1;
		right = left + 1;
		j = i;
		if ((left < n) && greater(heap[i], heap[left]))
		{
			i = left;
		}
		if ((right < n) && (greater(heap[i], heap[right])))
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

Two *ExtractMin(PriorityQueue *q)
{
	Two *ptr = q->heap[0];
	q->count = q->count - 1;
	if (q->count > 0)
	{
		q->heap[0] = q->heap[q->count];
		q->heap[0]->index = 0;
		Heapify(0, q->count, q->heap);
	}
	return ptr;
}

int main(int argc, char** argv)
{
	int n, m, i, start, end, ttk;
	Two *firstout;
	end = 0;
	scanf("%d %d", &n, &m);
	PriorityQueue pq = InitPriorityQueue(n);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &start, &ttk);
		Two *ptr = (Two*)malloc(sizeof(Two));
		ptr->index = pq.count;
		if (pq.count == n)
		{
			firstout = ExtractMin(&pq);
			start = start > firstout->v ? start : firstout->v;
			free(firstout);
		}
		ptr->v = start + ttk;
		end = end < ptr->v ? ptr->v : end;
		Insert(&pq, ptr);
	}
	for (i = pq.count; i > 0; i--)
	{
			firstout = ExtractMin(&pq);
			end = end < firstout->v ? firstout->v : end;
			free(firstout);
	}
	printf("%d", end);
	free(pq.heap);
	return 0;
}

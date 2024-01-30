#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Operations {
	ENQ, DEQ, EMPTY
};

int mapping(char *s)
{
	if (strcmp(s, "ENQ") == 0)
		return 0;
	if (strcmp(s, "DEQ") == 0)
		return 1;
	if (strcmp(s, "EMPTY") == 0)
		return 2;
	return -1;
}

struct Queue {
	int *data;
	int cap, count, head, tail;
};

struct Queue InitQueue()
{
	struct Queue q;
	q.data = (int*)malloc(4 * sizeof(int));
	q.cap = 4;
	q.count = q.head = q.tail = 0;
	return q; 
}

int QueueEmpty(struct Queue *q)
{
	return (q->count == 0);
}

void Enqueue(struct Queue *q, int x)
{
	if (q->count == q->cap) {
		int *helper = (int*)malloc(2 * q->cap * sizeof(int));
		int helperIndex = 0, i;
		for (i = q->head; i < q->cap; i++) {
			helper[helperIndex] = q->data[i];
			helperIndex++;
		}
		for (i = 0; i < q->tail; i++) {
			helper[helperIndex] = q->data[i];
			helperIndex++;
		}
		free(q->data);
		q->data = helper;
		q->cap = q->cap * 2;
		q-> head = 0;
		q-> tail = helperIndex;
	}
	q->data[q->tail] = x;
	q->tail = q->tail + 1;
	if (q->tail == q->cap)
		q->tail = 0;
	q->count = q->count + 1;
	return;
}

int Dequeue(struct Queue *q)
{
	int x = q->data[q->head];
	q->head = q->head + 1;
	if (q->head == q->cap)
		q->head = 0;
	q->count = q->count - 1;
	return x;
}

int main(int argc, char **argv)
{
	char operation[6];
	struct Queue q;
	q = InitQueue();
	int x, i, head;
	do {
		scanf("%s", operation);
		switch (mapping(operation)) {
			case ENQ: 
				scanf("%d\n", &x);
				Enqueue(&q, x);
				break;
			case DEQ:
				head = Dequeue(&q);
				printf("%d\n", head);
				break;
			case EMPTY:
				if (! QueueEmpty(&q))
					printf("false\n");
				else
					printf("true\n");
				break;
		}
	} while (strcmp(operation, "END") != 0);
	free(q.data);
	return 0;
}

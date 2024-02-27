#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Operations { ENQ, DEQ, MAX, EMPTY };

int mapping(char *operation)
{
	if (strcmp(operation, "ENQ") == 0)
		return 0;
	if (strcmp(operation, "DEQ") == 0)
		return 1;
	if (strcmp(operation, "MAX") == 0)
		return 2;
	if (strcmp(operation, "EMPTY") == 0)
		return 3;
	return -1;
}

struct DoubleStack {
	int *data;
	int *max;
	int cap, count, top1, top2;
};

struct Queue {
	int *data;
	int *max;
	int cap, count, head, tail;
};

union QueueOnStack {
	struct DoubleStack s;
	struct Queue q;
};

struct DoubleStack InitDoubleStack(int n)
{
	struct DoubleStack s;
	s.data = (int*)malloc(n * sizeof(int));
	s.max = (int*)malloc(n * sizeof(int));
	s.cap = n;
	s.count = 0;
	s.top1 = 0;
	s.top2 = n - 1;
	return s;
}

int StackEmpty1(struct DoubleStack *s)
{
	return s->top1 == 0;
}

int StackEmpty2(struct DoubleStack *s)
{
	return s->top2 == s->cap - 1;
}

void Push1(struct DoubleStack *s, int x)
{
	if (s->top2 < s->top1) {
		/* ResizeStack(s); */
	}
	s->data[s->top1] = x;
	if (s->top1 == 0)
		s->max[s->top1] = x;
	else
		s->max[s->top1] = x > s->max[s->top1 - 1] ? x : s->max[s->top1 - 1];
	s->top1 = s->top1 + 1;
	s->count = s->count + 1;
	return;
}

void Push2(struct DoubleStack *s, int x)
{
	if (s->top2 < s->top1) {
		/* ResizeStack(s); */
	}
	s->data[s->top2] = x;
	if (s->top2 == s->cap - 1)
		s->max[s->top2] = x;
	else
		s->max[s->top2] = x > s->max[s->top2 + 1] ? x : s->max[s->top2 + 1];
	s->top2 = s->top2 - 1;
	s->count = s->count + 1;
	return;
}

int Pop1(struct DoubleStack *s)
{
	s->top1 = s->top1 - 1;
	return s->data[s->top1];
}

int Pop2(struct DoubleStack *s)
{
	s->top2 = s->top2 + 1;
	return s->data[s->top2];
}

int Maximum1(struct DoubleStack *s)
{
	if (s->top1 == 0)
		return -2000000001;
	return s->max[s->top1 - 1];
}

int Maximum2(struct DoubleStack *s)
{
	if (s->top2 == s->cap - 1)
		return -2000000001;
	return s->max[s->top2 + 1];
}

int Maximum(union QueueOnStack *qos)
{
	int max1 = Maximum1(&qos->s);
	int max2 = Maximum2(&qos->s);
	return max1 > max2 ? max1 : max2;
}

union QueueOnStack InitQueueOnStack(int n)
{
	union QueueOnStack qos;
	qos.s = InitDoubleStack(n);
	return qos;
}

int QueueEmpty(union QueueOnStack *qos)
{
	return (StackEmpty1(&qos->s) && StackEmpty2(&qos->s));
}

void Enqueue(union QueueOnStack *qos, int x)
{ Push1(&qos->s, x); return;
}

int Dequeue(union QueueOnStack *qos)
{
	if (StackEmpty2(&qos->s))
		while (! StackEmpty1(&qos->s))
			Push2(&qos->s, Pop1(&qos->s));
	qos->s.count = qos->s.count - 1;
	return Pop2(&qos->s);
}

int main(int argc, char **argv)
{
	union QueueOnStack qos = InitQueueOnStack(1000000);
	char operation[6];
	int x;
	do {
		scanf("%s", operation);
		switch (mapping(operation)) {
			case ENQ:
				scanf("%d", &x);
				Enqueue(&qos, x);
				break;
			case DEQ:
				printf("%d\n", Dequeue(&qos));
				break;
			case MAX:
				printf("%d\n", Maximum(&qos));
				break;
			case EMPTY:
				if (QueueEmpty(&qos))
					printf("true\n");
				else
					printf("false\n");
				break;
		}

	} while (strcmp(operation, "END") != 0);
	free(qos.s.data);
	free(qos.s.max);
	return 0;
}

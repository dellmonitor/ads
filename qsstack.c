#include <stdio.h>
#include <stdlib.h>

struct Task {
	int low, high;
};

struct Stack {
	struct Task *data;
	int cap;
	int top;
};

struct Stack initStack(int n)
{
	struct Stack s;
	s.data = (struct Task*)malloc(n * sizeof(struct Task));
	s.cap = n;
	s.top = 0;
	return s;
}

int stackEmpty(struct Stack *s)
{
	return (s->top == 0);
}

void push(struct Stack *s, struct Task x)
{
	if (s->top == s->cap) {
		s->data = (struct Task*)realloc(s->data, (s->cap + 1) * sizeof(struct Task));
		s->cap = s->cap + 1;
	}
	s->data[s->top] = x;
	s->top = s->top + 1;
	return;
}

struct Task pop(struct Stack *s)
{
	s->top = s->top - 1;
	return s->data[s->top];
}

void swap(int a, int b, int *base)
{
	int store = base[a];
	base[a] = base[b];
	base[b] = store;
	return;
}

int partion(int low, int high, int *base)
{
	int i = low, j = low;
	while (j < high) {
		if (base[j] < base[high]) {
			swap(i, j, base);
			i = i + 1;
		}
		j = j + 1;
	}
	swap(i, high, base);
	return i;
}

void quickSort(int nel, int *base)
{
	struct Stack st = initStack(nel * 20);
	struct Task newTask = { 0, nel - 1 }, leftTask, rightTask;
	int q;
	push(&st, newTask);
	while (!stackEmpty(&st)) {
		newTask = pop(&st);
		if (newTask.low < newTask.high) {
			q = partion(newTask.low, newTask.high, base);
			leftTask.low = newTask.low; 
			leftTask.high = q - 1;
			rightTask.low = q + 1;
			rightTask.high = newTask.high;
			push(&st, rightTask);
			push(&st, leftTask);
		}
	}
	free(st.data);
	return;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	int *array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	quickSort(n, array);
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	free(array);
	return 0;
}

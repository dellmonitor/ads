#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	int *data;
	int cap;
	int top;
};

enum Operations {
	CONST, ADD, SUB, MUL, DIV, MAX, MIN, NEG, DUP, SWAP
};

int mapping(char *s)
{
	if (strcmp(s, "CONST") == 0)
		return 0;
	if (strcmp(s, "ADD") == 0)
		return 1;
	if (strcmp(s, "SUB") == 0)
		return 2;
	if (strcmp(s, "MUL") == 0)
		return 3;
	if (strcmp(s, "DIV") == 0)
		return 4;
	if (strcmp(s, "MAX") == 0)
		return 5;
	if (strcmp(s, "MIN") == 0)
		return 6;
	if (strcmp(s, "NEG") == 0)
		return 7;
	if (strcmp(s, "DUP") == 0)
		return 8;
	if (strcmp(s, "SWAP") == 0)
		return 9;
	return -1;
}

struct Stack initStack(int n)
{
	struct Stack s;
	s.data = (int*)malloc(n * sizeof(int));
	s.cap = n;
	s.top = 0;
	return s;
}

int stackEmpty(struct Stack *s)
{
	return (s->top == 0);
}

void push(struct Stack *s, int x)
{
	if (s->top == s->cap) {
		s->data = (int*)realloc(s->data, (s->cap + 1) * sizeof(int));
		s->cap = s->cap + 1;
	}
	s->data[s->top] = x;
	s->top = s->top + 1;
	return;
}

int pop(struct Stack *s)
{
	s->top = s->top - 1;
	return s->data[s->top];
}

int main(int argc, char **argv)
{
	char operation[6];
	struct Stack st;
	st = initStack(100);
	int x, a, b, i;
	do {
		scanf("%s", operation);
		switch (mapping(operation)) {
			case CONST: 
				scanf("%d", &x);
				push(&st, x);
				break;
			case ADD:
				a = pop(&st);
				b = pop(&st);
				push(&st, a + b);
				break;
			case SUB:
				a = pop(&st);
				b = pop(&st);
				push(&st, a - b);
				break;
			case MUL:
				a = pop(&st);
				b = pop(&st);
				push(&st, a * b);
				break;
			case DIV:
				a = pop(&st);
				b = pop(&st);
				push(&st, a / b);
				break;
			case MAX:
				a = pop(&st);
				b = pop(&st);
				push(&st, a > b ? a : b);
				break;
			case MIN:
				a = pop(&st);
				b = pop(&st);
				push(&st, a < b ? a : b);
				break;
			case NEG:
				a = pop(&st);
				push(&st, -a);
				break;
			case DUP:
				a = pop(&st);
				push(&st, a);
				push(&st, a);
				break;
			case SWAP:
				a = pop(&st);
				b = pop(&st);
				push(&st, a);
				push(&st, b);
				break;
		}
	} while (strcmp(operation, "END") != 0);
	printf("%d", pop(&st));
	free(st.data);
	return 0;
}

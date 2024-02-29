#include <stdio.h>
#include <stdlib.h>

struct Elem 
{
    struct Elem *prev, *next;
    int v;
};

struct Elem InitDoubleLinkedList()
{
	struct Elem l;
	l.prev = &l;
	l.next = &l;
	return l;
}

int ListEmpty(struct Elem *l)
{
	return l->next == l;
}

int ListLength(struct Elem *l)
{
	int len = 0;
	struct Elem *x = l;
	while (x->next != l)
	{
		len++;
		x = x->next;
	}
	return len;
}

struct Elem *ListSearch(struct Elem *l, int v)
{
	struct Elem *x = l->next;
	while (x->v != v)
	{
		x = x->next;
	}
	return x;
}

void InsertAfter(struct Elem *x, struct Elem *y)
{
	struct Elem *z = x->next;
	x->next = y;
	y->prev = x;
	y->next = z;
	z->prev = y;
	return;
}

int main(int agrc, char **argv)
{
	struct Elem l = InitDoubleLinkedList();
	struct Elem x = InitDoubleLinkedList();
	x.v = 9;
	InsertAfter(&l, &x);
	printf("%d %d\n", ListEmpty(&l), ListLength(&l));
	return 0;
}

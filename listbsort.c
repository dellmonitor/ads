#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

struct Elem
{
    struct Elem *next;
    char *word;
};

void InsertAfter(struct Elem *x, struct Elem *y)
{
	struct Elem *z = x->next;
	x->next = y;
	y->next = z;
	return;
}

int compare(struct Elem *x, struct Elem *y)
{
	return (strlen(x->word) - strlen(y->word));
}

struct Elem *bsort(struct Elem *list)
{
	struct Elem *t = NULL, *bound, *x, *y, *z;
	if (list == NULL || list->next == NULL)
	{
		return list;
	}
	while (t != list)
	{
		bound = t;
		t = list;
		x = list;
		y = x->next;
		z = y->next;
		while (z != bound)
		{
			if (compare(y, z) > 0)
			{
				x->next = z;
				y->next = z->next;
				z->next = y;
				t = y;
				x = x->next;
				z = y->next;
			}
			else
			{
				x = x->next;
				y = y->next;
				z = z->next;
			}
		}
	}
	y = list;
	while ((y->next != NULL) && (compare(list, y->next) > 0))
	{
		y = y->next;
	}
	if (y == list)
	{
		return list;
	}
	x = list->next;
	InsertAfter(y, list);
	return x;
}

int main(int argc, char **argv)
{
	char *sentence = (char*)malloc(1001 * sizeof(char));
	char *buffer = (char*)malloc(1001 * sizeof(char));
	char *store;
	fgets(sentence, 1000, stdin);
	struct Elem *list = (struct Elem*)malloc(sizeof(struct Elem)), *start, *next;
	start = list;
	list->word = "fistword";
	list->next = NULL;
	int i, j, state = OUT;
	for (i = 0; sentence[i] != 0; i++)
	{
		if (sentence[i] == ' ' || sentence[i] == '\n')
		{
			if (state == IN)
			{
				struct Elem *e = (struct Elem*)malloc(sizeof(struct Elem));
				buffer[j] = 0;
				store = (char*)malloc((j + 1) * sizeof(char));
				e->word = store;
				strncpy(store, buffer, j + 1);
				InsertAfter(list, e);
				list = list->next;
			}
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			j = 0;
			buffer[j] = sentence[i];
			j++;
		}
		else
		{
			buffer[j] = sentence[i];
			j++;
		}
	}
	list = bsort(start->next);
	while (list != NULL)
	{
		puts(list->word);
		next = list->next;
		free(list->word);
		free(list);
		list = next;
	}
	free(sentence);
	free(buffer);
	free(start);
	return 0;
}

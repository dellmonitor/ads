#include "elem.h"
#include <stdio.h>

struct Elem *searchlist(struct Elem *list, int k)
{	
	if ((!list) || ((list->tag == 0) && (list->value.i == k)))
		return list;
	searchlist(list->tail, k);
}

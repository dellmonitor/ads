#include <stdio.h>
int maxarray(void *base, size_t nel, size_t width,
		int(*compare)(void *a, void *b))
{
	size_t current_element_address = (size_t) base, max_element_address = (size_t) base, max_element_index = 0;
	for (size_t i = 1; i < nel; i++) {
		current_element_address = current_element_address + width;
		if (compare((void *)current_element_address, (void *)max_element_address) > 0) {
			max_element_address = current_element_address;
			max_element_index = i;
		}
	}
	return max_element_index;
}

#define FOUND 0x80000000
#include <stdio.h>

int main (int argc, char **argv)
{
	int i, j;
	long array_a[8], array_b[8];
	for (i = 0; i < 8; i++)
		scanf("%ld", &array_a[i]);
	for (i = 0; i < 8; i++)
		scanf("%ld", &array_b[i]);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (array_a[i] == array_b[j]) {
				array_b[j] = FOUND;
				break;
			}
		}
		if (j == 8) {
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}

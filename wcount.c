#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int wcount(char *s)
{
	int counter, i, state = OUT;
	for (i = counter = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ' || s[i] == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			counter++;
		}
	}
	return counter;
}

int main(int argc, char **argv)
{
	char *s = (char*)malloc(1001 * sizeof(char));
	fgets(s, 1000, stdin);
	printf("%d", wcount(s));
	free(s);
	return 0;
}

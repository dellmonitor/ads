#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charKey(char c) {
	return c - 97;
}

char *distributionSort(int (*key)(char c), int card, char *string, int nel)
{
	int *count = (int*)calloc(card, sizeof(int));
	int j = 0, k, i;
	while (j < nel) {
		k = key(string[j]);
		count[k] = count[k] + 1;
		j = j + 1;
	}
	i = 1;
	while (i < card) {
		count[i] = count[i] + count[i - 1];
		i = i + 1;
	}
	char *d = (char*)malloc((nel + 1) * sizeof(char));
	j = nel - 1;
	while (j >= 0) {
		k = key(string[j]);
		i = count[k] - 1;
		count[k] = i;
		d[i] = string[j];
		j = j - 1;
	}
	d[nel] = '\0';
	free(count);
	return d;
}

int main(int argc, char **argv)
{
	char *s;
	scanf("%ms", &s);
	/* char *s = (char*)malloc(sizeof(char)); */
	/* int i = 1, c; */
	/* while ((c = getchar()) != '\n') { */
	/* 	s[i - 1] = c; */
	/* 	i = i + 1; */
	/* 	s = (char*)realloc(s, i); */
	/* } */
	/* s[i - 1] = '\0'; */
	char *d;
	d = distributionSort(charKey, 26, s, strlen(s));
	printf("%s", d);
	free(s);
	free(d);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int nel)
{
	size_t string_length, concatenation_length = 0;
	int i, j, index = 0;
	for (i = 0; i < nel; i++) {
		string_length = strlen(s[i]);
		concatenation_length = concatenation_length + string_length;
	}
	char *concatenation = (char*)malloc((concatenation_length + 1) * sizeof(char));
	for (i = 0; i < nel; i++) {
		j = 0;
		while (s[i][j] != '\0') {
			concatenation[index] = s[i][j];
			j = j + 1;
			index = index + 1;
		}
	}
	concatenation[concatenation_length] = '\0';
	return concatenation;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	char **string = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
		string[i] = (char*)malloc(1001 * sizeof(char));
	for (i = 0; i < n; i++)
		scanf("%s", string[i]);
	char *concatenation = concat(string, n);
	printf("%s", concatenation);
	for (i = 0; i < n; i++)
		free(string[i]);
	free(string);
	free(concatenation);
	return 0;
}

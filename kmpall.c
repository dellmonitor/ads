#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *prefix(char *s)
{
	int s_length = strlen(s);
	int *p = (int*)malloc(s_length * sizeof(int));
	p[0] = 0;
	int t = 0, i = 1;
	while (i < s_length) {
		while ((t > 0) && s[t] != s[i])
			t = p[t - 1];
		if (s[t] == s[i])
			t = t + 1;
		p[i] = t;
		i = i + 1;
	}
	return p;
}

int KMPSubst(char *s, char *t)
{
	int q = 0, k = 0, t_length = strlen(t), s_length = strlen(s);
	int *p = prefix(s);
	while (k < t_length) {
		while ((q > 0) && (s[q] != t[k]))
			q = p[q - 1];
		if (s[q] == t[k])
			q = q + 1;
		if (q == s_length) {
			k = k - s_length + 1;
			free(p);
			return k;
		}
		k = k + 1;
	}
	free(p);
	return -1;
}

int main(int argc, char **argv)
{
	char *s = argv[1], *t = argv[2];
	int k = KMPSubst(s, t), count = 0;
	while (k != -1) {
		printf("%d ", k + count);
		if (k == 0) {
			t = t + 1;
			count = count + 1;
		}
		else {
			t = t + k + 1;
			count = count + k + 1;
		}
		k = KMPSubst(s, t);
	}
	return 0;
}

int strdiff(char *a, char *b)
{
	int i, index = 0;
	for (i = 0; a[i] != '\0' && b[i] != '\0' && a[i] == b[i]; i++)
		index = index + 8;
	if (a[i] == '\0' && b[i] == '\0')
		return -1;
	int xor = a[i] ^ b[i];
	while (!(xor % 2)) {
		index++;
		xor = xor >> 1;
	}
	return index;
}

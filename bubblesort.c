void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void(*swap)(unsigned long i, unsigned long j))
{
	unsigned long t = nel - 1, s = -1, bound, i, j;
	if (nel == 0)
		return;
	while (t != s + 1) {
		bound = t;
		t = 0;
		i = s + 1;
		while (i < bound) {
			if (compare(i + 1, i) == -1) {
				swap(i + 1, i);
				t = i;
			}
			i = i + 1;
		}
		j = bound;
		while (j > s) {
			if (compare(j, j - 1) == -1) {
				swap(j, j - 1);
				s = i;
			}
			j = j - 1;
		}
	}
	return;
}
